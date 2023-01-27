/*
 *1967 - Ʈ���� ����
 *
 *====ó���� �ߴ� ����====
 *�� �ڽĳ�带 �������� ����Ž������ �����Ͽ�
 *
 *���� �հŸ��� �����Ѵ�.
 *
 *������ ó������ ��� �ڽĳ����� �����ϰ�,
 *
 *�װͿ� ���� BFS�� ���� Ž���� �����ߴ���
 *
 *�ӵ��� 1648ms�� ���Դ�...
 *
 *��� 10000���� ���� BFS�� ��� �Ͽ����� �翬����...
 *
 *� ���� ����� ������?
 *
 *====������====
 *
 *�������� ��� 10000���� ���� BFS�� �����ϰ� �־���.
 *
 *������ 1�� ��尡 �׻� root�̹Ƿ�
 *
 *1������ BFS�� �����Ͽ� ���� �� ��带 ã�´�.(�̰��� ���� BFS�� ������)
 *
 *ã���� �� ���� BFS�� �Ѵٸ� �ݵ�� ���⼭ ���� �� ���̰� �����Ѵ�.
 *(�ᱹ BFS�� 1���� �ѹ�, ���⼭ ã���� ���� �� ���� �ѹ�, �� �ι��� �ϸ� �ȴ�.)
 *
 *
 *
 *��, Ʈ���� ������ �Ǵ� �� ����
 *
 *�ݵ�� �ش� Ʈ���� ���� �� ��带 �����Ѵ�
 *
 *�ڵ� ������ �ӵ��� 1648ms ���� 4ms�� �پ���.
 *
 *
 */

#include<iostream>
#include <vector>
#include <queue>

using namespace std;
struct _int2
{
	int Node;
	int Weight;
};

bool Visit[10001]{};
vector<vector<_int2>> Edges{};
vector<int>StartNodes{};
queue<_int2>BFS_Queue{};
int MaxWeight = 0;

void Push(_int2 const& Next)
{
	if (Visit[Next.Node] == false)
	{
		Visit[Next.Node] = true;
		BFS_Queue.push(Next);
	}
}

void RoundEdges(_int2 const& Current)
{
	for (int i = 0; i < Edges[Current.Node].size(); i++)
	{
		_int2 Next{};
		Next.Node = Edges[Current.Node][i].Node;
		Next.Weight = Current.Weight + Edges[Current.Node][i].Weight;
		Push(Next);
	}
}

int BFS(int const Start)
{
	int FurthestNode = 0;
	fill_n(Visit, 10001, false);
	BFS_Queue = queue<_int2>{};
	Push({ Start ,0 });
	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		RoundEdges(Current);
		if (MaxWeight < Current.Weight)
		{
			MaxWeight = Current.Weight;
			FurthestNode = Current.Node;
		}
	}
	return FurthestNode;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N = 0;
	cin >> N;
	Edges.resize(N + 1);
	while (N--)
	{
		int Start = 0, Dest = 0, Weight = 0;
		cin >> Start >> Dest >> Weight;
		Edges[Start].push_back({ Dest,Weight });
		Edges[Dest].push_back({ Start,Weight });
		StartNodes.push_back(Dest);
	}


	int const FurthestNode = BFS(1);
	BFS(FurthestNode);

	cout << MaxWeight;

	return 0;
}