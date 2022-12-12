/*
 *
 * 9370 - 미확인 도착지
 *
 *다익스트라로 구현하되, 해당 단서를 지났는지를 같이 표시했다
 *다음에는 그냥 해당 단서를 지나면 0.1정도를 빼서 계산해보자(float으로 길이를 처리)
 *
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 200000000
using namespace std;

struct  Path
{
	int Distance;
	bool IsValid;
};

struct _int2
{
	int Node;
	int Distance;
};

bool operator<(_int2 const& Left, _int2 const& Right)
{
	return Left.Distance < Right.Distance;
}
bool operator>(_int2 const& Left, _int2 const& Right)
{
	return Left.Distance > Right.Distance;
}

priority_queue<_int2, vector<_int2>, greater<>> Dijkstra_Queue{};
vector<vector<_int2>> Edges{};
vector<int> candidate{};
Path Paths[2001]{};

int N = 0, M = 0, T = 0;
int Start = 0;
int LinkStart = 0;
int LinkEnd = 0;

void RoundEdges(int const Current)
{
	for (auto const& elem : Edges[Current])
	{
		int next = elem.Node;
		int distance = Paths[Current].Distance + elem.Distance;

		if (distance <= Paths[next].Distance)
		{
			//경로를 지나간 경우
			if ((Current == LinkStart and next == LinkEnd) or (Current == LinkEnd and next == LinkStart))
				Paths[next].IsValid = true;
			else
			{
				//길이가 더 작은 경우는 출발지가 단서를 포함한 길인지만 확인한다.
				if (distance != Paths[next].Distance)
				{
					Paths[next].IsValid = Paths[Current].IsValid;
				}
				else
				{
					//경로를 지나지 않았지만 길이가 같은 경우, 출발지 혹은 도착지가 단서를 가졌다면 true가 되어야 한다.
					Paths[next].IsValid |= Paths[Current].IsValid;
					continue;
				}

			}
			Paths[next].Distance = distance;
			Dijkstra_Queue.push({ next, distance });
		}
	}
}

void Dijkstra()
{
	Dijkstra_Queue.push({ Start,0 });
	Paths[Start].Distance = 0;

	while (!Dijkstra_Queue.empty())
	{
		_int2 const current = Dijkstra_Queue.top();
		Dijkstra_Queue.pop();
		if (current.Distance > Paths[current.Node].Distance)continue;
		RoundEdges(current.Node);
	}
}

void PrintResult()
{
	sort(candidate.begin(), candidate.end());
	for (auto const& elem : candidate)
	{
		if (Paths[elem].IsValid and Paths[elem].Distance != INF)
			cout << elem << " ";
	}
	cout << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int testCase = 0;

	cin >> testCase;

	while (testCase--)
	{
		while (!Dijkstra_Queue.empty()) Dijkstra_Queue.pop();
		Edges.clear();
		candidate.clear();
		Path const init = { INF,false };
		fill_n(Paths, 2001, init);

		cin >> N >> M >> T;

		Edges.resize(N + 1);

		cin >> Start >> LinkStart >> LinkEnd;

		for (int i = 0; i < M; i++)
		{
			int first = 0;
			int second = 0;
			int distance = 0;
			cin >> first >> second >> distance;

			Edges[first].push_back({ second,distance });
			Edges[second].push_back({ first , distance });
		}

		for (int i = 0; i < T; i++)
		{
			int inputCandidate = 0;
			cin >> inputCandidate;
			candidate.emplace_back(inputCandidate);
		}
		Dijkstra();
		PrintResult();
	}


	return 0;
}