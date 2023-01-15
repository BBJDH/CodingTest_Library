/*
 *1297 - TV크기
 *
 *피타고라스 정리를 이용해 빗변 C를 구한다.
 *
 *실제 대각선의 길이를 구했던 C로 나누어 비율울 구하고
 *
 *해당 비율에 밑변과 높이 A B를 곱해 출력한다.
 *
 */

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double TargetC = 0;
	double A = 0, B = 0, C = 0;
	double Mul = 0;
	cin >> TargetC >> A >> B;

	C = sqrt(A * A + B * B);
	Mul = TargetC / C;
	cout << static_cast<int>(A * Mul) << " " << static_cast<int>(B * Mul);

	return 0;
}