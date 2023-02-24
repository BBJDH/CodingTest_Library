/*
 * 11724 - ���� ����� ����
 *
 * BFS�õ��� ���̷��� StartNode�� �־ Ž���Ϸ��� ������
 * ���ܰ� �����ߴ�
 * 1-5
 * 5-6 �ΰ��
 *
 * StartNode�� �޴´ٸ� 1�� 5������ BFS�� �õ��Ѵ�.
 *
 * �� ��� 1���� BFS�� 1�� 5�� Visit ó���ǹǷ�
 *
 * �̹� �湮�� 5���� 6���� Ž���� ������ �� ����
 *
 * �� ��� 6������ BFS�� ���� ���ο� �������� Ȯ���ؾ� �ϴµ�,
 *
 * start�� dest�� �ߺ�ó���ϸ� ��� �����ϴ� ����� ������(������ ��Ͽ� ���� BFS)
 * �̰�� Edges�� ������ N^2�� �����ϹǷ�
 *
 * �׳� 1�� ������ ��尹����ŭ N�� BFS�Լ��� ȣ���ϵ��� �ۼ��ߴ�.
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