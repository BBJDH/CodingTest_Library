/*
 *1103 - 게임
 *
 *50*50 2500 칸을 모두 방문해도 최대 카운트는 2500 이므로
 *INF를 3000으로 잡는다.
 *
 *그냥 DFS로 접근하여 한 루틴에서 방문한 곳을 다시 방문하게 된다면
 *무한이므로 -1를 출력토록 한다
 *
 *비용을 줄이기 위해 DP를 통해 TopDown으로 구성한다
 *
 *각 DP[Y][X]에서의 값은 해당 지점에서 움직일 수 있는 최대 카운트이다
 *
 *즉 최후의 도착지에서 마지막 도약 한번만 가능하므로 끝지점부터 1,
 *이전 지점은 2, 그 이전지점은 3 이런식으로 DP를 쌓아온다
 *DFS로 접근하여 다른 루틴에서 방문한 길을 만나면 이미 거기서 DP를 기록해 두었으므로
 *추가 호출없이 해당 DP를 받아온다
 *
 *각 방향은 네방향이므로 네방향에 대한 최대 카운트를 구해 현재 DP에 기록한다.
 *이렇게 시작점으로 거꾸로 쌓아오면
 *DP[0][0]에 최대 이동 카운트가 들어있다.
 *
 */
#include <iostream>
#include <string>
#define INF 3000

using namespace std;

struct _int2
{
	int X;
	int Y;
};

string Map[50]{};
int DP[50][50]{};
bool Visit[50][50]{};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int SizeX = 0;
int SizeY = 0;

int DFS(_int2 const& Current)
{
	int mul = Map[Current.Y][Current.X] - '0';
	int maxCount = 0;

	if (DP[Current.Y][Current.X] != 0)
		return DP[Current.Y][Current.X];

	Visit[Current.Y][Current.X] = true;
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Current.X + Direction[i].X * mul;
		Next.Y = Current.Y + Direction[i].Y * mul;

		//범위 이탈하면 현재 위치에서 이동가능한 것은 1
		if (Next.X < 0 or Next.Y < 0 or Next.X >= SizeX or Next.Y >= SizeY)
		{
			maxCount = max(maxCount, 1);
			continue;
		}

		if (Map[Next.Y][Next.X] == 'H')
		{
			maxCount = max(maxCount, 1);
			continue;
		}

		if (Visit[Next.Y][Next.X] == true)
			return DP[Current.Y][Current.X] = INF;

		maxCount = max(maxCount, DFS(Next) + 1);
	}
	Visit[Current.Y][Current.X] = false;

	return DP[Current.Y][Current.X] = maxCount;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SizeY >> SizeX;

	for (int i = 0; i < SizeY; i++)
	{
		cin >> Map[i];
	}
	DFS({ 0,0 });

	if (DP[0][0] >= INF)
	{
		cout << -1;
		return 0;
	}

	cout << DP[0][0];
	return 0;
}
