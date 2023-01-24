/*
 * 1010 - 다리 놓기
 *
 * nCr = n!/r!(n-r)!
 *
 *
 *
 *
 */


#include <iostream>
using namespace std;

long long Factorial(int Factor)
{
	long long result = 1;

	for(long long i = 1; i<=Factor; i++)
	{
		result *= i;
	}
	return result;
}

void Solution(int N, int K)
{
	long long Denominator = Factorial(N);
	long long R_Factorial = Factorial(K);
	long long NR_Factorial = Factorial(N-K);
	cout << Denominator/(R_Factorial* NR_Factorial)<<"\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	int N = 0, M = 0;
	cin >>TestCase;

	while (TestCase--)
	{
		cin >> N >> M;
		Solution(M, N);
	}

	return 0;
}