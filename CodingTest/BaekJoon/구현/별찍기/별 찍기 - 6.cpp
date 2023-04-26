/*
 *
 *2443 - 별 찍기 - 6
 *
 *
 *문제의 요구사항대로 별찍기를 구현한다
 *
 *별을 1 빈공간을 0이라고 한다면,
 *
 *
 *N = 5 일 때,
 *
 *111111111  빈 공간 0개,  별 9개
 *01111111   빈 공간 1개,  별 7개
 *0011111	 빈 공간 2개,  별 5개
 *000111	 빈 공간 i개,  별 (N-i)*2-1
 *00001		 의 규칙으로 반복문을 구성한다.
 *
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

	for (int i = 0; i < N; i++)
	{
		for (int Blank = 0; Blank < i; Blank++)
		{
			cout << " ";
		}
		for (int Star = 0; Star < (N - i) * 2 - 1; Star++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}