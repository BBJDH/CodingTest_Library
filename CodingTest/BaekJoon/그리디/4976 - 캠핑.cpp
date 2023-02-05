
/*
 *4976 - 캠핑
 *
 *휴가안에 캠핑장을 한번만 쓰는것이 아니라
 *
 *여러번 끊어서라도 지정된 휴가날짜 안에 최대한 캠핑장을
 *사용할수 있는 일수를 구하는것이 요구사항이다.
 *
 *때문에 지정된 휴가일수 V안에서 사용가능한 텀 P의 배수만큼 사용하고
 *남은 일수를 다음 텀 P로 생각하여 연속되는 사용일 L로서 사용한다
 *(즉 P의 배수로 빠진 나머지일수와 L을 비교하여 더 작은 일수로 합산한다.)
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int L = 0, P = 0, V = 0;
	int TestCase = 0;
	while (true)
	{
		cin >> L >> P >> V;
		if (V == 0)
			return 0;
		TestCase++;
		int mul = V / P;
		int mod = min(L, V - (mul * P));
		int result = mul * L + mod;
		cout << "Case " << TestCase << ": " << result << "\n";
	}


	return 0;
}