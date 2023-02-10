/*
 * 16953 - A → B
 *
 *두번째로 입력받은 DestNum에서 거꾸로 연산한다.
 *
 *2 162
 *162 ->81 -> 8 -> 4-> 2
 *
 *DestNum이 홀수라면 10으로 나누고(일의 자리는 사라지므로 -1처리는 필요없다.)
 *짝수이면 2로 나누어서 접근한다.
 *
 *DestNum이 홀수 일때 일의자리가 1이 아닌경우 StartNum에 도달할 수 없으므로
 *반복문 탈출처리한다.
 *
 *그래프 탐색을 통해 풀수도 있겠지만 위와같은 그리디가 더 적합하다.
 *항상 최소연산으로 해결 가능하다.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int StartNum = 0, DestNum = 0;
	int Count = 0;
	cin >> StartNum >> DestNum;

	while (DestNum > StartNum)
	{
		if (DestNum % 2 == 1)
		{
			if (DestNum % 10 != 1)
				break;
			DestNum /= 10;
		}
		else
			DestNum /= 2;

		Count++;
		if (StartNum == DestNum)
		{
			cout << Count + 1;
			return 0;
		}
	}
	cout << -1;

	return 0;
}