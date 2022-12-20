/*
 *20160 - 야쿠르트 아줌마 야쿠르트 주세요
 *
 *야쿠르트 아줌마가 이동하는 동선을 따라 움직이는 누적시간은 vector에 기록해둔다
 *각 포인트 마다 이전지점을 시작점, 현재 지점을 도착지로 하여 다익스트라를 시행한다.
 *이것들의 누적값을 vector에 저장한다.
 *
 *이후 플레이어의 시작점 기준으로 다익스트라를 진행하고,
 *위에서 구한 누적값 vector의 원소들 보다 작다면 min 함수를 통해 가장 작은 정점을 저장하고 출력한다.
 *
 *
 *하지만 이 방식으로는 속도가 450 가량 나온다
 *1위는 80 정도의 속도로 처리 가능하다
 *
 *어떤 차이가 있었을까?
 *
 *
 *
 *==모범 풀이==
 *
 *생각해보니 거꾸로 플레이어의 다익스트라를 계산해 두고
 *
 *아줌마가 플레이어의 도착시간보다 길다면 이미 플레이어와 만날 수 있다는 의미가 된다
 *
 *따라서 플레이어의 다익스트라 배열을 따로 저장해 두고,
 *
 *이것을 아주머니가 각 포인트로 이동 할 때마다 다익스트라를 진행할 때,
 *
 *플레이어의 값보다 누적 이동값이 크다면 다익스트라는 더 이상 수행할 필요없이 종료하면 된다.
 *
 *
 */


#include <iostream>
#include <queue>
#include <vector>
#define INF 10000000000

using namespace std;

struct _int2
{
	long long Dest;
	long long Weight;
};

bool operator>(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight > Right.Weight;
}
bool operator<(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight < Right.Weight;
}

priority_queue<_int2, vector<_int2>, greater<>> Dijkstra_Queue{};
vector<vector<_int2>> Edges{};
vector<long long> Path{};
long long Dijkstra_Weights[10001]{};
long long V = 0;

void RoundEdges(_int2 const& Current)
{
	for (auto const& elem : Edges[Current.Dest])
	{
		_int2 Next{};
		Next.Dest = elem.Dest;
		Next.Weight = Current.Weight + elem.Weight;

		if (Next.Weight < Dijkstra_Weights[Next.Dest])
		{
			Dijkstra_Weights[Next.Dest] = Next.Weight;
			Dijkstra_Queue.push(Next);
		}
	}
}

void Dijkstra(long long Start)
{


	for (int i = 0; i <= V; i++)
		fill_n(Dijkstra_Weights, V + 1, INF);

	Dijkstra_Queue = priority_queue<_int2, vector<_int2>, greater<>>{};

	Dijkstra_Weights[Start] = 0;
	Dijkstra_Queue.push({ Start ,0 });

	while (!Dijkstra_Queue.empty())
	{
		_int2 const current = Dijkstra_Queue.top();
		Dijkstra_Queue.pop();

		if (current.Weight > Dijkstra_Weights[current.Dest])
			continue;

		RoundEdges(current);
	}
}

void Solution(long long const PlayerPos)
{
	vector<long long> Path_Weight{};

	Path_Weight.resize(10);
	Path_Weight[0] = 0;
	long long sum = 0;
	long long startIndex = 0;
	for (int i = 1; i < Path.size(); i++)
	{

		long long const start = Path[startIndex];
		long long const dest = Path[i];

		Dijkstra(start);
		long long path_Weight = 0;
		if (Dijkstra_Weights[dest] >= INF)
		{
			Path_Weight[i] = INF;
			continue;
		}
		sum += Dijkstra_Weights[dest];

		Path_Weight[i] = sum;
		startIndex = i;
	}
	Dijkstra(PlayerPos);
	long long minVertex = 10001;
	for (int i = 0; i < Path_Weight.size(); i++)
	{
		long long const dest = Path[i];
		if (Path_Weight[i] < INF and Dijkstra_Weights[dest] < Path_Weight[i])
		{
			minVertex = min(minVertex, dest);
		}
	}
	if (minVertex == 10001)
		cout << "-1";
	else
		cout << minVertex;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long E = 0, PlayerPos = 0;

	cin >> V >> E;
	Edges.resize(V + 1);

	for (long long i = 0; i < E; i++)
	{
		long long start = 0;
		_int2 inputEdge{};

		cin >> start >> inputEdge.Dest >> inputEdge.Weight;
		Edges[start].emplace_back(inputEdge);
		Edges[inputEdge.Dest].push_back({ start ,inputEdge.Weight });
	}

	for (long long i = 0; i < 10; i++)
	{
		long long inputDest{};

		cin >> inputDest;
		Path.emplace_back(inputDest);
	}

	cin >> PlayerPos;

	//나와 아줌마의 시작 위치가 같다면 0
	if (PlayerPos == Path[0])
	{
		cout << PlayerPos;
		return 0;
	}
	Solution(PlayerPos);

	return 0;
}