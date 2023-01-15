
/*
 *B번 - 도넛 행성
 *
 *단순 그래프로 탐색을 진행하되,
 *문제의 요구사항에 따라 맵을 넘어가는 경우 0으로 돌아오고
 *음수가 되는 경우 Size-1이 되는 경우를 처리해준다.
 *
 *빈 공간을 입력받을때 해당 좌료를 저장해 두었다가
 *BFS 탐색을 진행하며 해당 구역이 새로운 구역이라면 카운트하여 출력한다.
 *
 */



#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

queue<_int2> BFS_Queue{};
vector<_int2> EmptyPlace{};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,-1}, {0,1} };
int Map[1000][1000]{};
bool Visit[1000][1000]{};
int SizeY = 0, SizeX = 0;

bool Push(_int2 const& Next)
{
	if (Visit[Next.Y][Next.X] == false)
	{
		Visit[Next.Y][Next.X] = true;
		BFS_Queue.push(Next);
		return true;
	}
	return false;
}

void RoundEdges(_int2 const& Current)
{
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		//0이하로 내려가는경우
		Next.X = Current.X + Direction[i].X;
		Next.Y = Current.Y + Direction[i].Y;
		if (Next.X == -1)
			Next.X = SizeX - 1;
		else if (Next.X == SizeX)
			Next.X = 0;

		if (Next.Y == -1)
			Next.Y = SizeY - 1;
		else if (Next.Y == SizeY)
			Next.Y = 0;
		Push(Next);

	}
}

bool BFS(_int2 const& Start)
{
	if (Push(Start) == false)
		return false;

	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		RoundEdges(Current);
	}
	return true;
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
			cin >> Visit[y][x];
			if (Visit[y][x] == 0)
			{
				EmptyPlace.push_back({ x,y });
			}
		}
	}
	int Result = 0;
	for (auto const& elem : EmptyPlace)
	{
		if (BFS(elem))
			Result++;
	}
	cout << Result;
	return 0;
}