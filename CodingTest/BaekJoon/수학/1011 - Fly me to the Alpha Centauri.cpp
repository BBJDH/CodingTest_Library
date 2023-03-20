/*
 *1011 - Fly me to the Alpha Centauri
 *
 *처음에는 BFS를 통해 위치가 Dest와 일치하고 속도가 0이라면 도착으로 처리했다.
 *
 *하지만 목적지는 2^31로 메모리 초과를 발생,
 *
 *다른 접근 방법을 찾아보기로 했다.
 *	(+1이 되는 지점)
 *이동거리가 1(1) 이라면 1번 1				- 이전 제곱수인 0*2+1
 *이동거리가 2(O) 이라면 2번 1 1				- 제곱수 1을 지남 +1
 *이동거리가 3(O) 이라면 3번 1 1 1		- 제곱수 1과 4사이인 2를 지남 +1
 *이동거리가 4(X) 라면   3번 1 2 1			- 변하지 않음
 *이동거리가 5(O) 라면   4번 1 2 1 1			- 제곱수 4를 지남
 *이동거리가 6(X) 이라면 4번 1 2 2 1			- 변하지 않음
 *이동거리가 7(O) 이라면 5번 1 2 2 1 1		- 4와 9 사이인 6을 지남
 *이동거리가 8(X) 이라면 5번 1 2 2 2 1		- 변하지 않음
 *이동거리가 9(X) 이라면 5번 1 2 3 2 1		- 변하지 않음
 *이동거리가 10(O) 이라면 6번 1 2 3 2 1 1		- 제곱수 9를 지남
 *이동거리가 11(X) 이라면 6번 1 2 3 2 2 1		- 변하지 않음
 *이동거리가 12(X) 이라면 6번 1 2 3 3 2 1		- 변하지 않음
 *이동거리가 13(O) 이라면 7번 1 2 3 3 2 1		- 제곱수 9와 16 사이인 12를 지남
 *
 * ...
 *
 *위와 같이 제곱수와 제곱수와 제곱수의 사이지점을 지날때마다 이동거리가 1씩 늘어난다
 *즉 현재 받은 임의의 거리가 Distance라고 한다면,
 *
 *Distance의 제곱근인 SqrtOfDistance를 구하고,
 *(SqrtOfDistance-1)*2+1를 이동거리로 계산해 둔다.
 *이후 현재 Distance가 SqrtOfDistance의 제곱을 지났다면 +1
 *SqrtOfDistance와 SqrtOfDistance+1의 제곱근 사이점을 지났다면 +1
 *처리하여 출력한다.
 *
 *입력 받는 거리는 2의 31승이 될 가능성이 있다 따라서 제곱 후 더하는 int 자료형의 오버플로우가 발생할 수 있다.
 *때문에 SqrtOfDistance*SqrtOfDistance가 아닌 double을 반환하는 pow함수를 이용해
 *계산을 완료하고 이 값을 int로 캐스팅했다.
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		int Start = 0, Dest = 0, Result = 0;
		int SqrtOfDistance = 0, Distance = 0;
		int NumOfMiddle = 0;
		cin >> Start >> Dest;
		Distance = Dest - Start;
		SqrtOfDistance = static_cast<int>(sqrt(Distance));
		NumOfMiddle = static_cast<int>((pow(SqrtOfDistance, 2) + pow(SqrtOfDistance + 1, 2)) / 2);
		Result = (SqrtOfDistance - 1) * 2 + 1;

		if (Distance > pow(SqrtOfDistance, 2))
		{
			Result++;
		}
		if (Distance > NumOfMiddle)
		{
			Result++;
		}

		cout << Result << "\n";
	}

	return 0;
}