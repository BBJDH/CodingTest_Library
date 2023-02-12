/*
 * 2178 - 미로 탐색
 *
 *그래프 탐색(너비우선탐색)으로 해결했다
 *
 *주어지는 Map이 int형이 아닌 문자열이며 시작점은 0,0이 아닌 1,1으로
 *
 *이것을 혼동하지 않고 탐색해야 한다.
 *
 *각 지점별 이동 가능한 탐색 방향은 최대 4방향으로 배열로 그래프를 구성했다.
 *(Edge수가 많다면 인접리스트로 구성한다.)
 *
 *무사히 BFS를 수행했다면 한번에 정답을 받게된다.
 *(별다른 예외가 없다.)
 *
 */

#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

struct Node
{
	_int2 Pos;
	int Count;
};
_int2 Direction[4] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<string> Map{};
queue<Node>BFS_Queue{};
bool Visit[101][101]{};
int SizeX = 0, SizeY = 0;

void Push(Node const& Next)
{
	if (Visit[Next.Pos.Y][Next.Pos.X] == false and Map[Next.Pos.Y - 1][Next.Pos.X - 1] == '1')
	{
		BFS_Queue.push(Next);
		Visit[Next.Pos.Y][Next.Pos.X] = true;
	}
}

bool Round_Edges(Node const& Current)
{
	for (int i = 0; i < 4; i++)
	{
		Node Next{};
		Next.Pos.X = Current.Pos.X + Direction[i].X;
		Next.Pos.Y = Current.Pos.Y + Direction[i].Y;
		Next.Count = Current.Count + 1;

		if (Next.Pos.X == SizeX and Next.Pos.Y == SizeY)
		{
			cout << Next.Count;
			return true;
		}

		if (Next.Pos.X > 0 and Next.Pos.Y > 0 and Next.Pos.X <= SizeX and Next.Pos.Y <= SizeY)
		{
			Push(Next);
		}

	}
	return false;
}

void BFS()
{
	_int2 Start{ 1,1 };
	Push({ Start ,1 });
	while (!BFS_Queue.empty())
	{
		Node const Current = BFS_Queue.front();
		BFS_Queue.pop();
		if (Round_Edges(Current) == true)
			break;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SizeY >> SizeX;
	for (int i = 0; i < SizeY; i++)
	{
		string inputStr{};
		cin >> inputStr;
		Map.push_back(inputStr);
	}
	BFS();
	return 0;
}