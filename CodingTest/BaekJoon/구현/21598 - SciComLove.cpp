/*
 *21598 - SciComLove
 *
 *간단한 조건문과 반복문을 다룰 수 있는지 물어보는 문제
 *
 *N이 2 이하일때만 갯수 만큼 SciComLove 를 출력한다.
 *
 *
 */

#include<iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	if (N <= 2)
	{
		while (N--)
		{
			cout << "SciComLove\n";
		}
	}

	return 0;
}