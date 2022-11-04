/*
1644 - 소수의 연속합

에라토스테네스의 체로 소수를 찾고
이에 대한 누적합 배열을 저장한다
이것을 투포인터로 좌측부터 탐색(Left Right 포인터가 좌측에서 시작한다)
탐색하며 일치하는 합이 등장하면 Count 증가 및 최종 출력

*/



#include <iostream>
#include <vector>

using namespace  std;

bool Nums[4000001]{};
vector<int> PrimeNums{};
int TargetNum = 0;


void MarkNonPrime()
{
	Nums[0] = true;
	Nums[1] = true;
	for (int i = 2; i * i <= 4000000; i++)
	{
		if (Nums[i] == false)
		{
			for (int j = 2; j * i <= 4000000; j++)
			{
				Nums[i * j] = true;
			}
		}
	}
}
void PushPrimeNum()
{
	int Sum = 0;

	PrimeNums.emplace_back(Sum);
	for (int i = 2; i <= 4000000; i++)
	{
		if (Nums[i] == false)
		{
			Sum += i;
			PrimeNums.emplace_back(Sum);
		}
	}
}

void FindCountSum()
{
	int Left = 0;
	int Right = 1;
	int Count = 0;
	while (Left < Right and Right < PrimeNums.size())
	{
		int Sum = PrimeNums[Right] - PrimeNums[Left];
		if (Sum == TargetNum)
			Count++;
		if (Sum <= TargetNum)
			Right++;
		else
			Left++;
	}
	cout << Count;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	MarkNonPrime();
	PushPrimeNum();

	cin >> TargetNum;

	FindCountSum();

	return 0;
}