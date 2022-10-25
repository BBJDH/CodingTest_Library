/*
11779 - 최소비용 구하기 2

다익스트라 문제이다
추가로 최단 거리의 경로를 출력해야 한다.
따라서 거리와 함께 경로 테이블을 갱신해주어야 한다

다익스트라가 끝난 후 최단거리를 출력하고,
해당목적지부터 갱신된 경로를 역추적(스택 삽입)하여 출력해준다.
*/

#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#define INF 2000000000

using namespace std;

struct _int2
{
	int Pos;
	int Distance;
};

bool operator>(_int2 const& Left, _int2 const& Right)
{
	return Left.Distance > Right.Distance;
}
bool operator<(_int2 const& Left, _int2 const& Right)
{
	return Left.Distance < Right.Distance;
}

priority_queue<_int2, vector<_int2>, greater<_int2>> Dijkstra_Queue{};
int Distance[1001]{};
int Path[1001]{};
vector<vector<_int2>>Edges{};
int N = 0, M = 0;

void RoundEdges(_int2 const& Current)
{
	for (auto const& Elem : Edges[Current.Pos])
	{
		_int2 NextNode{};
		NextNode.Distance = Current.Distance + Elem.Distance;
		NextNode.Pos = Elem.Pos;
		if (NextNode.Distance < Distance[Elem.Pos])
		{
			//갱신
			Dijkstra_Queue.push(NextNode);
			Distance[Elem.Pos] = NextNode.Distance;
			Path[NextNode.Pos] = Current.Pos;
		}
	}
}

void Dijkstra(_int2 const& Start)
{
	Dijkstra_Queue.push(Start);
	Distance[Start.Pos] = 0;
	while (!Dijkstra_Queue.empty())
	{

		_int2 const Current = Dijkstra_Queue.top();
		Dijkstra_Queue.pop();

		if (Current.Distance > Distance[Current.Pos])
			continue;
		RoundEdges(Current);
	}
}
void ClearDistance()
{
	for (int i = 0; i <= N; i++)
	{
		Distance[i] = INF;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	Edges.resize(N + 1);
	ClearDistance();
	while (M--)
	{
		int Start = 0, End = 0, Weight = 0;
		cin >> Start >> End >> Weight;
		Edges[Start].push_back({ End,Weight });
	}
	int Start = 0; int Dest = 0;
	cin >> Start >> Dest;
	Dijkstra({ Start,0 });

	stack<int> Print{};
	int NextCity = Dest;
	while (NextCity)
	{
		Print.push(NextCity);
		NextCity = Path[NextCity];
	}
	cout << Distance[Dest] << "\n" << Print.size() << "\n";
	while (!Print.empty())
	{
		cout << Print.top() << " ";
		Print.pop();
	}

	return 0;
}