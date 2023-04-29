/*
 *
 *2523 - 별 찍기 - 13
 *
 *문제의 요구사항대로 구현한다.
 *
 *
 */
#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = N - 1; i > 0; i--)
	{
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		cout << "\n";

	}

	return 0;
}