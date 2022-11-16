/*
16991 - ���ǿ� ��ȸ 3

���� ��İ� �����ϴ�, �Ÿ� ���ϴ� �Լ��� ���� ������.
�Ҽ��� 6�ڸ��� �ݵ�� ǥ�����־�� �Ѵ� (������� ��� X)

*/

#include <iostream>
#include <math.h>


using namespace std;

#define INF 123456789

struct _int2
{
	int X;
	int Y;
};

_int2 Vertices[16]{};
double DP[16][1 << 16]{};

_int2 Start{};
int Size = 0;
int VisitAllBit = 0;

double Distance(_int2 const& Start, _int2 const& End)
{
	_int2 Vector = { End.X - Start.X, End.Y - Start.Y };

	return sqrt(Vector.X * Vector.X + Vector.Y * Vector.Y);
}

void Solution(int Current, int VisitBit)
{

	//���� �����ϸ� Ż��
	if (DP[Current][VisitBit] != 0) return;
	if (VisitBit == VisitAllBit)
	{
		//������ ��� �Է�
		DP[Current][VisitBit] = Distance(Vertices[0], Vertices[Current]);
		return;
	}

	//DP ��� ����
	double MinWeight = INF;
	for (int i = 1; i < Size; i++)
	{
		//���� ���ų� �̹� �湮���´� ����
		if (((1 << i) & VisitBit) == 0)
		{
			//���ο� �湮���� newVisitBit
			int newVisitBit = VisitBit | (1 << i);
			//ȣ������� �����ؾ��Ѵ� �츮�� ������ �İ�� ���� �� �ڿ������� �Ųٷ� DP�� ����� ���̴�.
			Solution(i, newVisitBit);
			// �ٸ� �������� �� ���� �� ������ �̸� ����Ͽ� min���� ����
			MinWeight = min(MinWeight, Distance(Vertices[Current], Vertices[i]) + DP[i][newVisitBit]);
		}
	}
	//DP ����,
	DP[Current][VisitBit] = MinWeight;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size;
	VisitAllBit = (1 << Size) - 1;

	for (int i = 0; i < Size; i++)
	{
		_int2 inputVertex{};
		cin >> inputVertex.X >> inputVertex.Y;
		Vertices[i] = inputVertex;
	}
	Start = Vertices[0];
	Solution(0, 1);
	printf("%.6f", DP[0][1]);
	return 0;
}
