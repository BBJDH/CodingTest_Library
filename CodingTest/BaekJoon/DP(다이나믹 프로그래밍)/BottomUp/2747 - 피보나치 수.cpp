/*
 *2747 - 피보나치 수
 *
 *2번 수열까지의 수를 미리 점화식으로 하여
 *
 *DP[i] = DP[i-1] + DP[i-2]로 메모이제이션 한다.
 *
 *N까지 계산을 완료했다면 이 수를 출력하고 종료
 *
 */
#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int DP[46]{};
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 1;
	int N = 0;
	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	cout << DP[N];

	return 0;
}