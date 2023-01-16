/*
 *2446 - 별 찍기 - 9
 *
 *역 피라미드를 출력하는 코드를 작성하고
 *이것을 반복문 안에서 모래시계의 중간에 도달하면
 *더해지는 숫자를 토글하여 다시 피라미드를 출력하도록 구현했다.
 *
 */


#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n = 0;
	cin >> n;

	int direction = 1;

	for (int i = n; i > 0 and i <= n; i -= direction)
	{
		for (int blank = 0; blank < n - i; blank++)
			cout << " ";
		for (int star = 0; star < i * 2 - 1; star++)
			cout << "*";
		cout << "\n";
		if (i == 1)
			direction *= -1;
	}

	return 0;
}