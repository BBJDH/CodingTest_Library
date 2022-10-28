/*
1238 - 파티

각 마을에서 X로 향하고 X에서 각 마을로 향하는 최단경로의 합이 필요하다
따라서 X로 향하는 방향으로 다익스트라를 해주고, 다시 반대방향으로 다익스트라를 해준다

요령은 edge를 정방향 역방향으로 따로 보관해주고, 다익스트라를 따로 돌려준다
X에서 각 마을로 향하는 방향은 그대로 X에서 다익스트라를 실행해 최단경로를 저장하고
역방향으로 돌린다음 X에서 다익스트라를 하면 각 마을에서 X로 향하는 최단경호를 구할 수 있다.
*/

#include<iostream>
#include<queue>
#include<vector>
#define INF 2000000000

using namespace std;

struct _int2
{
	int Pos;
	int Weight;
};

bool operator>(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight > Right.Weight;
}
bool operator<(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight < Right.Weight;
}

priority_queue<_int2, vector<_int2>, greater<_int2>> Dijkstra_Queue{};
vector<vector<_int2>> Edges{};
vector<vector<_int2>> Edges_Reverse{};
int Distance[1001]{};
int ReversDistance[1001]{};
int N = 0, M = 0, X = 0;

void SetDistance()
{
	for (int i = 0; i < 1001; i++)
	{
		Distance[i] = INF;
		ReversDistance[i] = INF;
	}
}
void RoundEdges(_int2 const& Current)
{
	for (auto const& Elem : Edges[Current.Pos])
	{
		_int2 Next{};
		Next.Pos = Elem.Pos;
		Next.Weight = Current.Weight + Elem.Weight;

		if (Next.Weight < Distance[Next.Pos])
		{
			Distance[Next.Pos] = Next.Weight;
			Dijkstra_Queue.push(Next);
		}
	}
}
void RoundEdges_Reverse(_int2 const& Current)
{
	for (auto const& Elem : Edges_Reverse[Current.Pos])
	{
		_int2 Next{};
		Next.Pos = Elem.Pos;
		Next.Weight = Current.Weight + Elem.Weight;

		if (Next.Weight < ReversDistance[Next.Pos])
		{
			ReversDistance[Next.Pos] = Next.Weight;
			Dijkstra_Queue.push(Next);
		}
	}
}

void Dijkstra(_int2 const& Start, bool IsReverse)
{
	Dijkstra_Queue.push(Start);
	if (IsReverse)
		ReversDistance[Start.Pos] = 0;
	else
		Distance[Start.Pos] = 0;
	while (!Dijkstra_Queue.empty())
	{
		_int2 const Current = Dijkstra_Queue.top();
		Dijkstra_Queue.pop();

		if (not IsReverse and Distance[Current.Pos] < Current.Weight) continue;
		if (IsReverse and ReversDistance[Current.Pos] < Current.Weight) continue;
		if (IsReverse)
			RoundEdges_Reverse(Current);
		else
			RoundEdges(Current);
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> X;
	Edges.resize(N + 1);
	Edges_Reverse.resize(N + 1);
	while (M--)
	{
		int Start = 0, Dest = 0, Weight = 0;
		cin >> Start >> Dest >> Weight;
		Edges[Start].push_back({ Dest,Weight });
		Edges_Reverse[Dest].push_back({ Start,Weight });
	}
	SetDistance();
	Dijkstra({ X,0 }, false);
	Dijkstra({ X,0 }, true);

	int Sum = 0;
	for (int i = 1; i <= N; i++)
	{
		Sum = max(Sum, Distance[i] + ReversDistance[i]);
	}
	cout << Sum;
	return 0;
}