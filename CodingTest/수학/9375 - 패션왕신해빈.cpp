
/*
9375 - 패션왕 신해빈

옷을 고르지 않은 경우를 포함하여 경우의 수를 계산

옷의 카테고리당 가짓수가 3 2 3 이라면
각각 안고른 경우를 포함하여 4 3 4 로 계산하여 4*3*4 -1로 계산
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;


map<string, int> Cloths{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		Cloths.clear();
		int Size = 0;
		cin >> Size;
		while (Size--)
		{
			string Name{};
			string InputCategory{};
			cin >> Name >> InputCategory;
			Cloths[InputCategory]++;
		}
		int Mul = 1;
		for (auto const& Elem : Cloths)
			Mul *= (Elem.second + 1);
		cout << Mul - 1 << "\n";
	}

	return 0;
}
