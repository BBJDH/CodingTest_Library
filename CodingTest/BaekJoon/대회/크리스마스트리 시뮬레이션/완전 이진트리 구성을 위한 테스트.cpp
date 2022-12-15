/*
 *가능한 0~9가 나올수 있는 수의 조합 출력
 *
 *
 */


#include <iostream>
#include <vector>

using namespace std;

struct _int2
{
	int Left;
	int Right;
};
vector<vector<_int2>> Combinations{};

void PrintPairNums(int const TargetNum)
{
	for (int left = 0; left <= 9; left++)
	{
		for (int right = 0; right <= 9; right++)
		{
			int const  result = left + right;

			if (TargetNum == result % 10)
			{
				Combinations[TargetNum].push_back({ left,right });
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Combinations.resize(10);
	for (int i = 0; i <= 9; i++)
	{
		PrintPairNums(i);
	}

	return 0;
}