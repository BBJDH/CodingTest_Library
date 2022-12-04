/*
 *1068 - Ʈ��
 *
 *DFS�� �����Ͽ� �� ���� ���޽� (�� Edge�� ���ٸ�) LeafCount�� �÷��ش�
 *�ֻ��� �θ� �ݵ�� 0�� �ƴϴ�!
 *�Է����ǿ� -1�� �ֻ��� ��� �Է����� �����ߴ�.
 *
 *���� ������ ��Ʈ���� ���� DFS�� Ž����Ų��
 *������ ���� �ش� Edge�� �����൵ �ȴ� �������� ������ �ʾƵ�
 *��Ʈ�κ��� Ž���� �õ��ϹǷ� ������ ����� Edge�� ���� �� �� ����.
 *
 *Ʈ�������̹Ƿ� ��ȯ�� ���⶧���� �湮ó���� �ʿ�ġ �ʴ�.
 *�ݵ�� �ѹ����� �湮�ϰԵȴ�.
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