#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct _double2
{
	double X;
	double Y;
};

_double2 Vertices[3];

void Input_Vertices()
{
	for (int i = 0; i < 3; i++)
		cin >> Vertices[i].X >> Vertices[i].Y;
}

/*
먼저 점들이 일직선상에 위치했는지 확인
일직선상에 세점이 위치한다면, -1 출력, 종료
점1 ~ 점3, 점1 ~점2

각 점별 길이를 구함

가장 작은 길이 두개랑 가장 큰 길이 두개만 구해서 두배씩 하면 됨
*/

bool CheckSlopeEquel()
{
	//double Slop1 = (Vertices[2].Y - Vertices[0].Y) / (Vertices[2].X - Vertices[0].X);
	//double Slop2 = (Vertices[2].Y - Vertices[1].Y) / (Vertices[2].X - Vertices[1].X);

	//if (abs(Slop2 - Slop1) < 0.0000000001)
	//	return true;
	//else
	//	return false;
	//EPSILON을 주는 방식은 오답처리된다
	//return abs(Slop2) == abs(Slop1);	//정답

	//혹은 CCW알고리즘을 사용한다
	int CCW = (Vertices[0].X * Vertices[1].Y + Vertices[1].X * Vertices[2].Y + Vertices[2].X * Vertices[0].Y)
		- (Vertices[1].X * Vertices[0].Y + Vertices[2].X * Vertices[1].Y + Vertices[0].X * Vertices[2].Y);
	if (CCW == 0)
		return true;
	return false;

}

double CalcLength(_double2 const& Start, _double2 const& Dest)
{
	return sqrt((Dest.X - Start.X) * (Dest.X - Start.X) + (Dest.Y - Start.Y) * (Dest.Y - Start.Y));
}

double CalcMinMax()
{
	double LengthArry[3];
	for (int i = 0; i < 3; i++)
	{
		if (i == 2)
		{
			LengthArry[i] = CalcLength(Vertices[i], Vertices[0]);
			break;
		}
		LengthArry[i] = CalcLength(Vertices[i], Vertices[i + 1]);
	}
	sort(LengthArry, LengthArry + 3);


	return LengthArry[2] * 2 - LengthArry[0] * 2;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.precision(16);
	Input_Vertices();

	if (CheckSlopeEquel())
	{
		cout << -1;
		return 0;
	}
	cout << CalcMinMax();
	return 0;
}
