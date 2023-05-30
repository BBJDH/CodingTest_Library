/*
 *15829 - Hashing
 *
 *문제의 요구사항대로 구현한다.
 *
 *다만 문자의 길이가 50이 아니라 더 길어질수도 있다는 가정으로
 *지수 계산을 분할정복으로 풀었다(이 문제는 분할정복으로 구하지않고 N으로 모두 곱해도 풀이 가능하다.)
 *
 *
 *1234567891 * 1234567891 는 오버플로우가 발생하므로 계산값은 long long으로 받아서 처리한다.
 *
 *해싱함수와 안에서 지수값을 분할정복으로 계산할 GetPowerNumWithModNum 함수를 작성했다.
 *
 *입력받은 문자열의 각 문자에 맞추어 해싱값을 구하고 ModNum으로 나머지 연산하여 출력한다.
 *
 */

#include <iostream>
#include <string>

using namespace std;


//Mod로 오버플로우를 방지하는 분할정복 지수 계산, 1234567891*1234567891는 42억을 넘어간다.
long long GetPowerNumWithModNum(long long const BaseNum, long long ExponentNum, long long const NumOfMod)
{
	if (ExponentNum == 0)
	{
		return 1;
	}
	if (ExponentNum == 1)
	{
		return BaseNum % NumOfMod;
	}

	//지수를 반으로 쪼개어 계산 유도
	long long ResultOfHalf = GetPowerNumWithModNum(BaseNum, ExponentNum / 2, NumOfMod);

	//쪼갠값 다시 합치기
	long long Result = (ResultOfHalf * ResultOfHalf) % NumOfMod;

	if (ExponentNum % 2 == 1)
	{
		//홀수면 위의 계산에서 1이 날아갔으므로.. 1만큼 더 계산 
		Result = (Result * BaseNum) % NumOfMod;
	}

	return Result;
}

long long HashFunction(string const& InputStr)
{
	long long Result = 0;
	long long const ModNum = 1234567891;
	long long const EigenValue = 31;

	for (int i = 0; i < InputStr.size(); i++)
	{
		long long HashNum = InputStr[i] - 'a' + 1;
		HashNum = HashNum * GetPowerNumWithModNum(EigenValue, i, ModNum);
		HashNum = HashNum % ModNum;
		Result += HashNum;
		Result = Result % ModNum;
	}
	return Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Lenth = 0;
	string InputStr{};
	cin >> Lenth >> InputStr;

	cout << HashFunction(InputStr);

	return 0;
}