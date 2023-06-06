/*
 *27323 - 직사각형
 *
 *정말 간단한 기하학 문제
 *
 *사각형의 넓이 공식대로 입력받은 변을 곱하여 출력한다.
 *
 *
 */
#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A = 0, B = 0;
	cin >> A >> B;

	cout << A * B;

	return 0;
}