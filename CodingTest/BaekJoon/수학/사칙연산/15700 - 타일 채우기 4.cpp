/*
 * 15700 - 타일 채우기 4
 *
 *간단한 사칙연산 문제이지만
 *
 *int 오버플로우를 물어보는 문제이기도 하다.
 *
 *먼저 문제의 해결방법은
 *N과 M을 곱하면 가용한 칸 수가 나오고
 *이것을 2로 나누면(타일의 크기가 2이므로) 해답을 찾을 수 있다.
 *
 *하지만 N과 M이 10억을 초과함을 주의해야한다.
 *
 *여기서 NxM을 받을 변수만 longlong으로 지정해서는 안된다
 *
 *NxM을 연산시 곱하기 연산을 N이 호출하여 N이 저장받으므로
 *
 *M은 int여도 되지만 결과값을 잠시 받는 N는 long long이어야 한다.
 */


#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int M = 0;
	long long N = 0;
	long long NumberOfCells = 0;

	cin >> N >> M;

	NumberOfCells = N * M;
	cout << NumberOfCells / 2;

	return 0;
}