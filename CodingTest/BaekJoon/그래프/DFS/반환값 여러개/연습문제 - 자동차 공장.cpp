/*
 *======================================================================
 *�������� - �ڵ��� ����
 *
 *�־����� a b c �� ����
 *
 *�Ųٷ� Edges�� ����� DFS�� Ž���� ��ȯ�޴� ����� ����� ������.
 *
 *���� ���� �ܰ��� ����ǰ ���� �Ųٷ� �����Ͽ� b ���� a�� Ž���ϰ� ��ȯ�޴� ����� c�� ���ϴ� ������ �����Ѵ�.
 *
 *�ٸ� ����� ������ �ϴ� ������ �ΰ��̴� R-value�� ����� �� ��Ʈ�� ���Ͽ� ��Ȯ�� ��갪�� �򵵷� �����ؾ��Ѵ�.
 *
 */

#include <iostream>
#include <vector>
#define INF 1000000007

using namespace std;

struct _int2
{
	int Dest;
	int Count;
};

struct Cost
{
	int CostItem;
	int CostHuman;
};

vector<vector<_int2>> Edges{};
vector<int> Costs{};

Cost DFS(_int2 Current)
{
	Cost Result{};
	if (Edges[Current.Dest].empty())
	{
		//������ ����
		Result.CostItem += Costs[Current.Dest];
		return Result;
	}
	//�ΰǺ��� ���
	for (_int2 const& elem : Edges[Current.Dest])
	{
		//���� ��� ���� ���� �õ�, �� ���� ��� ��� ����
		Cost CurrentResult = DFS(elem);
		//���� �ݿ�
		CurrentResult.CostHuman = (CurrentResult.CostHuman * elem.Count) % INF;
		CurrentResult.CostItem = (CurrentResult.CostItem * elem.Count) % INF;
		//�ջ�
		Result.CostHuman = (Result.CostHuman + CurrentResult.CostHuman) % INF;
		Result.CostItem = (Result.CostItem + CurrentResult.CostItem) % INF;

	}
	//������ ���ϴ� �ΰǺ�� �������� �ջ�
	Result.CostHuman = (Result.CostHuman + Costs[Current.Dest]) % INF;
	return Result;
}

Cost Solution(int n, vector<int> costs, vector<vector<int>> edges)
{
	Cost answer{};
	Edges.resize(n);
	Costs = costs;
	int Root = edges[0][0] - 1;
	for (vector<int> const& elem : edges)
	{
		Edges[elem[1] - 1].push_back({ elem[0] - 1,elem[2] });
		if ((elem[0] - 1) == Root)
		{
			Root = elem[1] - 1;
		}
	}
	//root�� DFS


	answer = DFS({ Root, 1 });

	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//vector<vector<int>> InputEdges = { {1,7,3}, {2,4,2}, {2,5,1}, {3,4,1},
	//	{3,5,2}, {4,7,1}, {5,7,2}, {6,7,1}, {7,8,2} };
	//Solution(8, {4,5,10,10,10,8,10,10}, InputEdges);

	//vector<vector<int>> InputEdges = {{3,1,2}, {1,2,1}, {4,1,2}, {4,2,3} };
	//Solution(4, { 10,10,5,6 }, InputEdges);

	vector<vector<int>> InputEdges = { {4,3,2}, {3,2,2}, {2,1,2} };
	Solution(4, { 1,1,1,1 }, InputEdges);

	return 0;
}

