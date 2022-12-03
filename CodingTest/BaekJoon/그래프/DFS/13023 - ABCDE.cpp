/*
 *
 *13023 - ABCDE
 *
 *���̰� 0���� ���� 4���� ���� �����Ѵٸ� �����ƾ���� DFS�� ó���Ѵ�
 *
 *�� ��忡���ؼ� ��� DFS�� �����Ѵ�.
 *
 *����� Ž���� �ƴ� ���� �����̹Ƿ� ������ ������ ��ƾ�� ���� �湮ó�� ������ �ʿ��ϴ�
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