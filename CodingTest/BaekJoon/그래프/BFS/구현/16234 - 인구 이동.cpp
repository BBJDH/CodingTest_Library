/*
 *16234 - 인구 이동
 *
 *BFS를 통해 풀었다.
 *
 *각 지점으로부터 인접한 네 칸으로 탐색을 시도한다.
 *
 *문제에 주어진 인구차이 조건에 부합한다면 해당 지점을 큐에 삽입
 *
 *큐에서 빠져나오는 지점들의 인구 합을 구하고
 *빠져나온 갯수만큼 나누어 구역인구를 다시 설정한다.
 *
 *위에서 큐에나 빠져나온 구역들은 다시 위에서 구한 평균인구만큼 다시 설정해주어야 하므로
 *
 *새로운 큐에 넣어 보존후, BFS가 종료된다면 꺼내어 설정한다.
 *이전 탐색에서 바뀐 인구와 다음 BFS시작 칸이 병합되지 않도록 방문관리를 해주어야 한다.
 *
 *방문 초기화는 하루단위로 초기화 한다.
 *
 *모든 BFS를 시행했을때 더 이상 병합할 곳이 없다면 종료, 해당 일수를 반환한다.
 *
 */


#include <iostream>
#include <queue>

using namespace std;


struct _int2
{
	int X;
	int Y;
};

queue<_int2> BFSQueue{};

int Map[50][50]{};
bool Visit[50][50]{};
_int2 Direction[4] = { {1,0},{-1,0},{0,1},{0,-1} };
int MergeMax = 0, MergeMin = 0;
int Size = 0;

void Push(_int2 const& Next)
{
	if (Visit[Next.Y][Next.X] == false)
	{
		Visit[Next.Y][Next.X] = true;
		BFSQueue.push(Next);
	}
}

void RoundEdge(_int2 const& Current)
{
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Current.X + Direction[i].X;
		Next.Y = Current.Y + Direction[i].Y;

		int const Diff = abs(Map[Current.Y][Current.X] - Map[Next.Y][Next.X]);

		if (Next.X >= 0 and Next.X < Size and Next.Y >= 0 and Next.Y < Size and Diff >= MergeMin and Diff <= MergeMax)
		{
			Push(Next);
		}
	}
}


bool BFS(_int2 const& Start)
{
	BFSQueue = queue<_int2>();

	Push(Start);

	int Count = 0;
	int Sum = 0;
	queue<_int2>VisitedNodes{};
	while (!BFSQueue.empty())
	{
		_int2 const Current = BFSQueue.front();
		BFSQueue.pop();
		Count++;
		Sum += Map[Current.Y][Current.X];
		VisitedNodes.push(Current);
		RoundEdge(Current);
	}
	while (!VisitedNodes.empty())
	{
		_int2 const Current = VisitedNodes.front();
		VisitedNodes.pop();
		Map[Current.Y][Current.X] = Sum / Count;
	}
	if (Count <= 1)
	{
		return false;
	}
	return true;
}

bool Solution()
{
	bool Result = false;

	for (int i = 0; i < Size; i++)
	{
		fill_n(Visit[i], Size, false);
	}

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			Result |= BFS({ x,y });
		}
	}
	return Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> Size >> MergeMin >> MergeMax;

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			cin >> Map[y][x];
		}
	}

	int Result = 0;
	while (true)
	{

		if (Solution() == false)
		{
			cout << Result;
			break;
		}
		Result++;
	}

	return 0;
}