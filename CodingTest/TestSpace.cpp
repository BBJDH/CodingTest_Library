/*
 *2022 제1회 미적확통컵 A번 - 연속인가? ?
 *
 *입력 받은 k에 대해 양쪽에서 수렴하는지만 확인해주면 된다 즉
 *
 *a (a*k+b) == (c * k + d) 가 true라면 해당 함수 f(x)는 연속이다
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long k = 0;
	long long a = 0, b = 0, c = 0, d = 0;

	cin >> k>>a>>b>>c>>d;

	if((a*k+b) == (c * k + d))
	{
		cout << "Yes"<<" "<< (a * k + b);
	}
	else
	{
		cout << "No";
	}

	return 0;
}