/*
1865 - 웜홀

벨만포드 알고리즘

수는 1 부터 N까지 순차적으로 입력되어 있으므로

N까지의 거리 테이블을 작성, (값은 허용가능한 최대값으로 등록)
이후 시작점으로부터 Edge마다 방문하여 짧은 거리를 갱신해 준다. Count++;

여기서 확인할 점이 있다 1-2 100 도로가 존재하고
1-2 101 웜홀이 존재한다면,
2 에서 1로 이동(100) 1에서 2로 웜홀(-101)로 -1 가중치로 계속해서 해당경로는 방문처리가 없으므로(오직 기존보다 거리가 작을경우 갱신된다)
거리테이블 Distance[2] = -101, -102 ... 로 무한히 갱신되게 된다
이를 위해  각 노드에 이동 Count와 걸린 시간을 부여한다.
한 노드 기준 첫 출발부터 끝노드까지 방문하는 최대 경우는 N-1 이므로
방문횟수가 N이 된다면 음의 순환이 발생함을 감지하고 탈출한다.(YES로 연결)

예외사항이 존재한다
폐쇄경로가 여러개 존재하는 경우를 대비하여 모든 정점에 대해 엣지를 벨만포드 한다.
하나라도 음의 순환이 발생한다면(YES)
무사히 다 빠져나왔다면 (NO)

*/


#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct _int2
{
	int Pos;
	int Time;
};

struct Node
{
	_int2 Path;
	int Count;
};

#define INF 10001

queue<Node> BF_Queue{};
vector<vector<_int2>> Edges{};
vector<int> Distance(501, INF);
int TestCast = 0;
int N = 0;

void Push(Node const& PushNode)
{
	if (PushNode.Path.Time < Distance[PushNode.Path.Pos])
	{
		BF_Queue.push(PushNode);
		Distance[PushNode.Path.Pos] = PushNode.Path.Time;
	}
}

void CheckEdges(Node const& CurrentNode)
{
	for (int i = 0; i < Edges[CurrentNode.Path.Pos].size(); i++)
	{
		Node const NextNode =
		{
			{
				Edges[CurrentNode.Path.Pos][i].Pos,
				CurrentNode.Path.Time + Edges[CurrentNode.Path.Pos][i].Time
			},
			CurrentNode.Count + 1
		};
		Push(NextNode);
	}
}


bool BellmanFord(Node const& StartNode)
{
	CheckEdges(StartNode);
	while (!BF_Queue.empty())
	{
		Node const CurrentNode = BF_Queue.front();
		BF_Queue.pop();
		if (CurrentNode.Count == N)
		{
			return true;
		}
		CheckEdges(CurrentNode);
	}
	return false;
}
void CheckAllVertex()
{
	for (int i = 1; i <= N; i++)
	{
		Distance[i] = 0;
		if (BellmanFord({ { i, 0 }, 0 }))
		{
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> TestCast;
	while (TestCast--)
	{
		int M = 0, W = 0;
		cin >> N >> M >> W;
		BF_Queue = queue<Node>();
		Edges.clear();
		Edges.resize(N + 1);
		fill_n(Distance.begin(), 501, INF);
		while (M--)
		{
			int S = 0, E = 0, T = 0;
			cin >> S >> E >> T;
			Edges[S].push_back({ E,T });
			Edges[E].push_back({ S,T });
		}
		while (W--)
		{
			int S = 0, E = 0, T = 0;
			cin >> S >> E >> T;
			Edges[S].push_back({ E, -T });
		}
		CheckAllVertex();
	}

	return 0;
}
