/*
 *
 *2644- 촌수계산
 *
 *그래프 탐색을 통해 풀이 가능하다
 *
 *각 사람을 Node로 취급하고 사람 하나를 건너갈 때마다 촌수가 증가한다
 *
 *이 촌수를 Count로 기록하여 관리한다.
 *
 *BFS를 통해 탐색하여 정답을 출력했다.
 *
 *
 *
 */



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct _int2
{
	int Node;
	int Count;
};

vector<vector<int>> Edges{};
queue<_int2> BFS_Queue{};
vector<int> Visit{};

int Start = 0, Dest = 0;
int Size = 0;

void Push(_int2 const Next)
{
	if (Visit[Next.Node] == false)
	{
		Visit[Next.Node] = true;
		BFS_Queue.push(Next);
	}
}

void RoundEdges(_int2 const Current)
{
	for (int const elem : Edges[Current.Node])
	{
		_int2 Next{};
		Next.Node = elem;
		Next.Count = Current.Count + 1;
		Push(Next);
	}
}

void BFS(int const Start)
{
	int Result = -1;
	Push({ Start ,0 });

	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		if (Current.Node == Dest)
		{
			Result = Current.Count;
			break;
		}
		RoundEdges(Current);
	}
	cout << Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> Size;
	cin >> Start >> Dest;
	int NumOfEdges = 0;
	cin >> NumOfEdges;
	Visit.resize(Size + 1);
	Edges.resize(Size + 1);
	for (int i = 0; i < NumOfEdges; i++)
	{
		int InputStart = 0, InputDest = 0;
		cin >> InputStart >> InputDest;

		Edges[InputStart].push_back(InputDest);
		Edges[InputDest].push_back(InputStart);
	}

	BFS(Start);

	return 0;
}
