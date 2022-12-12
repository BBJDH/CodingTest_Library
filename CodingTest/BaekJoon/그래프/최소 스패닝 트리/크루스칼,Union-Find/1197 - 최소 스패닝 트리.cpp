/*
1197 - �ּ� ���д� Ʈ��

ũ�罺Į �˰����� ���� �ִܰŸ��� �����Ѵ�

���� Edge�� ���� ������ �Ѵ�

���� Edge�� �� ���� Start�� Dest�� ���ؼ� Union�� �˻�,

���� �ٸ� �θ� �����ٸ� �ϳ��� �����ش�. �ѹ� ���� ��δ� ������ �����Ƿ�,

�����ٶ� Edge�� ����ġ�� TotalWeight�� �����Ѵ�

�� ������ �ݺ�, ������ TotalWeight�� ����Ѵ�.

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

	//FindParent ��� ȣ���� �ƴ� Parent�� ������ �ؾ��ϴ� ����?
	//ã�� �� �ֻ��� �θ� ����� ������Ʈ ���ش�
	//1 <- 2<- 3<-4 �� ���� �θ� ���������� parent(4)�� ȣ���ϸ� 1234�� Parent[i]�� 1�� ������Ʈ�ȴ�
	//������ ������ ȣ�⿡���� ����� �е������� ����
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

