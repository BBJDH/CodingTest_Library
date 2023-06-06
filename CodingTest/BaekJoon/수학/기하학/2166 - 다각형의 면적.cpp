/*

2166 - �ٰ����� ����

ù ���� �������� ����,

���� ������ ������ �ĺ��� ����
�ι�° ������ �������� abs(��������)/2 �� ���س���
�������� -1 ���� ���� �� ����


��������

���� �־����� ������� �����̾� ������ ���� �ﰢ���� ���̸� ���� ��� ���� ������Ų��
���������� ���밪���� ����Ѵ�

����)
4
0 0
0 10
10 10
10 0
�� 100������

4
0 0
0 10
10 0
10 10
�� 0�� ���;� �Ѵ�

 */



#include<iostream>
#include<vector>
using  namespace  std;

struct _longlong2
{
	long long X;
	long long Y;
};

vector<_longlong2> Vertices{};

long long Cross(_longlong2 const& First, _longlong2 const& Second)
{
	//2�� ���̸� ��ȯ first.x * second.y - first.y * second.y
	return First.X * Second.Y - First.Y * Second.X;
}

long long Area = 0;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputSize = 0;
	cin >> InputSize;
	while (InputSize--)
	{
		_longlong2 InputVertex{};
		cin >> InputVertex.X >> InputVertex.Y;
		Vertices.emplace_back(InputVertex);
	}

	for (int i = 1; i < Vertices.size() - 1; i++)
	{
		_longlong2 VFirst = { Vertices[i].X - Vertices[0].X, Vertices[i].Y - Vertices[0].Y };
		_longlong2 VSecond = { Vertices[i + 1].X - Vertices[0].X, Vertices[i + 1].Y - Vertices[0].Y };
		Area += Cross(VFirst, VSecond);

	}
	//cout�� ������ ���� ��ŭ�� �����ڰ� �Ǿ���..
	printf("%.1lf", static_cast<double>(abs(Area)) / 2.0);
	return 0;
}