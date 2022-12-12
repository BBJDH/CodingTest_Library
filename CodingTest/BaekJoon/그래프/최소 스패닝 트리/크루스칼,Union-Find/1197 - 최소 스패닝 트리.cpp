/*
1197 - 최소 스패닝 트리

크루스칼 알고리즘을 통해 최단거리를 연결한다

최초 Edge에 대해 정렬을 한다

작은 Edge의 양 끝단 Start와 Dest에 대해서 Union을 검사,

서로 다른 부모를 가졌다면 하나로 묶어준다. 한번 묶은 경로는 변하지 않으므로,

묶어줄때 Edge의 가중치를 TotalWeight에 누적한다

이 과정을 반복, 종료후 TotalWeight를 출력한다.

 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

struct Edge
{
	int Start;
	int Dest;
	int Weight;
};

bool operator<(Edge const& First, Edge const& Second)
{
	return First.Weight < Second.Weight;
}
bool operator>(Edge const& First, Edge const& Second)
{
	return First.Weight > Second.Weight;
}

int Parent[10001]{};
vector<Edge>Edges{};

int VertextSize = 0;
int EdgeSize = 0;

int FindParent(int const ChildNum)
{
	if (Parent[ChildNum] == ChildNum) return ChildNum;

	//FindParent 재귀 호출이 아닌 Parent에 대입을 해야하는 이유?
	//찾는 겸 최상위 부모를 제대로 업데이트 해준다
	//1 <- 2<- 3<-4 로 서로 부모를 물고있을때 parent(4)를 호출하면 1234의 Parent[i]는 1로 업데이트된다
	//떄문에 이후의 호출에서는 비용이 압도적으로 감소
	return Parent[ChildNum] = FindParent(Parent[ChildNum]);
}

void Solution()
{
	int totalWeight = 0;

	sort(Edges.begin(), Edges.end());

	for (auto const& elem : Edges)
	{
		int startParnet = FindParent(elem.Start);
		int destParnet = FindParent(elem.Dest);
		if (startParnet != destParnet)
		{
			Parent[destParnet] = startParnet;
			totalWeight += elem.Weight;
		}
	}
	cout << totalWeight;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> VertextSize >> EdgeSize;

	for (int i = 1; i <= VertextSize; i++)
	{
		Parent[i] = i;
	}

	while (EdgeSize--)
	{
		Edge InputEdge{};
		cin >> InputEdge.Start >> InputEdge.Dest >> InputEdge.Weight;
		Edges.emplace_back(InputEdge);
	}
	Solution();


	return 0;
}

