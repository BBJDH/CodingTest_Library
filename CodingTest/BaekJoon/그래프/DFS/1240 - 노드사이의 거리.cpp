/*
 *1240 - �������� �Ÿ�
 *
 *Edge�� ���⼺�� �����Ƿ� Ž���� �߻��ϴ� ��ȯ�� �����ϱ� ���� Visit�� �߰��Ѵ�
 *Query�� ���������� DFS�� �������־� �ٷιٷ� ����� ������ �ߴ�.
 *�� Query���� �湮ó���ʱ�ȭ�� ���� ����
 *
 */


#include <iostream>
#include <vector>

using namespace std;

struct  _int2
{
	int Pos;
	int Distance;
};

vector<vector<_int2>> Edges{};
bool Visit[1001]{};
int HowManyNodes = 0;
int HowManyQuery = 0;

void DFS(int const Current, int const& Dest, int Distance)
{
	if (Current == Dest)
	{
		cout << Distance << "\n";
		return;
	}
	Visit[Current] = true;
	for (int i = 0; i < Edges[Current].size(); i++)
	{
		int Next = Edges[Current][i].Pos;
		if (Visit[Next] == false)
			DFS(Next, Dest, Distance + Edges[Current][i].Distance);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> HowManyNodes >> HowManyQuery;
	Edges.resize(HowManyNodes + 1);
	for (int i = 0; i < HowManyNodes - 1; i++)
	{
		int start = 0;
		_int2 Edge{};
		cin >> start >> Edge.Pos >> Edge.Distance;
		Edges[start].emplace_back(Edge);
		Edges[Edge.Pos].push_back({ start,Edge.Distance });
	}

	for (int i = 0; i < HowManyQuery; i++)
	{
		fill_n(Visit, 1001, false);
		int start = 0;
		int dest = 0;

		cin >> start >> dest;

		DFS(start, dest, 0);
	}

	return 0;
}