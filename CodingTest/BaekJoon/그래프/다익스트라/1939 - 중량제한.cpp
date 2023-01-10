/*
 * 1939 - 중량제한
 *
 * 다익스트라로 풀어보자
 *
 * 한 정점에서 목표 정점까지 이동해야 한다.
 * 이동 도중 다익스트라 테이블(해당 정점으로 향하는 최소 중량이 기록됨)의
 * 값보다 큰 다리만을 선택하여 이동한다
 * 이렇게 이동해온 다리들의 최소 중량을 다익스트라 테이블에 업데이트 해준다.
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