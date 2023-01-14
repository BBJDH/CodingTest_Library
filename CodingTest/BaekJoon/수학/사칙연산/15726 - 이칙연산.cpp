/*
 *15726 - 이칙연산
 *
 *곱하고 나누는 경우와 나누고 곱하는 경우 두가지 뿐 이므로
 *둘의 max를 출력한다.
 *
 *문제의 조건에 따라 소수점을 버리기 위해 정수 자료형으로 캐스팅 했다.
 *
 */

#include <iostream>
#define LIMIT 1000000000

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double A = 0, B = 0, C = 0;
	cin >> A >> B >> C;

	cout << static_cast<int>(max(A * B / C, A / B * C));

	return 0;
}