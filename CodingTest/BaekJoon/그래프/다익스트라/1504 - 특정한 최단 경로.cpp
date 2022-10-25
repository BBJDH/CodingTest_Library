/*
1504 - Ư���� �ִ� ���

v1�� v2�� �ݵ�� ���ľ� �Ѵ�
���� �� �� ���� ��ġ�� ��ΰ� ��� �� ������ �����־�� �Ѵ�

1���� ���ͽ�Ʈ�� �����ϸ�,
V1 V2�� ���� ����� ���̸� �����صΰ�,

V1���� ���ͽ�Ʈ���
V1-V2 �Ÿ��� V1-N�� �Ÿ��� �����صд�

���������� V2���� ���ͽ�Ʈ��� V2-N�� �Ÿ��� �����صд�(V1-V2�� ������ ���ߴ�)

�� �� ����� �ջ� (V1-V2 -N, V2-V1 -N)�� ���� ���Ͽ� ���� ���� ����Ѵ�.

������ ���⼭ ���Ѱ��� ���Ѱ��� �Ѵ´ٸ�, -1�� ����Ѵ�.

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