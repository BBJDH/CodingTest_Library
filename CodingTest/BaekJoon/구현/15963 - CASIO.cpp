/*
 *15963 - CASIO
 *
 *int가 가지는 수의 표현 범위를 물어보는 문제
 *
 *10의 자리를 모두 입력받는다면 int로는 표현이 불가하다
 *
 *99억을 받을 수 있게 long long 자료형을 사용한다.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long N = 0, M = 0;

	cin >> N >> M;

	if (N == M)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}


	return 0;

}