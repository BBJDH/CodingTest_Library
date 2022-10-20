
/*

11725 - 트리의 부모 찾기
무작위 연결이 주어지고 이 연결을 1을 루트로 하여 다음 루트를 찾아나가는 방식이다.
따라서 방문시 이전 방문 노드는 부모이고 현재 방문 노드는 자식이된다
DFS BFS 어느쪽으로 풀던 무관하다
DFS의 경우 방문하게 되는경우 부모를 지정 한 후 재귀호출하는 방식으로 구현했다.

*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>Edge{};
int Parents[100001]{};
bool Visit[100001]{};

int InputCase = 0;

void DFS(int Pos = 1)
{
	Visit[Pos] = true;
	for (int i = 0; i < Edge[Pos].size(); i++)
	{
		if (Visit[Edge[Pos][i]] == false)
		{
			Parents[Edge[Pos][i]] = Pos;
			Visit[Edge[Pos][i]] = true;
			DFS(Edge[Pos][i]);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Edge.resize(100001);
	cin >> InputCase;
	int Count = InputCase;
	while (Count--)
	{
		int InputLeft{}, InputRight{};
		cin >> InputLeft >> InputRight;
		Edge[InputLeft].push_back(InputRight);
		Edge[InputRight].push_back(InputLeft);
	}
	DFS();
	for (int i = 2; i <= InputCase; i++)
		cout << Parents[i] << "\n";
	return 0;
}