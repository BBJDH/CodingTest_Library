/*
1865 - ��Ȧ

�������� �˰���

���� 1 ���� N���� ���������� �ԷµǾ� �����Ƿ�

N������ �Ÿ� ���̺��� �ۼ�, (���� ��밡���� �ִ밪���� ���)
���� ���������κ��� Edge���� �湮�Ͽ� ª�� �Ÿ��� ������ �ش�. Count++;

���⼭ Ȯ���� ���� �ִ� 1-2 100 ���ΰ� �����ϰ�
1-2 101 ��Ȧ�� �����Ѵٸ�,
2 ���� 1�� �̵�(100) 1���� 2�� ��Ȧ(-101)�� -1 ����ġ�� ����ؼ� �ش��δ� �湮ó���� �����Ƿ�(���� �������� �Ÿ��� ������� ���ŵȴ�)
�Ÿ����̺� Distance[2] = -101, -102 ... �� ������ ���ŵǰ� �ȴ�
�̸� ����  �� ��忡 �̵� Count�� �ɸ� �ð��� �ο��Ѵ�.
�� ��� ���� ù ��ߺ��� �������� �湮�ϴ� �ִ� ���� N-1 �̹Ƿ�
�湮Ƚ���� N�� �ȴٸ� ���� ��ȯ�� �߻����� �����ϰ� Ż���Ѵ�.(YES�� ����)

���ܻ����� �����Ѵ�
����ΰ� ������ �����ϴ� ��츦 ����Ͽ� ��� ������ ���� ������ �������� �Ѵ�.
�ϳ��� ���� ��ȯ�� �߻��Ѵٸ�(YES)
������ �� �������Դٸ� (NO)

*/


#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct _int2
{
	int Pos;
	int Time;
};

struct Node
{
	_int2 Path;
	int Count;
};

#define INF 10001

queue<Node> BF_Queue{};
vector<vector<_int2>> Edges{};
vector<int> Distance(501, INF);
int TestCast = 0;
int N = 0;

void Push(Node const& PushNode)
{
	if (PushNode.Path.Time < Distance[PushNode.Path.Pos])
	{
		BF_Queue.push(PushNode);
		Distance[PushNode.Path.Pos] = PushNode.Path.Time;
	}
}

void CheckEdges(Node const& CurrentNode)
{
	for (int i = 0; i < Edges[CurrentNode.Path.Pos].size(); i++)
	{
		Node const NextNode =
		{
			{
				Edges[CurrentNode.Path.Pos][i].Pos,
				CurrentNode.Path.Time + Edges[CurrentNode.Path.Pos][i].Time
			},
			CurrentNode.Count + 1
		};
		Push(NextNode);
	}
}


bool BellmanFord(Node const& StartNode)
{
	CheckEdges(StartNode);
	while (!BF_Queue.empty())
	{
		Node const CurrentNode = BF_Queue.front();
		BF_Queue.pop();
		if (CurrentNode.Count == N)
		{
			return true;
		}
		CheckEdges(CurrentNode);
	}
	return false;
}
void CheckAllVertex()
{
	for (int i = 1; i <= N; i++)
	{
		Distance[i] = 0;
		if (BellmanFord({ { i, 0 }, 0 }))
		{
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> TestCast;
	while (TestCast--)
	{
		int M = 0, W = 0;
		cin >> N >> M >> W;
		BF_Queue = queue<Node>();
		Edges.clear();
		Edges.resize(N + 1);
		fill_n(Distance.begin(), 501, INF);
		while (M--)
		{
			int S = 0, E = 0, T = 0;
			cin >> S >> E >> T;
			Edges[S].push_back({ E,T });
			Edges[E].push_back({ S,T });
		}
		while (W--)
		{
			int S = 0, E = 0, T = 0;
			cin >> S >> E >> T;
			Edges[S].push_back({ E, -T });
		}
		CheckAllVertex();
	}

	return 0;
}
