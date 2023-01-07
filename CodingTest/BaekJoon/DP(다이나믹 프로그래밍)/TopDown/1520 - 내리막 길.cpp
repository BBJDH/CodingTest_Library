/*
 *1520 - 내리막 길
 *
 *DFS로 똑같이 목적지를 향해 찾아가면 시간초과가 발생한다.
 *
 *때문에 DFS에 DP를 이용해 목적지에 도달 했다면 1을 반환 하도록 처리하고
 *
 *다음 목적지가 이미 방문 했던 경로 였다면
 *해당 지점에는 이미 그 지점으로부터 방문가능 한 모든 경우의 수가 기록되어 있으므로
 *다음 목적지의 DP를 받아서 합산한다
 *
 *하지만 이렇게만 처리한다면 막다른길에 도달한경우에 대한 중복 방문 처리가 되지 않는다
 *문제에는 아주 공들인 막다른길이 존재해 이곳에 중복으로 빠진다면 많은 시간비용을 소모한다.
 *
 *때문에 다음과 같이 처리한다.
 *
 *최초 -1로 DP를 초기화
 *목적지 도착시 1반환
 *막다른길 도착시 0반환
 *
 *다음 도착지가 -1이 아닌DP값이라면 그값을 받아옴
 *(여기서 막다른길로 가는경로는 0이므로 더이상 탐색이 진행되지 않는다.)
 *
 *여기서부터는 다음 목적지가 DP = -1 경우 즉 방문해보지 않은 경우이다.
 *
 *이경우는 각 상하좌우에 대한 탐색을 진행한다
 *Map의 범위는 넘어가지 않는지, 내리막길이 맞는지 확인한 후
 *다음 DFS를 호출해 준다 이 결과는 해당 위치의 DP값을 갱신한 후 반환토록하고
 *현재 함수도 반환된 값들을 합산하여 현재 위치에서의 DP에 기록 후 반환 처리한다.
 *
 *이후 최초의 위치로 모든 경우의 수들이 모아지므로
 *
 *DP[0][0]을 열어보면 모든 경우의 수에 대한 결과가 기록되어 있다.
 *
 */

#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int Map[500][500]{};
int DP[500][500]{};
int SizeX = 0;
int SizeY = 0;

int DFS(_int2 const& Pos)
{
	int elem = Map[Pos.Y][Pos.X];
	if (Pos.X == SizeX - 1 and Pos.Y == SizeY - 1)
	{
		return DP[Pos.Y][Pos.X] = 1;
	}
	if (DP[Pos.Y][Pos.X] != -1)
		return DP[Pos.Y][Pos.X];

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Pos.X + Direction[i].X;
		Next.Y = Pos.Y + Direction[i].Y;
		if (Next.X >= SizeX or Next.Y >= SizeY or Next.X < 0 or Next.Y < 0)
			continue;
		if (Map[Pos.Y][Pos.X] <= Map[Next.Y][Next.X])
			continue;
		sum += DFS(Next);
	}

	return DP[Pos.Y][Pos.X] = sum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SizeY >> SizeX;


	for (int y = 0; y < SizeY; y++)
	{
		for (int x = 0; x < SizeX; x++)
		{
			cin >> Map[y][x];
			DP[y][x] = -1;
		}
	}
	DFS({ 0,0 });
	cout << DP[0][0];
	return 0;
}