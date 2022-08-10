
#include<iostream>
#include<vector>
#include<queue>


#define INF 30000000
using namespace std;

/*
시작점은 StartNodeNum
큐에 시작점 삽입
꺼내온 큐로부터 Edge를 방문
시작점 Weight는 0으로 설정
해당 점의 Edge에 접근하여 가중치를 비교

*/

struct _int2
{
	int NodeNum = 0;
	int Weight = INF;
};

bool operator>(_int2 const& A, _int2 const& B)
{
	return A.Weight < B.Weight;
}
bool operator<(_int2 const& A, _int2 const& B)
{
	return A.Weight > B.Weight;
}

vector<vector<_int2>> Edges{};
vector<int> DistanceFromSrc{};
priority_queue<_int2> DijkstraQueue{};
/*
UpdateWeight
첫 방문노드로부터 호출
방문노드로부터 엣지 순회
SrcToDestWeight 와 엣지의 웨이트+도달하기까지 웨이트 와 비교하여 더 작은 값을 삽입
*/

/*
우선순위 큐에서 뽑아낸 노드(현재 근접한 가장 가까운 노드)
노드에대해서 최소거리 업데이트를 시도 방문하지 않은 노드는 거리를 업데이트하고 삽입
*/
void RoundEdges(int const StartNode)
{

	for (auto iter = Edges[StartNode].begin(); iter != Edges[StartNode].end(); iter++)
	{
		int const UpdatedWeight = iter->Weight + DistanceFromSrc[StartNode];
		if (UpdatedWeight < DistanceFromSrc[iter->NodeNum])
		{
			DistanceFromSrc[iter->NodeNum] = UpdatedWeight;
			DijkstraQueue.push({ iter->NodeNum,UpdatedWeight });
		}
	}
}

void Dijkstra(int const StartNodeNum)
{
	DistanceFromSrc[StartNodeNum] = 0;
	DijkstraQueue.push({ StartNodeNum ,0 });

	while (!DijkstraQueue.empty())
	{
		_int2 const VisitNode = DijkstraQueue.top();
		DijkstraQueue.pop();
		RoundEdges(VisitNode.NodeNum);
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int NodeSize = 0;
	int InputEdgesSize = 0;
	int StartNodeNum = 0;

	cin >> NodeSize >> InputEdgesSize >> StartNodeNum;
	Edges.resize(NodeSize + 1);
	for (int i = 0; i < NodeSize + 1; i++)
	{
		DistanceFromSrc.push_back(INF);
	}

	while (InputEdgesSize--)
	{
		_int2 InputEdge{};
		int InputNodeNum = 0;
		cin >> InputNodeNum >> InputEdge.NodeNum >> InputEdge.Weight;
		Edges[InputNodeNum].push_back(InputEdge);
	}
	Dijkstra(StartNodeNum);
	for (int i = 1; i < DistanceFromSrc.size(); i++)
	{
		if (DistanceFromSrc[i] == INF)
			cout << "INF" << "\n";
		else
			cout << DistanceFromSrc[i] << "\n";
	}
	return 0;
}