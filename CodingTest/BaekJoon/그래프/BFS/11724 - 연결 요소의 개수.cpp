/*
 * 11724 - 연결 요소의 개수
 *
 * BFS시도를 줄이려고 StartNode마 넣어서 탐색하려고 했지만
 * 예외가 존재했다
 * 1-5
 * 5-6 인경우
 *
 * StartNode만 받는다면 1과 5에서만 BFS를 시도한다.
 *
 * 이 경우 1에서 BFS시 1과 5가 Visit 처리되므로
 *
 * 이미 방문된 5에서 6으로 탐색을 진행할 수 없다
 *
 * 이 경우 6에서도 BFS를 통해 새로운 구역임을 확인해야 하는데,
 *
 * start와 dest를 중복처리하며 모두 저장하는 방법이 있지만(저장한 목록에 대해 BFS)
 * 이경우 Edges의 갯수가 N^2에 근접하므로
 *
 * 그냥 1번 노드부터 노드갯수만큼 N번 BFS함수를 호출하도록 작성했다.
 *
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int NumberOfNodes = 0, NumberOfEdges = 0;

queue<int> BFS_Queue{};
vector<vector<int>> Edges{};
bool Visit[1001]{};

bool Push(int NextNode)
{
	if (Visit[NextNode] == false)
	{
		Visit[NextNode] = true;
		BFS_Queue.push(NextNode);
		return true;
	}
	return false;
}

void RoundEdges(int CurrentNode)
{
	for (int const elem : Edges[CurrentNode])
	{
		Push(elem);
	}
}

bool BFS(int StartNode)
{
	if (Push(StartNode) == false)
		return false;
	while (!BFS_Queue.empty())
	{
		int CurrentNode = BFS_Queue.front();
		BFS_Queue.pop();
		RoundEdges(CurrentNode);
	}
	return true;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int NumberOfConnectingElements = 0;

	cin >> NumberOfNodes >> NumberOfEdges;

	Edges.resize(NumberOfNodes + 1);

	for (int i = 0; i < NumberOfEdges; i++)
	{
		int StartNode = 0, DestNode = 0;
		cin >> StartNode >> DestNode;

		Edges[StartNode].push_back(DestNode);
		Edges[DestNode].push_back(StartNode);
	}

	for (int elem = 1; elem <= NumberOfNodes; elem++)
	{
		if (BFS(elem) == true)
			NumberOfConnectingElements++;
	}
	cout << NumberOfConnectingElements;

	return 0;
}