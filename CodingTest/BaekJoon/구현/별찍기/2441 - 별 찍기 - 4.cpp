/*
 *2441 - 별 찍기 - 4
 *
 *빈 공간과 별을 나누어 출력한다라고 했을때
 *0과 *로 표시한다면
 *
 * *****
 * 0****
 * 00***
 * 000**
 * 0000*
 *
 * 로 표시된다 즉 전체 반복문 i의 흐름이 0~ N-1일때
 * 0을 i만큼(0~N-1), *을 N-i개만큼 찍고 줄을 넘기면 된다.
 */

#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int space = 0; space < i; space++)
			cout << " ";
		for (int star = 0; star < N - i; star++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}