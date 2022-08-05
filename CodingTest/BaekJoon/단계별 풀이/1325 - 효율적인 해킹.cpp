#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<algorithm>


using namespace std;
struct Node
{
	vector<int> Edges;
};

struct _int2
{
	int NodeNum;
	int Count;
};

int Visit[10001]{};
Node Coms[10001]{};
queue<int> BFSQueue{};
stack<int> DFSStack{};
vector<_int2> Results{};
int VisitCount = 0;

bool Compare(_int2 const& A, _int2 const& B)
{
	if (A.Count == B.Count)
		return A.NodeNum < B.NodeNum;
	return A.Count > B.Count;
}

void Clear()
{
	for (int i = 0; i < 10001; i++)
		Visit[i] = false;
	VisitCount = 0;
}


void Push_Queue(int const& NextPass)
{
	if (Visit[NextPass] == false)
	{
		Visit[NextPass] = true;
		BFSQueue.push(NextPass);
		VisitCount++;
	}
}
void Push_Stack(int const& NextPass)
{
	if (Visit[NextPass] == false)
	{
		Visit[NextPass] = true;
		DFSStack.push(NextPass);
		VisitCount++;
	}
}


void BFS(int const StartNum)//시작 노드 번호 전달 필요
{
	Clear();
	Push_Queue(StartNum);

	while (!BFSQueue.empty())
	{
		int const CurrentPath = BFSQueue.front();
		BFSQueue.pop();
		for (int i = 0; i < Coms[CurrentPath].Edges.size(); i++)
		{
			Push_Queue(Coms[CurrentPath].Edges[i]);
		}
	}
	Results.push_back({ StartNum,VisitCount });
}

void DFS(int const StartNum)//시작 노드 번호 전달 필요
{
	Clear();
	Push_Stack(StartNum);

	while (!DFSStack.empty())
	{
		int const CurrentPath = DFSStack.top();
		DFSStack.pop();
		for (int i = 0; i < Coms[CurrentPath].Edges.size(); i++)
		{
			Push_Stack(Coms[CurrentPath].Edges[i]);
		}
	}
	Results.push_back({ StartNum,VisitCount });
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	int NodeSize = 0;
	cin >> NodeSize >> TestCase;
	while (TestCase--)
	{
		int SrcCom = 0;
		int EdgeCom = 0;
		cin >> EdgeCom >> SrcCom;
		Coms[SrcCom].Edges.push_back({ EdgeCom });
	}
	//각 노드에대해서 큐에 넣고 출발
	for (int i = 1; i <= NodeSize; i++)
		DFS(i);

	sort(Results.begin(), Results.end(), Compare);

	int MaxCount = Results[0].Count;

	for (int i = 0; i < Results.size(); i++)
		if (MaxCount == Results[i].Count)
			cout << Results[i].NodeNum << " ";

	return 0;
}