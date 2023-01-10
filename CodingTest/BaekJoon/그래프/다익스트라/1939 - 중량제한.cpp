/*
 * 1939 - �߷�����
 *
 * ���ͽ�Ʈ��� Ǯ���
 *
 * �� �������� ��ǥ �������� �̵��ؾ� �Ѵ�.
 * �̵� ���� ���ͽ�Ʈ�� ���̺�(�ش� �������� ���ϴ� �ּ� �߷��� ��ϵ�)��
 * ������ ū �ٸ����� �����Ͽ� �̵��Ѵ�
 * �̷��� �̵��ؿ� �ٸ����� �ּ� �߷��� ���ͽ�Ʈ�� ���̺� ������Ʈ ���ش�.
 *
 */

#include<iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

struct _int2
{
	int Pos;
	int Weight;
};
bool operator > (_int2 const& Left, _int2 const& Right)
{
	return Left.Weight > Right.Weight;
}
bool operator < (_int2 const& Left, _int2 const& Right)
{
	return Left.Weight < Right.Weight;
}

priority_queue<_int2, vector<_int2>>Dijkstra_Queue{};
vector<vector<_int2>> Edges{};
int Dijkstra_Table[10001]{};
int N = 0;

void Push(_int2 const& Next)
{
	Dijkstra_Queue.push(Next);
}

void RoundEdges(_int2 const& Current)
{
	for (auto elem : Edges[Current.Pos])
	{
		_int2 Next{};
		Next.Pos = elem.Pos;
		Next.Weight = min(Current.Weight, elem.Weight);
		if (Next.Weight > Dijkstra_Table[Next.Pos])
		{
			Dijkstra_Table[Next.Pos] = Next.Weight;
			Push(Next);
		}
	}
}

void Dijkstra(int Start)
{
	Push({ Start,INF });

	while (!Dijkstra_Queue.empty())
	{
		_int2 const Current = Dijkstra_Queue.top();
		Dijkstra_Queue.pop();
		if (Current.Weight < Dijkstra_Table[Current.Pos]) continue;
		RoundEdges(Current);
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int egdeCount = 0;
	int start = 0, dest = 0;
	cin >> N >> egdeCount;
	Edges.resize(N + 1);
	for (int i = 0; i < egdeCount; i++)
	{
		int src = 0;
		_int2 dest{};
		cin >> src >> dest.Pos >> dest.Weight;
		Edges[src].push_back(dest);
		Edges[dest.Pos].push_back({ src ,dest.Weight });
	}
	cin >> start >> dest;
	Dijkstra(start);
	cout << Dijkstra_Table[dest];

	return 0;
}