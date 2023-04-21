/*
 *
 *1550 - 16진수
 *
 * FFF 를 십진수로 변환하면,
 *
 * F(16^2)*15 + F(16^1)*15 + F(16^0)*15 로 계산된다
 *
 * 마찬가지로 A901 를 변환한다면,
 *
 * A(16^3)*10 + (16^2)*9 + (16^1)*0 + (16^0)*1 로 계산된다
 *
 * 즉 각 자리수 별로 16의 지수와 해당 자릿수를 10진수로 변환한 수의 곱이므로
 * 먼저 각 자리수 별로 10진수로 변환할 함수를 만든다.
 *
 * 이후 입력 받은 문자열에 대하여 반복문으로 순회하며 함수를 호출한다
 *
 * 함수에서 반환되는값을 누적하여 합한 결과가 16 진수로 변환한 값에 해당한다.
 *
 *
 *
 */



#include <iostream>
#include <string>
#include <cmath>

using namespace std;



long long HexToDec(char const Hex, long long const Exponent)
{
	long long Result = 0;
	if (Hex <= '9')
	{
		Result = Hex - '0';
	}
	else
	{
		Result = Hex - 'A' + 10;
	}

	Result = Result * static_cast<long long>(pow(16, Exponent));

	return Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	cin >> InputStr;
	long long Result = 0;

	for (int i = 0; i < InputStr.size(); i++)
	{
		Result += HexToDec(InputStr[InputStr.size() - i - 1], i);
	}
	cout << Result;
	return 0;
}