/*
 * 7569 - 토마토
 *
 * 기존 토마토를 3차원으로 확장한 문제,
 *
 * Direction을 3차원으로 만들어주고
 *
 * BFS를 통해 토마토를 전파시킨다.
 *
 * 처음 입력시 토마토라면 미리 큐에 푸시 처리한다
 *
 * 마지막 반복문을 빠져나온 뒤 익지 않은 토마토가 있는지 확인한다
 *
 */

#include <iostream>
#include <queue>

using namespace std;

struct _int3
{
	int X;
	int Y;
	int Z;
};
struct Node
{
	_int3 Pos;
	int Day;
};

_int3 Direction[6] = { {1,0,0},{-1,0,0} ,{0,1,0} ,{0,-1,0} ,{0,0,1} ,{0,0,-1} };
queue<Node> BFS_Queue{};
bool Visit[100][100][100]{};
int Map[100][100][100]{};

int MaxZ = 0, MaxY = 0, MaxX = 0;

void Push(Node const & Next)
{
	if(Visit[Next.Pos.Z][Next.Pos.Y][Next.Pos.X] == false)
	{
		Visit[Next.Pos.Z][Next.Pos.Y][Next.Pos.X] = true;
		BFS_Queue.push(Next);
	}
}

void RoundEdges(Node const& Current)
{
	for(int i=0; i<6; i++)
	{
		Node Next{};
		Next.Pos.X = Current.Pos.X + Direction[i].X;
		Next.Pos.Y = Current.Pos.Y + Direction[i].Y;
		Next.Pos.Z = Current.Pos.Z + Direction[i].Z;
		Next.Day = Current.Day + 1;

		if (Next.Pos.X >= 0 and Next.Pos.X < MaxX
			and Next.Pos.Y >= 0 and Next.Pos.Y < MaxY
			and Next.Pos.Z >= 0 and Next.Pos.Z < MaxZ
			)
			Push(Next);
	}
}

void Solution()
{
	int Day = 0;
	while (!BFS_Queue.empty())
	{
		Node const Current = BFS_Queue.front();
		BFS_Queue.pop();
		Day = max(Day, Current.Day);
		RoundEdges(Current);
	}


	for (int z = 0; z < MaxZ; z++)
	{
		for (int y = 0; y < MaxY; y++)
		{
			for (int x = 0; x < MaxX; x++)
			{
				if (Visit[z][y][x] == false)
				{
					cout << -1;
					return;
				}
			}
		}
	}


	cout << Day;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> MaxX >> MaxY >> MaxZ;

	for(int z=0; z< MaxZ; z++)
	{
		for(int y=0; y< MaxY; y++)
		{
			for(int x=0; x< MaxX; x++)
			{
				cin >> Map[z][y][x];
				if (Map[z][y][x] == 1)
					Push({ {x,y,z} ,0});
				if (Map[z][y][x] == -1)
					Visit[z][y][x] = true;
			}
		}
	}
	Solution();
	return 0;
}