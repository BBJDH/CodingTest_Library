/*
 * 11389 - �ɺ� �������� 6�ܰ� ��Ģ
 *
 * �� ��� ģ���κ��� BFS, ��� ģ���� Ž���� ����� �����Ͽ� ����Ѵ�
 *
 *���� ���� ����� ����ϴ°� �ƴ϶� ���� ���� ����� ���� ����� ����ؾ� �Ѵ�.
 *
 *�� Ž���� ������ ģ���� Start �ٸ� ��� ģ���� Dest�� �Ͽ� BFS�� �ϰ� ���� ��θ� �ջ��Ѵ�.
 *
 *���� ���� ��ο��� Start�� �����Ѵ�.
 *
 *��� �ݺ����� Ż���Ѵٸ� Start�� ����Ѵ�
 *
 *�� Start���� Dest�� ���ϴ� ����� �ߺ� ���ǹǷ�, DP�� �߰��ϸ� �� ������ �� �ִ�
 *
 *������ �� 1 ���� 2�� ���� ����� DP�� ������Ʈ�ϰ�
 *
 *���� 2���� 1�ΰ��� ����� �ʿ��Ҷ��� ���� ��� �Ǿ��ִ��� (����� INF�� �ƴ���)�� üũ�Ѵ�
 *
 *����� �̹� ��� �Ǿ��ִٸ� �ش� ������� ����Ͽ� �ð��� ���� ��ų �� �ִ�.
 *
 *
 *Ȥ�� �÷��̵� ������ ����ص� �ȴ�.
 *
 *
 * ������ ����
 *
 * 1 3
 * 1 4
 * 2 3
 * 3 4
 * 4 5
 *
 * 1 - 2 �� 2���
 * 1 - 3 �� 1���
 * 1 - 4 �� 1���
 * 1 - 5 �� 2���
 *
 *
 * 1 - 2 => 2
 * 1 - 3 => 1
 * 1 - 4 => 1
 * 1 - 5 => 2
 *
 * 1�� 6
 *
 * 2 - 1 => 2
 * 2 - 3 => 1
 * 2 - 4 => 2
 * 2 - 5 => 3
 *
 * 2 �� 8
 *
 * 3 -
 *
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct _int2
{
	int Num;
	int Count;
};

bool Visit[101]{};
vector<vector<int>>Edges{};
queue<_int2>BFSQueue{  };


void Push(_int2 const& Next)
{
	if (Visit[Next.Num] == false)
	{
		Visit[Next.Num] = true;
		BFSQueue.push(Next);
	}
}

void RoundEdge(_int2 const& Current)
{
	for (int const elem : Edges[Current.Num])
	{
		_int2 Next{};
		Next.Num = elem;
		Next.Count = Current.Count + 1;
		Push(Next);
	}
}

int BFS(_int2 const& Start, int const Dest)
{
	int Result = 0;
	BFSQueue = queue<_int2>();
	for (int i = 1; i < 101; i++)
	{
		fill_n(Visit, 101, false);
	}
	Push(Start);
	while (!BFSQueue.empty())
	{
		_int2 Current = BFSQueue.front();
		BFSQueue.pop();
		if (Current.Num == Dest)
		{
			Result = Current.Count;
			break;
		}
		RoundEdge(Current);

	}
	return Result;
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int MinResult = 500000;
	int Result = 0;
	int NumOfPeople = 0, NumOfEdges = 0;
	cin >> NumOfPeople >> NumOfEdges;
	Edges.resize(NumOfPeople + 1);

	while (NumOfEdges--)
	{
		int Start = 0;
		int Dest = 0;

		cin >> Start >> Dest;
		Edges[Start].push_back(Dest);
		Edges[Dest].push_back(Start);
	}
	for (int Start = 1; Start <= NumOfPeople; Start++)
	{
		int CurrentResult = 0;
		for (int Dest = 1; Dest <= NumOfPeople; Dest++)
		{
			if (Start == Dest)
			{
				continue;
			}
			CurrentResult += BFS({ Start ,0 }, Dest);
		}
		if (MinResult > CurrentResult)
		{
			MinResult = min(MinResult, CurrentResult);
			Result = Start;
		}
	}
	cout << Result;

	return 0;
}