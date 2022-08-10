
#include<iostream>
#include<vector>
#include<queue>


#define INF 30000000
using namespace std;

/*
�������� StartNodeNum
ť�� ������ ����
������ ť�κ��� Edge�� �湮
������ Weight�� 0���� ����
�ش� ���� Edge�� �����Ͽ� ����ġ�� ��

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
ù �湮���κ��� ȣ��
�湮���κ��� ���� ��ȸ
SrcToDestWeight �� ������ ����Ʈ+�����ϱ���� ����Ʈ �� ���Ͽ� �� ���� ���� ����
*/

/*
�켱���� ť���� �̾Ƴ� ���(���� ������ ���� ����� ���)
��忡���ؼ� �ּҰŸ� ������Ʈ�� �õ� �湮���� ���� ���� �Ÿ��� ������Ʈ�ϰ� ����
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