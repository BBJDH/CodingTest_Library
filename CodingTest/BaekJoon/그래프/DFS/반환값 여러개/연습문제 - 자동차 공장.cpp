/*
 *======================================================================
 *연습문제 - 자동차 공장
 *
 *주어지는 a b c 에 대해
 *
 *거꾸로 Edges를 만들어 DFS로 탐색해 반환받는 비용을 계산해 나간다.
 *
 *가장 높은 단계의 완제품 부터 거꾸로 접근하여 b 에서 a를 탐색하고 반환받는 비용의 c를 곱하는 식으로 접근한다.
 *
 *다만 계산해 나가야 하는 변수가 두개이다 R-value로 만들어 각 루트에 대하여 명확한 계산값을 얻도록 연습해야한다.
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
		//재료까지 도달
		Result.CostItem += Costs[Current.Dest];
		return Result;
	}
	//인건비의 경우
	for (_int2 const& elem : Edges[Current.Dest])
	{
		//먼저 재료 까지 도달 시도, 각 단일 재료 비용 산출
		Cost CurrentResult = DFS(elem);
		//갯수 반영
		CurrentResult.CostHuman = (CurrentResult.CostHuman * elem.Count) % INF;
		CurrentResult.CostItem = (CurrentResult.CostItem * elem.Count) % INF;
		//합산
		Result.CostHuman = (Result.CostHuman + CurrentResult.CostHuman) % INF;
		Result.CostItem = (Result.CostItem + CurrentResult.CostItem) % INF;

	}
	//재료들을 합하는 인건비는 마지막에 합산
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
	//root로 DFS


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

