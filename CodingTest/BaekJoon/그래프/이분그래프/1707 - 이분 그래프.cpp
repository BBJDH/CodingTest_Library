/*
 * 1707 - 이분 그래프
 *
 *BFS를 통해 붉은색(R), 파란색(B)로 각 방문 노드를 번갈아 칠해가며,
 *어떤노드에서 방문을 시작하여도 R또는 B가 연속되지 않는지 확인해야 한다.
 *
 *처음에는 BFS를 통해 문제의 요구사항대로 RB를 번갈아 칠하고
 *DFS를 통해 모든 노드에서 탐색하도록 하여 이분 그래프를 검사하고자 했다.
 *
 *하지만 시간초과가 발생
 *
 *방법을 강구해보니 따로 DFS를 시행하지 않아도 된다.
 *
 *처음 BFS를 시행할때 사이클이 되는 시점, 즉 방문했던 곳에 다시 돌아가는 시점에
 *RB스위칭이 성립하는지(거꾸로 말하면 RR BB로 연속되는 방문이 나타나는지)확인하면 된다.
 *
 *만약 한번이라도 RR 또는 BB로 연속된다면 이분그래프가 아님으로 결정
 *결과를 리턴한다.
 *
 *
 *
 *이분그래프는 짝수 크기의 사이클만을 가진다.
 *이 특성을 이용해 union-find로 사이클검사로 이분그래프 판별할수있지 않을까
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

		//DFS 확인
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
