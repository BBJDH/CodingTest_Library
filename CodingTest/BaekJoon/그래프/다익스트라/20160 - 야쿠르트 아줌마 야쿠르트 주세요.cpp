/*
 *20160 - ����Ʈ ���ܸ� ����Ʈ �ּ���
 *
 *����Ʈ ���ܸ��� �̵��ϴ� ������ ���� �����̴� �����ð��� vector�� ����صд�
 *�� ����Ʈ ���� ���������� ������, ���� ������ �������� �Ͽ� ���ͽ�Ʈ�� �����Ѵ�.
 *�̰͵��� �������� vector�� �����Ѵ�.
 *
 *���� �÷��̾��� ������ �������� ���ͽ�Ʈ�� �����ϰ�,
 *������ ���� ������ vector�� ���ҵ� ���� �۴ٸ� min �Լ��� ���� ���� ���� ������ �����ϰ� ����Ѵ�.
 *
 *
 *������ �� ������δ� �ӵ��� 450 ���� ���´�
 *1���� 80 ������ �ӵ��� ó�� �����ϴ�
 *
 *� ���̰� �־�����?
 *
 *
 *
 *==��� Ǯ��==
 *
 *�����غ��� �Ųٷ� �÷��̾��� ���ͽ�Ʈ�� ����� �ΰ�
 *
 *���ܸ��� �÷��̾��� �����ð����� ��ٸ� �̹� �÷��̾�� ���� �� �ִٴ� �ǹ̰� �ȴ�
 *
 *���� �÷��̾��� ���ͽ�Ʈ�� �迭�� ���� ������ �ΰ�,
 *
 *�̰��� ���ָӴϰ� �� ����Ʈ�� �̵� �� ������ ���ͽ�Ʈ�� ������ ��,
 *
 *�÷��̾��� ������ ���� �̵����� ũ�ٸ� ���ͽ�Ʈ��� �� �̻� ������ �ʿ���� �����ϸ� �ȴ�.
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

	//���� ���ܸ��� ���� ��ġ�� ���ٸ� 0
	if (PlayerPos == Path[0])
	{
		cout << PlayerPos;
		return 0;
	}
	Solution(PlayerPos);

	return 0;
}