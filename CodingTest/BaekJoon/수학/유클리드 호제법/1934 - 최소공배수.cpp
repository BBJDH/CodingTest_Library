/*
 *1934 - 최소공배수
 *
 *
 *주어진 수 A와 B에 대하여 최대 공약수가 G라고 할 때,
 *
 *A를 G로 나눈 몫을 a, B 를 G로 나눈 몫을 b라고 한다면
 *
 *최소공배수 L = G x a x b 가 성립함을 알고 문제에 접근해야 한다.
 *
 *
 *유클리드 호제법으로 두 수의 최소공배수를 먼저 구하고 a와 b를 구한 후
 *
 *이 세 숫자를 곱하여 최소공배수를 출력한다.
 *
 */


#include <iostream>
#include <algorithm>

using namespace std;


int GCD(int const Bigger, int const Smaller)
{
	if (Smaller == 0)
	{
		return Bigger;
	}
	return GCD(Smaller, Bigger % Smaller);
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		int NumberOfInputs[2]{};
		for (int i = 0; i < 2; i++)
		{
			cin >> NumberOfInputs[i];
		}
		sort(NumberOfInputs, &NumberOfInputs[1]);

		int G = GCD(NumberOfInputs[1], NumberOfInputs[0]);
		int a = NumberOfInputs[0] / G;
		int b = NumberOfInputs[1] / G;
		cout << G * a * b << "\n";
	}

	return 0;
}