/*
 *
 *1717 - 집합의 표현
 *
 *Union-Find를 통해 풀이 가능하다.
 *
 *처음 입력받는 N개에 대하여 자신을 부모로 가지는 집합을 배열로 만들어준다.
 *
 *Union[원소] = 부모  의 관계를 가지도록 만든다.
 *
 *이것을 재귀적으로 호출하여 부모를 찾아나간다.
 *
 *이때 재귀함수의 최종반환인 최상위 부모가 모든 원소들의 부모로 업데이트되도록
 *재귀함수를 구성한다.
 *
 *합집합 연산은 LeftNum의 최상위 부모를 RightNum의 최상위 부모로 합쳐지도록 연산한다
 *(즉 LeftNum의 집합이 RightNum의 집합으로 합쳐지게 된다.)
 *
 *이후 같은 집합인지 구분 여부는 GetParent를 통해 동일한 최상위 부모를 가졌는지
 *
 *확인만 해주면 된다.
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;


vector<int> Union{};

int GetParent(int const Child)
{
	if (Union[Child] == Child)
	{
		return Child;
	}
	return Union[Child] = GetParent(Union[Child]);
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Size = 0;
	int TestCase = 0;
	cin >> Size >> TestCase;

	Union.resize(Size + 1);
	for (int i = 0; i < Union.size(); i++)
	{
		Union[i] = i;
	}

	while (TestCase--)
	{
		int Operator = 0, LeftNum = 0, RightNum = 0;

		cin >> Operator >> LeftNum >> RightNum;

		if (Operator == 0)
		{
			Union[GetParent(LeftNum)] = GetParent(RightNum);
			continue;
		}
		if (GetParent(LeftNum) == GetParent(RightNum))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}


	return 0;
}