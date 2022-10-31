/*
2467 - 용액

정렬된 번호들을
양쪽의 끝을 Left Right로 두고,
Left Right의 합이 0보다 작다면 Left를 증가
합이 0보다 크다면 Right 감소로 둘이 만날때 까지 반복문을 돌며 값을 계산한다
그중 가장 차이가 작은 값을 저장/출력

*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct _int3
{
	int Left;
	int Right;
	int Sum;
};

vector<int> Nums{};
//              1,000,000,000*2
_int3 Result{ 0,0,2000000001 };
int NumSize = 0;


void Search()
{
	int Left = 0;
	int Right = static_cast<int>(Nums.size()) - 1;

	while (Left < Right)
	{
		int const Sum = Nums[Left] + Nums[Right];

		if (abs(Sum) < Result.Sum)
		{
			Result.Left = Nums[Left];
			Result.Right = Nums[Right];
			Result.Sum = abs(Sum);
		}

		if (Sum < 0)
			Left++;
		else
			Right--;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> NumSize;
	while (NumSize--)
	{
		int InputNum = 0;
		cin >> InputNum;
		Nums.emplace_back(InputNum);
	}
	sort(Nums.begin(), Nums.end());
	Search();
	cout << Result.Left << " " << Result.Right;

	return 0;
}