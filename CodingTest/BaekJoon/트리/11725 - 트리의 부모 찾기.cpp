
/*

11725 - Ʈ���� �θ� ã��
������ ������ �־����� �� ������ 1�� ��Ʈ�� �Ͽ� ���� ��Ʈ�� ã�Ƴ����� ����̴�.
���� �湮�� ���� �湮 ���� �θ��̰� ���� �湮 ���� �ڽ��̵ȴ�
DFS BFS ��������� Ǯ�� �����ϴ�
DFS�� ��� �湮�ϰ� �Ǵ°�� �θ� ���� �� �� ���ȣ���ϴ� ������� �����ߴ�.

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