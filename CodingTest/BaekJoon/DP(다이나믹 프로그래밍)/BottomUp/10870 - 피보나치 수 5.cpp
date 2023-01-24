/*
 * 10870 - 피보나치수 5
 *
 * DP를 만들어 dp[1]=dp[2]=1 의 값을 넣어두고
 * dp[i] = dp[i-1]+dp[i-2]의 식으로 메모이제이션 한다.
 *
 * 값계산중 int 범위를 넘어감에 유의
 *
 *
 */

#include <iostream>
#define Size 21
using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int DP[100]{};
	DP[1] = 1;
	DP[2] = 1;
	for (int i = 3; i <= Size; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	int n = 0;
	cin >> n;
	cout << DP[n];

	return 0;
}