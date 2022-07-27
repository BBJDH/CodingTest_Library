#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
각 원별로 해당 점이 안에 있는지 체크,
원안에 점 1개만 있는 것을 모두 카운트, 이 합계가 지나야 하는 항성계

*/
struct _float3
{
	float X;
	float Y;
	float Radius;
};
struct _float2
{
	float X;
	float Y;
};

vector<int> InCircleCheck;
vector<_float3> Circles;
_float2 Start{};
_float2 Dest{};

void InputInfo(int const CircleCount)
{
	InCircleCheck.clear();
	Circles.clear();

	for (int i = 0; i < CircleCount; i++)
	{
		_float3 InputCircle{};
		cin >> InputCircle.X >> InputCircle.Y >> InputCircle.Radius;
		Circles.push_back(InputCircle);
		InCircleCheck.push_back(0);
	}
}


float Length(_float2 const& Start, _float2 const& Dest)
{
	return sqrt((Start.X - Dest.X) * (Start.X - Dest.X) + (Start.Y - Dest.Y) * (Start.Y - Dest.Y));
}

bool CollideDotAndCircle(_float2 const& Dot, _float3 const& Circle)
{
	return Length(Dot, { Circle.X,Circle.Y }) <= Circle.Radius;
}

//모든 원에대해 해당 점이 원 안에 있는지 체크
void CheckAllCircle()
{
	int Count = 0;
	for (int i = 0; i < Circles.size(); i++)
	{
		if (CollideDotAndCircle(Start, Circles[i]))
			InCircleCheck[i]++;
		if (CollideDotAndCircle(Dest, Circles[i]))
			InCircleCheck[i]++;
	}
	for (int i = 0; i < Circles.size(); i++)
		if (InCircleCheck[i] == 1)
			Count++;

	cout << Count << "\n";
}



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		int CircleCount = 0;
		cin >> Start.X >> Start.Y >> Dest.X >> Dest.Y;
		cin >> CircleCount;
		InputInfo(CircleCount);
		CheckAllCircle();
	}


	return 0;
}
