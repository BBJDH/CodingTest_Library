
/*
1747 - 소수 & 팰린드롬

에라스토테네스의 채로 소수를 먼저 찾고, 이후 팰린드롬수인지를 판별

*/
#include<iostream>
#include<bitset>
#include<vector>
#include<string>
using namespace std;

#define Size 1003002

bitset<Size> Nums{};
vector<string> PrimeNums{};



void SetPrimeNum()
{
	Nums.flip();
	Nums[0] = false;
	Nums[1] = false;
	for (int i = 2; i * i < Size; i++)
	{
		if (Nums[i])
			PrimeNums.push_back(to_string(i));
		for (int j = 2; i * j < Size; j++)
		{
			Nums[i * j] = false;
		}
	}
}

bool CheckPalindrome(int const Num)
{
	string Str = to_string(Num);

	for (int i = 0; i < Str.size() / 2; i++)
	{
		if (Str[i] != Str[Str.size() - i - 1])
			return false;
	}

	return true;
}

void GetPalindrome(int const StartNum)
{
	for (int i = StartNum; i < Size; i++)
	{
		if (Nums[i] and CheckPalindrome(i))
		{
			cout << i;
			return;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputNum = 0;

	cin >> InputNum;
	SetPrimeNum();
	GetPalindrome(InputNum);


	return 0;
}
