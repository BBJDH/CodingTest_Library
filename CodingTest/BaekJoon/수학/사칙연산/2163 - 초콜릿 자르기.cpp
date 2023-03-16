/*
 *2163 - 초콜릿 자르기
 *
 *
 *입력받은 가로로 나눈 수, 세로로 나눈 수 중
 *
 *작은 수와 큰 수로 나누고
 *
 *작은 수인 쪽 축을 기준으로 먼저 나눈후 나누어 탄생한 축들을
 *
 *다시 큰 수인 축쪽으로 나눈다
 *
 *예를 들어 초콜릿 문양이
 *
 * ******
 * ******
 * ******
 *
 *위와 같다고 가정해 보면, (6x3)
 *
 * 먼저 작은축으로 자른다 (3개로 나누기 위해 2번 자른다)
 *
 * ******
 *
 * ******
 *
 * ******
 *
 * 이것을 이번엔 분할수가 많은 축으로 모두 잘라준다(분할된 개수3*5 )
 *
 * 즉 2 + 3*5
 *
 * 정리하면 (작은 분할수-1) + (작은 분할수)*(큰 분할수-1) 로 정리된다.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;

	cin >> N >> M;

	int const SideNumOfMin = min(N, M);
	int const SideNumOfMax = max(N, M);

	cout << (SideNumOfMin - 1) + SideNumOfMin * (SideNumOfMax - 1);

	return 0;
}