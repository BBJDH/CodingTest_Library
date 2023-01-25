/*
 *
 * 1010 - 다리 놓기
 *
 *문제의 조건이 왼쪽 사이트가 오른쪽 사이트갯수 이하이므로
 *
 *오른쪽 사이트를 N 왼쪽 사이트를 r 이라고 하면
 *
 *nCr 과 같은 결과값이 도출된다.
 *
 *nCr 은 n! / r!(n-r)! 으로
 *
 *하지만 n!과 r! 등 팩토리얼을 그대로 구하면 long long 범위조차 이탈한다.
 *
 *그렇다면 어떻게 구해야 하는가?
 *
 *nCr를 약분해보면 다음과 같이 정리된다
 *
 * n-r과 r중 작은것을 Count 라고 한다면
 *
 *N부터 Count개만큼의 순차곱 / Count! 으로 진행한다.
 *
 *하지만 분모 따로 분자 따로 먼저 계산하면 역시 long long을 이탈할 우려가 있기 때문에
 *
 *Count만큼 도는 반복문을 통해 곱하기와 나누기를 같이 계산하여 진행한다.
 *
 *
 */

#include<iostream>

using namespace std;

void GetCombination(int const N, int const R)
{
	int Count = 0;
	int Result = 1;
	Count = min(R, N - R);

	for (int i = 0; i < Count; i++)
	{
		Result *= (N - i);
		Result /= (i + 1);
	}
	cout << Result << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, R = 0, TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		cin >> R >> N;
		GetCombination(N, R);
	}

	return 0;
}