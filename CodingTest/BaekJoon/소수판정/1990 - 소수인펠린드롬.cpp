
/*
1990 - 소수 In 팰린드롬

수의 범위는 1억이지만 한번 프로그램을 돌려서 출력해보면
소수이면서 펠린드롬수는 1천만 이상 존재하지 않는다

문자열로 바로 확인가능한 펠린드롬수를 먼저 확인하고 그다음 브루트포스로 소수인지 검사

*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;


bool CheckPrimeNum(int const Num)
{

	for (int i = 2; i <= sqrt(Num); i++)
	{
		if (Num % i == 0)
		{
			return false;;
		}
	}
	return true;
}

bool CheckPalindrome(int const Num)
{
	string Str = to_string(Num);
	string Str_Cpy = Str;
	reverse(Str_Cpy.begin(), Str_Cpy.end());
	return Str == Str_Cpy;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int StartNum = 0;
	int EndNum = 0;

	cin >> StartNum >> EndNum;
	for (int i = StartNum; i <= EndNum; i++)
	{
		if (i > 10000000)
			break;
		if (CheckPalindrome(i) and CheckPrimeNum(i))
			cout << i << "\n";
	}

	cout << -1;
	return 0;
}
