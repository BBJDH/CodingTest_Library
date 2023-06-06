/*
 *27433 - 팩토리얼 2
 *
 *문제의 요구사항대로 N까지 증감하여 모든 자연수를 곱해준다.
 *
 *다만 20!의 경우 2432902008176640000 으로 int의 범위를 초과하므로
 *
 *long long으로 Result를 기록하여 출력한다.
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
	long long Result = 1;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		Result = Result * i;
	}
	cout << Result;

	return 0;
}