/*
 *
 *13023 - ABCDE
 *
 *깊이가 0시작 기준 4깊이 까지 도달한다면 종료루틴으로 DFS를 처리한다
 *
 *각 노드에대해서 모두 DFS를 시행한다.
 *
 *모든노드 탐색이 아닌 깊이 측정이므로 측정에 실패한 루틴에 대해 방문처리 해제가 필요하다
 *
 */



#include <iostream>
#include <vector>

using namespace  std;



vector<vector<int>>Edges{};
bool Visit[2000]{};
int NodeCount = 0;
int EdgeCount = 0;


int DFS(int const Node, int const  Depth)
{
	if (Depth == 4)
	{
		return Depth;
	}
	int result = 0;
	Visit[Node] = true;
	for (int i = 0; i < Edges[Node].size(); i++)
	{
		int const Dest = Edges[Node][i];

		if (Visit[Dest] == false)
		{
			result = max(result, DFS(Edges[Node][i], Depth + 1));
		}

	}
	Visit[Node] = false;
	return result;
}


bool Solution()
{
	for (int i = 0; i < NodeCount; i++)
	{
		if (DFS(i, 0) == 4)
			return true;
	}
	return false;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> NodeCount >> EdgeCount;
	Edges.resize(NodeCount);

	for (int i = 0; i < EdgeCount; i++)
	{
		int Start = 0;
		int Dest = 0;

		cin >> Start >> Dest;
		Edges[Start].emplace_back(Dest);
		Edges[Dest].emplace_back(Start);
	}
	cout << Solution();
	return 0;
}