/*
 *
 *1476 - 날짜 계산
 *
 *재귀와 브루트포스로 풀었다.
 *
 *E, S, M 은 모두 (Value % Max) + (Value / Max) 를통해 계산 가능하다
 *(이때 Max는 1이 되는 수이다 E는 16, S의 Max는 29)
 *
 *하지만 Value가 너무 커서 (Value % Max) + (Value / Max) 조차 Max를 넘어갈 수 있으므로
 *이것을 재귀적으로 처리했다.
 *
 *임의의 Value에 대해 E S M 을 구하는 함수를 위와 같이 재귀로 작성한 후
 *
 *Value를 브루트포스로 수를 하나씩 올려가며 완전 탐색한다.
 *
 *E S M 과 모두 일치하는 Value가 나타난다면 출력하고 종료한다.
 *
 *
 */

#include <iostream>

using namespace std;

int SetNum(int const Value, int const Max)
{
	if (Value < Max)
	{
		return Value;
	}
	int const NextValue = (Value % Max) + (Value / Max);
	return SetNum(NextValue, Max);
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int E = 0, S = 0, M = 0;
	int CurrentNum = 1;
	cin >> E >> S >> M;

	CurrentNum = max(max(E, S), M);
	while (true)
	{
		if (SetNum(CurrentNum, 16) == E and SetNum(CurrentNum, 29) == S and SetNum(CurrentNum, 20) == M)
		{
			cout << CurrentNum;
			break;
		}

		CurrentNum++;
	}


	return 0;
}