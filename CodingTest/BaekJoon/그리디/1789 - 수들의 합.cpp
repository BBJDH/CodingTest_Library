/*
 *1789 - 수들의 합
 *
 *자연수들의 합 이므로 가장 작은 자연수인 1부터 자례대로 더해간다
 *
 *1부터 N까지의 합 공식 = N(N+1)/2 이므로
 *
 * S >=N(N+1)/2 인 최대값 N을 찾으면 된다.
 *
 *이항해보면 2*S >= N(N+1) 관계가 성립하고
 *이를 쉽게 구하기 위해 N(N+1)의 값을 sqrt 함수를 활용한다.
 *
 *즉 N(N+1)이 아닌 N의 제곱으로 근사하여 근사값으로부터 탐색하면된다.
 *
 */

#include<iostream>
#include <math.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long S = 0, SearchNum = 0;
	cin >> S;
	SearchNum = static_cast<long long>(sqrt(S * 2));
	//근사값 계산

	if (SearchNum * (SearchNum + 1) / 2 <= S)	//식이 성립한다면 그대로 출력
	{
		cout << SearchNum;
		return 0;
	}
	//그렇지 않은경우 -1 출력
	cout << SearchNum - 1;

	return 0;
}