#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*

한층의 초콜릿 갯수를 구해보면
White : RC + (R-1)(C-1)
Dark : (R-1)C + R(C-1)
의 공식이 나오게 된다

전개 해 보면,

White : 2RC - R - C + 1;
Dark : 2RC - R - C;
로 식이 W 와 D가 식이 중첩된다
따라서 한쪽을 구해주면 다른한쪽도 쉽게 구할 수 있다.

R과 C에 대해 층을 쌓아 올리면, R 또는 C가 1일 때 까지 위의 식의 합을 구하면 된다
따라서 R 과 C를 한가지 변수로 두고, 시그마식으로 구해보자

R과 C 중 R을 큰 수로 설정하면,
d = (R-C) 로 설정했을때 R = C+d 가 된다 따라서 식을 다시 정리하면 
Black 은 2(C+d)C - (C+d) -C 로 정리된다.
전개하면 2C^2+2dC -2C-d => 2C^2 + 2(d-1)C -d가 된다 이것을 시그마로 대입하면

sigma(1~C) Dark : C * (C + 1) * (2 * C + 1) / 3 + (diff - 1) * C * (C + 1) - diff * C
sigma(1~C) White : C * (C + 1) * (2 * C + 1) / 3 + (diff - 1) * C * (C + 1) - diff * C +C
임을 알 수 있다.

*/

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long R = 0;
	long long C = 0;


	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		cin >> R >> C;

		if (R < C)
			swap(R, C);
		long long diff = R - C;
		long long Dark = C * (C + 1) * (2 * C + 1) / 3 + (diff - 1) * C * (C + 1) - diff * C;
		long long White = Dark + C;

		cout << White << " " << Dark << "\n";

	}
	return 0;
}
