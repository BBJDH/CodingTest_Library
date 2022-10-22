#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long N = 0, M = 0;

	cin >> N >> M;

	long long m = M;
	long long Mul = 1;
	long long Div = 1;
	for (long long i = N; i > N - M; i--)
	{
		Mul *= i;
		Div *= m;
		m--;
	}
	cout << Mul / Div;
	return 0;
}