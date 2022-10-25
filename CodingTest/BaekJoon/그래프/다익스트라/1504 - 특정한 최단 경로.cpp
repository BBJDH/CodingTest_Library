/*
1504 - 특정한 최단 경로

v1과 v2를 반드시 거쳐야 한다
헌제 이 두 점을 거치는 경로가 어디가 더 빠를지 비교해주어야 한다

1에서 다익스트라를 시행하면,
V1 V2로 가는 경로의 길이를 저장해두고,

V1에서 다익스트라로
V1-V2 거리와 V1-N의 거리를 저장해둔다

마지막으로 V2에서 다익스트라로 V2-N의 거리를 저장해둔다(V1-V2는 이전에 구했다)

이 두 경로의 합산 (V1-V2 -N, V2-V1 -N)을 구해 비교하여 작은 값을 출력한다.

하지만 여기서 합한값이 상한값을 넘는다면, -1을 출력한다.

*/


#include<iostream>
#include<vector>
#include<queue>
#include<assert.h>
#define INF 2500000
using namespace std;

struct _int2
{
	int Pos;
	int Weight;
};

bool operator<(_int2 const& First, _int2 const& Second)
{
	return First.Weight < Second.Weight;
}
bool operator>(_int2 const& First, _int2 const& Second)
{
	return First.Weight > Second.Weight;
}
priority_queue<_int2, vector<_int2>, greater<_int2>> Dijkstra_Queue{};
vector<vector<_int2>>Edges{};
vector<int> Distance{};
int V1 = 0, V2 = 0;
int N = 0, E = 0;


void SetDistanceMax()
{
	Distance = vector<int>();
	Distance.resize(N + 1);
	for (int i = 0; i < Distance.size(); i++)
	{
		Distance[i] = INF;
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

void Dijkstra(_int2 const& Start)
{
	Dijkstra_Queue.push(Start);
	SetDistanceMax();
	Distance[Start.Pos] = 0;
	while (!Dijkstra_Queue.empty())
	{
		_int2 const CurrentNode = Dijkstra_Queue.top();
		Dijkstra_Queue.pop();
		RoundEdges(CurrentNode);
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> N >> E;
	Edges.resize(N + 1);
	while (E--)
	{
		int StartPos = 0, DestPos = 0, Weight = 0;
		cin >> StartPos >> DestPos >> Weight;
		Edges[StartPos].push_back({ DestPos ,Weight });
		Edges[DestPos].push_back({ StartPos ,Weight });
	}

	int V1 = 0, V2 = 0;
	cin >> V1 >> V2;

	int Path1 = 0;
	int Path2 = 0;

	Dijkstra({ 1,0 });
	int Distance_V1 = Distance[V1];
	int Distance_V2 = Distance[V2];

	Dijkstra({ V1,0 });
	int Distance_V1_V2 = Distance[V2];
	int Distance_V1_N = Distance[N];


	Dijkstra({ V2,0 });
	int Distance_V2_N = Distance[N];
	Path1 = Distance_V1 + Distance_V1_V2 + Distance_V2_N;
	Path2 = Distance_V2 + Distance_V1_V2 + Distance_V1_N;
	int Result = min(Path1, Path2);


	if (Result >= INF)
	{
		cout << -1;
		return 0;
	}
	cout << Result;

	return 0;
}