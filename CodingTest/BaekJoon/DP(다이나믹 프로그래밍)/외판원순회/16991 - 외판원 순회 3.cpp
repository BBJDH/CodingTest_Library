/*
16991 - 외판원 순회 3

이전 방식과 동일하다, 거리 구하는 함수만 따로 만들자.
소수점 6자리를 반드시 표시해주어야 한다 (정수라면 상관 X)

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

	//값이 존재하면 탈출
	if (DP[Current][VisitBit] != 0) return;
	if (VisitBit == VisitAllBit)
	{
		//끝지점 비용 입력
		DP[Current][VisitBit] = Distance(Vertices[0], Vertices[Current]);
		return;
	}

	//DP 계산 시작
	double MinWeight = INF;
	for (int i = 1; i < Size; i++)
	{
		//길이 없거나 이미 방문상태는 제외
		if (((1 << i) & VisitBit) == 0)
		{
			//새로운 방문상태 newVisitBit
			int newVisitBit = VisitBit | (1 << i);
			//호출순서에 유의해야한다 우리는 끝까지 파고들어간 다음 맨 뒤에서부터 거꾸로 DP를 기록할 것이다.
			Solution(i, newVisitBit);
			// 다른 정점에서 더 작을 수 있으니 이를 고려하여 min으로 갱신
			MinWeight = min(MinWeight, Distance(Vertices[Current], Vertices[i]) + DP[i][newVisitBit]);
		}
	}
	//DP 갱신,
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
