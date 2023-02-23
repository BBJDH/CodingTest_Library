/*
 *11727 - 2xn 타일링 2
 *
 *n이 1인경우 1
 *n이 2인경우 3
 *3인경우 (n-2)*2 + n-1
 *.
 *.
 *.
 *
 *(맨끝타일이 횡으로 뻗은경우 또는 2*2로 덮인경우이므로 x2 + 종으로 한장만 둔 경우)
 *
 *마지막으로 구해진 수를 10007로 %처리하는것을 잊지 말자.
 *
 *
 */


#include<iostream>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int DP[1001]{};
	DP[1] = 1;
	DP[2] = 3;
	int N = 0;
	cin >> N;
	for (int i = 3; i <= N; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2] * 2) % 10007;
	}


	cout << DP[N];


	return 0;
}