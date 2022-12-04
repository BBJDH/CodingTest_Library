/*
 *1068 - 트리
 *
 *DFS로 접근하여 맨 끝에 도달시 (즉 Edge가 없다면) LeafCount를 늘려준다
 *최상위 부모가 반드시 0이 아니다!
 *입력조건에 -1은 최상위 노드 입력임을 유추했다.
 *
 *따라서 지정된 루트노드로 부터 DFS로 탐색시킨다
 *지워진 노드는 해당 Edge만 지워줘도 된다 하위까지 지우지 않아도
 *루트로부터 탐색을 시도하므로 지워진 노드의 Edge에 도달 할 수 없다.
 *
 *트리구조이므로 순환이 없기때문에 방문처리가 필요치 않다.
 *반드시 한번씩만 방문하게된다.
 *
 */

#include <iostream>
#include <vector>

using namespace  std;

int Parents[51]{};
vector<vector<int>>Edges{};
int LeafCount = 0;

void DFS(int CurrentNode)
{
	if (Edges[CurrentNode].empty())
		LeafCount++;

	for (int i = 0; i < Edges[CurrentNode].size(); i++)
	{
		int NextNode = Edges[CurrentNode][i];
		DFS(NextNode);
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int NodeCount = 0;

	cin >> NodeCount;
	Edges.resize(NodeCount);

	int StartNode = 0;

	for (int Node = 0; Node < NodeCount; Node++)
	{

		cin >> Parents[Node];
		if (Parents[Node] == -1)
			StartNode = Node;
		else
			Edges[Parents[Node]].emplace_back(Node);
	}
	int eraseNode = 0;
	cin >> eraseNode;
	if (eraseNode == StartNode)
	{
		cout << 0;
		return 0;
	}
	if (!Edges[Parents[eraseNode]].empty() and eraseNode < NodeCount)
	{
		for (int i = static_cast<int>(Edges[Parents[eraseNode]].size()) - 1; i >= 0; i--)
		{
			if (Edges[Parents[eraseNode]][i] == eraseNode)
				Edges[Parents[eraseNode]].erase(Edges[Parents[eraseNode]].begin() + i);
		}
	}
	DFS(StartNode);
	cout << LeafCount;
	return 0;
}