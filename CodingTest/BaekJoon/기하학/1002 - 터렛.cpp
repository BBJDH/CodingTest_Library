/*
 *1002 - 터렛
 *
 *기하학 문제이다
 *
 *두 사람의 좌표와 반경을 원으로 인식하고,
 *두 원의 충돌 지점이 몇개인지 계산한다.
 *
 *두 점의 위치와 반경이 모두 일치한다면 충돌지점이 무한대로 -1
 *
 *두 점사이의 거리를 구하고 거리가 두원의 반경의 합보다 멀다면 0
 *반대로 안쪽에서 완전히 포함된 경우도 역시
 *두 점 사이의 거리가 두 원의 반경의 차이보다 작다면 0을 반환한다.
 *
 *한 점이 겹치는 경우는 위의 두 거리가 같은 경우는 1을 반환
 *
 *이외의 경우는 모두 두 점이 충돌하므로 2를 반환한다
 *
 *위의 함수를 작성하고 각 TestCase에 대하여 출력한다.
 *
 *
 */

#include<iostream>
#include <cmath>

using namespace std;

struct _double3
{
	double X;
	double Y;
	double R;
};


int Collision(_double3 const& First, _double3 const& Second)
{
	//완전히 일치
	if (First.X == Second.X and First.Y == Second.Y and First.R == Second.R)
	{
		return -1;
	}

	double const Distance = sqrt((First.X - Second.X) * (First.X - Second.X)
		+ (First.Y - Second.Y) * (First.Y - Second.Y));

	//두 원이 멀리 떨어져 만나는 점이 없는 경우
	if (Distance > (First.R + Second.R))
	{
		return 0;
	}
	//원 한쪽이 다른 한쪽에 완전히 포함되어 만나는 점이 없는 경우
	if (Distance < abs(First.R - Second.R))
	{
		return 0;
	}
	//안에서 한 점이 만나는 경우
	if (Distance == abs(First.R - Second.R))
	{
		return 1;
	}
	//바깥에서 한 점이 만나는 경우
	if (Distance == (First.R + Second.R))
	{
		return 1;
	}
	return 2;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		_double3 CircleFirst{};
		_double3 CircleSecond{};

		cin >> CircleFirst.X >> CircleFirst.Y >> CircleFirst.R;
		cin >> CircleSecond.X >> CircleSecond.Y >> CircleSecond.R;
		cout << Collision(CircleFirst, CircleSecond) << "\n";

	}

	return 0;
}