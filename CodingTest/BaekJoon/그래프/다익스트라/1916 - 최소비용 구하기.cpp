/*
 *1916 - �ּҺ�� ���ϱ�
 *
 *�������� ���ͽ�Ʈ�� �����̴�
 *
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct _int2
{
	int Dest;
	int Weight;
};

vector<vector<_int2>> Edges{};
priority_queue<_int2> Dijkstra_Queue{};
int Weight[1001]{};
int TownNum = 0;

bool operator>(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight > Right.Weight;
}
bool operator<(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight < Right.Weight;
}

void RoundEdges(_int2 Current)
{
	for (auto const& elem : Edges[Current.Dest])
	{
		_int2 Next{};
		Next.Dest = elem.Dest;
		Next.Weight = Weight[Current.Dest] + elem.Weight;

		if (Next.Weight < Weight[Next.Dest])
		{
			Dijkstra_Queue.push(Next);
			Weight[Next.Dest] = Next.Weight;
		}
	}
}

void Dijkstra(_int2 const& Start)
{
	Dijkstra_Queue.push(Start);
	Weight[Start.Dest] = Start.Weight;
	while (!Dijkstra_Queue.empty())
	{
		_int2 const current = Dijkstra_Queue.top();
		Dijkstra_Queue.pop();

		//������ ť�ȿ� �߰� �Ǿ������� �ռ� �������� �������� �� ������η� ������Ʈ�Ǿ�
		//�̹� ������ �ǹ̰� ������ ���� RoundEdge�� ���� �ʰ� ���� ������
		if (current.Weight > Weight[current.Dest])continue;
		RoundEdges(current);
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int edgesNum = 0;
	int start = 0, dest = 0;
	cin >> TownNum >> edgesNum;
	Edges.resize(TownNum + 1);
	fill_n(Weight, TownNum + 1, 100000000);
	while (edgesNum--)
	{
		int inputStart = 0;
		_int2 inputEdge{};

		cin >> inputStart >> inputEdge.Dest >> inputEdge.Weight;

		Edges[inputStart].emplace_back(inputEdge);
	}
	cin >> start >> dest;
	Dijkstra({ start,0 });
	cout << Weight[dest];
	return 0;
}