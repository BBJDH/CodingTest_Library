/*
 *25559 - 패스
 *
 *
 *원형으로 카드를 돌린다고 생각을 해보면,
 *
 *첫번째 큰 카드인 N을 먼저 본인이 받고,
 *
 *N-1카드와 2
 *N-3카드와 4
 *N-5카드와 6
 *N-7카드와 8
 *	.
 *	.
 *	.
 *	N-a가 1이면 1카드를 받아 종료
 *
 *로 두 카드의 합을 N+1을 만들어 모든 인원이 패스를 받을 수 있다.
 *
 *예시를 들어 12로 풀어본다면
 *
 *12 11 2 9 4 7 6 5 8 3 10 1  로 모두 패스를 받는 것이 가능하다
 *
 *1의 경우 1카드를 받으면 공을 패스해 자신이 다시 받게 되므로 1은 예외로 한다
 *
 *홀수의 경우는 위의 조건을 따르면 카드가 중복되어 성립하지 않는다
 *
 *즉 카드의 합으로 왼쪽은 홀수, 오른쪽은 짝수를 두기 위해서는 반드시 N은 짝수여야 한다.
 *
 */


#include <iostream>

using namespace std;


void Solution(int const N)
{
	if (N == 1)
	{
		cout << 1;
		return;
	}
	if (N % 2)
	{
		cout << -1;
		return;
	}

	cout << N << " ";
	for (int i = N - 1; i >= 2; i -= 2)
	{
		cout << i << " " << (N + 1) - i << " ";
	}
	cout << 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;
	Solution(N);

	return 0;
}