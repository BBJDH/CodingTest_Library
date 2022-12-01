/*
 *7576 - 토마토
 *
 * 1로 들어오는 지점을 모두 큐에 집어넣고 우선순위 탐색을 돌린다
 * 각 노드에게 익게된 일수를 기록하고 그 일수의 최대값을 업데이트한다
 * 큐를 탈출한 후 모두 익었는지 확인할 수 있도록 큐에서 빼낸 횟수 + -1의 갯수의 총합이 전체 공간수와 일치하는지 확인해 준다
 * 모두 익었다면 업데이트 했던 일수를, 익지 않았다면 -1을 출력한다.
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

struct Node
{
	_int2 Pos;
	int Day;
};

vector<_int2> Tomato_One{};
queue<Node> BFS_Queue{};
_int2 Direction[4] = { {1,0}, {0,1},{-1,0}, {0,-1} };
int Map[1000][1000]{};
int Visit[1000][1000]{};
int M = 0, N = 0;
int Count = 0;
void PUSH(Node const& Next)
{
	if (Visit[Next.Pos.Y][Next.Pos.X] == false and Map[Next.Pos.Y][Next.Pos.X] != -1)
	{
		Visit[Next.Pos.Y][Next.Pos.X] = true;
		BFS_Queue.push(Next);
	}
}

void RoundEdges(Node const& Current)
{
	for (int i = 0; i < 4; i++)
	{
		Node Next{};

		Next.Pos.X = Current.Pos.X + Direction[i].X;
		Next.Pos.Y = Current.Pos.Y + Direction[i].Y;
		Next.Day = Current.Day + 1;

		if (Next.Pos.X >= 0 and Next.Pos.X < M and Next.Pos.Y >= 0 and Next.Pos.Y < N)
		{
			PUSH(Next);
		}
	}
}

void BFS()
{
	for (int i = 0; i < Tomato_One.size(); i++)
		PUSH({ Tomato_One[i], 0 });
	int dayMax = 0;

	while (!BFS_Queue.empty())
	{
		Node const current = BFS_Queue.front();
		BFS_Queue.pop();
		dayMax = max(dayMax, current.Day);

		RoundEdges(current);
		Count++;
	}
	if (Count != N * M)
	{
		cout << -1;
		return;
	}
	cout << dayMax;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int inputNum = 0;
			cin >> inputNum;
			Map[y][x] = inputNum;
			if (inputNum == 1)
				Tomato_One.push_back({ x,y });
			else if (inputNum == -1)
				Count++;
		}
	}

	BFS();

	return 0;
}