/*
 *16234 - �α� �̵�
 *
 *BFS�� ���� Ǯ����.
 *
 *�� �������κ��� ������ �� ĭ���� Ž���� �õ��Ѵ�.
 *
 *������ �־��� �α����� ���ǿ� �����Ѵٸ� �ش� ������ ť�� ����
 *
 *ť���� ���������� �������� �α� ���� ���ϰ�
 *�������� ������ŭ ������ �����α��� �ٽ� �����Ѵ�.
 *
 *������ ť���� �������� �������� �ٽ� ������ ���� ����α���ŭ �ٽ� �������־�� �ϹǷ�
 *
 *���ο� ť�� �־� ������, BFS�� ����ȴٸ� ������ �����Ѵ�.
 *���� Ž������ �ٲ� �α��� ���� BFS���� ĭ�� ���յ��� �ʵ��� �湮������ ���־�� �Ѵ�.
 *
 *�湮 �ʱ�ȭ�� �Ϸ������ �ʱ�ȭ �Ѵ�.
 *
 *��� BFS�� ���������� �� �̻� ������ ���� ���ٸ� ����, �ش� �ϼ��� ��ȯ�Ѵ�.
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