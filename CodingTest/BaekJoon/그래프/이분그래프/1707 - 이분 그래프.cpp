/*
 * 1707 - �̺� �׷���
 *
 *BFS�� ���� ������(R), �Ķ���(B)�� �� �湮 ��带 ������ ĥ�ذ���,
 *���忡�� �湮�� �����Ͽ��� R�Ǵ� B�� ���ӵ��� �ʴ��� Ȯ���ؾ� �Ѵ�.
 *
 *ó������ BFS�� ���� ������ �䱸���״�� RB�� ������ ĥ�ϰ�
 *DFS�� ���� ��� ��忡�� Ž���ϵ��� �Ͽ� �̺� �׷����� �˻��ϰ��� �ߴ�.
 *
 *������ �ð��ʰ��� �߻�
 *
 *����� �����غ��� ���� DFS�� �������� �ʾƵ� �ȴ�.
 *
 *ó�� BFS�� �����Ҷ� ����Ŭ�� �Ǵ� ����, �� �湮�ߴ� ���� �ٽ� ���ư��� ������
 *RB����Ī�� �����ϴ���(�Ųٷ� ���ϸ� RR BB�� ���ӵǴ� �湮�� ��Ÿ������)Ȯ���ϸ� �ȴ�.
 *
 *���� �ѹ��̶� RR �Ǵ� BB�� ���ӵȴٸ� �̺б׷����� �ƴ����� ����
 *����� �����Ѵ�.
 *
 *
 *
 *�̺б׷����� ¦�� ũ���� ����Ŭ���� ������.
 *�� Ư���� �̿��� union-find�� ����Ŭ�˻�� �̺б׷��� �Ǻ��Ҽ����� ������
 *
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool Push(int const Current, int const Next, vector<char>& Visit, queue<int>& BFSQueue)
{
	if (Visit[Next] == '\0')
	{
		if (Visit[Current] == 'R')
		{
			Visit[Next] = 'B';
		}
		else if (Visit[Current] == 'B')
		{
			Visit[Next] = 'R';
		}
		BFSQueue.push(Next);
		return true;
	}
	if (Visit[Current] == Visit[Next])
	{
		return false;
	}
	if (Visit[Current] == Visit[Next])
	{
		return false;
	}
	return true;
}

bool RoundEdge(int const Current, vector<vector<int>> const& Edges, vector<char>& Visit, queue<int>& BFSQueue)
{
	for (int const Dest : Edges[Current])
	{
		if (Push(Current, Dest, Visit, BFSQueue) == false)
		{
			return false;
		}
	}
	return true;
}

bool BFS(int const Start, vector<char>& Visit, vector<vector<int>> const& Edges)
{
	queue<int>BFSQueue{};
	if (Visit[Start] == '\0')
	{
		Visit[Start] = 'R';
	}
	BFSQueue.push(Start);

	while (!BFSQueue.empty())
	{
		int const Current = BFSQueue.front();
		BFSQueue.pop();
		if (RoundEdge(Current, Edges, Visit, BFSQueue) == false)
		{
			return false;
		}
	}
	return true;
}

bool DFS(int Current, vector<bool>& DFSVisit, vector<vector<int>> const& Edges, vector<char> RBVisit)
{
	if (DFSVisit[Current] == true)
	{
		return true;
	}
	DFSVisit[Current] = true;
	for (int const Dest : Edges[Current])
	{
		if (RBVisit[Current] == RBVisit[Dest])
		{
			return false;
		}
		if (RBVisit[Current] == RBVisit[Dest])
		{
			return false;
		}
		if (DFS(Dest, DFSVisit, Edges, RBVisit) == false)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		int VertexNum = 0, EdgeNum = 0;
		vector<vector<int>> Edges{};
		vector<char> Visit{};

		cin >> VertexNum >> EdgeNum;
		Edges.resize(VertexNum + 1);
		Visit.resize(VertexNum + 1);
		for (int i = 0; i < EdgeNum; i++)
		{
			int Src = 0, Dest = 0;
			cin >> Src >> Dest;
			Edges[Src].push_back(Dest);
			Edges[Dest].push_back(Src);
		}

		bool IsBipartiteGraph = true;
		for (int Start = 1; Start <= VertexNum; Start++)
		{
			if (BFS(Start, Visit, Edges) == false)
			{
				IsBipartiteGraph = false;
				break;
			}
		}
		if (IsBipartiteGraph == true)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";

		}

		//DFS Ȯ��
		//bool IsBipartiteGraph = true;
		//for(int Start = 1; Start<= VertexNum; Start++)
		//{
		//	vector<bool>DFSVisit{};
		//	DFSVisit.resize(VertexNum + 1);
		//	if(DFS(Start, DFSVisit,Edges,Visit)==false)
		//	{
		//		IsBipartiteGraph = false;
		//		break;
		//	}
		//}
		//if(IsBipartiteGraph == true)
		//{
		//	cout << "YES\n";
		//}
		//else
		//{
		//	cout << "NO\n";
		//	
		//}

	}

	return 0;
}
