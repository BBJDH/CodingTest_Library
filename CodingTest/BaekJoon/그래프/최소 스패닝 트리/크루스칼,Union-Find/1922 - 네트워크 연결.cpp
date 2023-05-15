/*
 * 1922 - 네트워크 연결
 *
 * 크루스칼을 이용해 최소스패닝트리를 만들어 해결했다.
 *
 *
 *문제를 크게 나누면,
 *- 모든 컴퓨터는 연결되어야 한다.
 *- 최소비용으로 연결되어야 한다.
 *
 * 이에 따라 각 컴퓨터간의 연결 비용에 대해 그리디로 접근한다.
 *
 * _int3 자료형을 만들어 Src에서 Dest로 연결하는 비용 Weight을 비교하는
 *
 * 부등호 연산자 함수를 오버로딩한다.
 *
 * 모든 Edges를 _int3으로 입력받아 배열로 저장하고, 위의 부등호를 이용해 정렬한다.
 *
 * 이후 최소 비용인 간선부터 꺼내 하나의 Parent로 묶어주는 작업을 시작한다.
 *
 * 만약 Src와 Dest의 Parent가 동일하다면 이미 연결된 것이므로 비용을 합산하지 않는다.
 * (자기 자신으로의 연결인경우도 Parent가 동일하게 되므로 합산되지 않는다.)
 *
 * 모든 Edge에 대해 위의 과정을 반복하고 완료 후 TotalWeight를 출력한다.
 *
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct _int3
{
	int Src;
	int Dest;
	int Weight;
};

bool operator>(_int3 const& Left, _int3 const& Right)
{
	return Left.Weight > Right.Weight;
}
bool operator<(_int3 const& Left, _int3 const& Right)
{
	return Left.Weight < Right.Weight;
}


int Parent[1001]{};

int GetParent(int const Child)
{
	if (Parent[Child] == Child)
	{
		return Child;
	}
	return Parent[Child] = GetParent(Parent[Child]);
}

void Solution(vector<_int3>& Edges)
{
	int TotalWeight = 0;

	sort(Edges.begin(), Edges.end());

	for (_int3 const Elem : Edges)
	{
		int const SrcParent = GetParent(Elem.Src);
		int const DestParent = GetParent(Elem.Dest);

		if (SrcParent != DestParent)
		{
			Parent[DestParent] = SrcParent;
			TotalWeight = TotalWeight + Elem.Weight;
		}
	}
	cout << TotalWeight;
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<_int3>Edges{};
	int NumOfComputer = 0, NumOfEdges = 0;

	cin >> NumOfComputer >> NumOfEdges;

	for (int i = 1; i <= NumOfComputer; i++)
	{
		Parent[i] = i;
	}

	while (NumOfEdges--)
	{
		_int3 Input{};
		cin >> Input.Src >> Input.Dest >> Input.Weight;
		Edges.push_back(Input);
	}
	Solution(Edges);
	return 0;
}