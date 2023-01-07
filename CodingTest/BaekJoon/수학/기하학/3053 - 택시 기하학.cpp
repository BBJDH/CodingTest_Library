/*
 *3053 - 택시 기하학
 *
 *유클리드 기하학은 우리가 아는 일반적인 원의 넓이 공식을 정의하여 출력한다.
 *
 *택시 기하학에서의 원은 마름모 모양으로 형성된다
 *
 *즉 입력 받은 r 를 반 대각선으로 하는 마름모이므로
 *이 마름모의 넓이를 구해서 출력해주면 된다. R = 2r 이므로 2r*2r/2 =4r^2/2 = 2r^2 이다
 *
 *
 */

#include <iostream>
#include <math.h>
using namespace std;
#define PIE atan(1)*4

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(6);
	double r = 0;
	cin >> r;

	cout << r * r * PIE << "\n";
	cout << r * r * 2;

	return 0;
}