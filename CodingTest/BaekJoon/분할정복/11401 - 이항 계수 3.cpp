/*
 *11401 - 이항 계수 3
 *
 *이항 계수 (N K) 는 N! / K!(N-K)! 를 이용해 이항 계수 (N K)의 Mod 1,000,000,007을 구한다.
 *
 *문제가 요구하는 정해는 1,000,000,007(이하 Limit라고 한다.)의 나머지를 요구한다는 것을 이용해
 *나머지 연산의 성질을 이용한다
 *
 *(a*b)%Limit =  (a%Limit*b%Limit)%Limit 임을 이용해야한다
 *
 *문제는  (a/b)%Limit =  (a%Limit/b%Limit)%Limit 가 성립되지 않는다.
 *(나눗셈은 안된다!, 즉 N! / K!(N-K)!의 /는 성립되지 않는다!)
 *
 *때문에 분모인 K!(N-K)!의 역 ((K!(N-K)!)^-1)%Limit를 구해야 한다
 *
 *여기서 페르마의 소정리가 필요해진다 페르마의 소정리는
 *
 *a는 정수 p는 소수일때,
 *
 *pow(a,p)%p = a%P 가 성립한다. 양변을 a로 나누면
 *pow(a,p-1)%p = 1%p 를 다시 양변으로 나누면
 *pow(a,p-2)%p = (a^-1)%p가 된다.
 *여기에서 a^-1이 치환되어 (K!(N-K)!)^-1)라고 생각하면 된다!
 *(공교롭게도 Limit = 1,000,000,007는 소수이다. )즉 우리가 원하는 정해는
 *
 *[N!* pow(K!(N-K)!,Limit-2)]%Limit 이다 (연산과정의 변수 오버플로에 유의하자.)
 *여기서 pow()는 타겟이 되는 정수의 1,000,000,005 제곱을 구해야 하는데...
 *당연히 오버플로우가 예상된다. 매 제곱당 %Limit를 처리해주자
 *
 *그냥 N의 비용으로 제곱을 접근하면 느리다. 다음의 성질을 이용한다.
 *
 *a의 8제곱은 a의 4제곱 * a의 4제곱과 같다
 *
 *즉 1,000,000,005를 지수가 1 혹은 2가 될때 까지 분할하여 함수를 호출해
 *분할정복으로 제곱을 계산토록 처리하면 된다.
 *
 *
 */

#include <iostream>
#define Limit 1000000007

using namespace std;

int CalcFactorialWithLimit(long long TargetNum)
{
	long long Result = 1;

	while (TargetNum)
	{
		Result *= TargetNum;
		Result = Result % Limit;
		TargetNum--;
	}
	return static_cast<int>(Result);
}


long long PowWithLimit(long long TargetNum, int Exponent)
{
	if (Exponent == 1)
		return TargetNum;
	if (Exponent == 2)
		return (TargetNum * TargetNum) % Limit;
	if (Exponent % 2 == 1)
	{
		return (PowWithLimit(TargetNum, Exponent / 2) * PowWithLimit(TargetNum, ((Exponent / 2) + 1))) % Limit;
	}
	return PowWithLimit(TargetNum, Exponent / 2) * PowWithLimit(TargetNum, (Exponent / 2)) % Limit;
}

void Solution(int N, int K)
{
	long long N_FactorialWithLimit = 1;
	long long K_FactorialWithLimit = 1;
	long long N_Minus_K_FactorialWithLimit = 1;
	long long Denominator = 1;
	int Result = 0;


	N_FactorialWithLimit = CalcFactorialWithLimit(N);
	K_FactorialWithLimit = CalcFactorialWithLimit(K);
	N_Minus_K_FactorialWithLimit = CalcFactorialWithLimit(N - K);
	Denominator = PowWithLimit(((K_FactorialWithLimit * N_Minus_K_FactorialWithLimit) % Limit), Limit - 2);
	Result = (N_FactorialWithLimit * Denominator) % Limit;
	cout << Result;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, K = 0;
	cin >> N >> K;

	Solution(N, K);

	return 0;
}