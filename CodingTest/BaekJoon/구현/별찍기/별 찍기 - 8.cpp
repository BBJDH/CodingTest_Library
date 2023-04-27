/*
 *
 *2445 - 별 찍기 - 8
 *
 *
 *각 한 줄마다 별, 빈 공간, 별 순으로 반복문으로 출력한다
 *
 *별은 1부터 N까지 출력 빈 공간은 (N-i)*2의 규칙으로 나아간다
 *
 *N 까지 도달했다면 이번엔 N-1부터 1까지 위 아래 대칭이 되도록 출력한다.
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
		//별 출력
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		for (int Blank = 0; Blank < (N - i) * 2; Blank++)
		{
			cout << " ";
		}
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = N - 1; i > 0; i--)
	{
		//별 출력
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		for (int Blank = 0; Blank < (N - i) * 2; Blank++)
		{
			cout << " ";
		}
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}