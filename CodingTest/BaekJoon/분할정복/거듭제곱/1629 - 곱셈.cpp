/*
 *1629 - 곱셈
 *
 * 입력받는 세수의 크기가 21억의 크기만큼 들어오므로
 *
 * 구현으로 몽땅 계산해나가면 시간초과가 발생한다.
 * 주어진 곱셈수 21억을 logn으로 풀어나갈 수 있는 분할정복을 통해 풀었다.
 *
 * 21억을 호출한다면 반으로 나눈 10억을 구해 이것을 두번 곱하면 된다.
 * 마찬가지로 10억은 5억으로 쪼개진다
 *
 * ...
 *
 * 마지막 1에 도달한다면 자신의 수 % 나눔수를 반환 처리한다
 *
 * 홀수인 경우만 예외로 처리하여 한번만 더 곱하여 나누어 반환처리한다.
 *
 * 매 곱셈마다 Mod 연산을 해주어야 한다 그렇지않으면 오버플로우로 틀린값이 계산된다.
 *
 * 나누어진수에 자신의 수를 곱해 나누거나 자신의 수*자신의 수를 곱해 나눔수로 나누어도 결과는 같아지는
 * 수학적 규칙이 있다.
 *
 */
#include <iostream>

using namespace std;

long long GetMul(long long const NumOfMul, long long CountOfMul, long long const NumOfMod)
{
	if (CountOfMul == 1)
	{
		return NumOfMul % NumOfMod;
	}

	long long ResultOfHalf = GetMul(NumOfMul, CountOfMul / 2, NumOfMod);

	long long Result = (ResultOfHalf * ResultOfHalf) % NumOfMod;

	if (CountOfMul % 2 == 1)
	{
		//홀수면 위의 계산에서 1이 날아갔으므로.. 1만큼 더 계산 
		Result = (Result * NumOfMul) % NumOfMod;
	}

	return Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long NumOfMul = 0, CountOfMul = 0, NumOfMod = 0;
	cin >> NumOfMul >> CountOfMul >> NumOfMod;

	long long Result = GetMul(NumOfMul, CountOfMul, NumOfMod);

	cout << Result;
	return 0;
}