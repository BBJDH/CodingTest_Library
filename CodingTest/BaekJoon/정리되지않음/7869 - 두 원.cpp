#include<iostream>
#include <math.h>
#define PI acos(-1)

using namespace std;


struct _double2
{
	double X;
	double Y;
};

struct Circle
{
	_double2 Center;
	double Radius;
};

double Length(_double2 const& Src, _double2 const& Dest)
{
	return sqrt((Dest.X - Src.X) * (Dest.X - Src.X) + (Dest.Y - Src.Y) * (Dest.Y - Src.Y));
}

double ExtentOfCircle(Circle const& Target)
{
	//PI * r * r
	return PI * Target.Radius * Target.Radius;
}

double ExtentOfSector(Circle const& Target, double const& HalfAngle)
{
	//부채꼴의 넓이 = r^2* 각/PI(/2*2) 반각이므로 괄호부분은 생략됨
	return Target.Radius * Target.Radius * HalfAngle;
}


double ExtentOfTriangle(Circle const& Src, double const& Distance, double const& HalfAngle)
{
	//삼각형의 넓이 = 1/2 * sin(사이각) * 양옆의 변 두개의 곱
	//우리는 이 삼각형 넓이의 두배가 필요 하므로 2를 곱한다 1/2*2가 생략
	return  Src.Radius * Distance * sin(HalfAngle);
}

double CalcHalfAngle(double const& SrcRadius, double const& DestRadius, double const& Distance)
{
	//cos(r1부채꼴 각 / 2) = (r1 ^ 2 + d ^ 2 - r2 ^ 2) / (2r1 * d)
	return acos((SrcRadius * SrcRadius + Distance * Distance - DestRadius * DestRadius) / (2 * SrcRadius * Distance));
}

/*
먼저 두원이 떨어져있거나 한쪽이 안에 완전히 포함된 경우
넓이 0 혹은 작은 원의 크기로 반환
둘이 포함되지 않으면서 겹쳐진 경우 계산

두 원의 겹쳐진 두점에 대한 부채꼴넓이 두개를 더한 다음
r1, r2, D(두 점 사이의 거리)가 그리는 삼각형의 삼각형의 넓이 두개만큼의 넓이를 빼준다

부채꼴의 넓이를 구하기 위해 부채꼴의 각을 구한다
원에서 부채꼴의 각은 180도가 넘어갈 수 있으므로 반으로 나누어 삼각함수 공식을 활용한다

거리D를 공유하고 각각 위아래로 r1 r2로 뻗은 삼각형을 상상해보자
여기서 각 원의 부채꼴에 대한 각을 구한다

r1의 부채꼴 각(코사인 법칙) Cos(A) =( b^2 + c^2 - a^2 ) / (2bc) [a는 각A의 마주하는 변이다]
cos(r1부채꼴 각/2) =   (r1^2 + d^2 -r2^2) / (2r1*d)

*/
double Solution(Circle const& Src, Circle const& Dest)
{
	double const Distance = Length(Src.Center, Dest.Center);
	if (Distance >= (Src.Radius + Dest.Radius))
		return 0;
	if (Distance <= abs(Src.Radius - Dest.Radius))
		return Src.Radius > Dest.Radius ? ExtentOfCircle(Dest) : ExtentOfCircle(Src);

	double const SrcHalfAngle = CalcHalfAngle(Src.Radius, Dest.Radius, Distance);
	double const DestHalfAngle = CalcHalfAngle(Dest.Radius, Src.Radius, Distance);

	double const SrcSector = ExtentOfSector(Src, SrcHalfAngle);
	double const DestSector = ExtentOfSector(Dest, DestHalfAngle);
	return SrcSector + DestSector - ExtentOfTriangle(Src, Distance, SrcHalfAngle);
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(3);
	Circle Circles[2]{};

	for (int i = 0; i < 2; i++)
		cin >> Circles[i].Center.X >> Circles[i].Center.Y >> Circles[i].Radius;


	cout << Solution(Circles[0], Circles[1]);

	return 0;
}
