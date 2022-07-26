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
���� ������ �������� ��ġ�ߴ��� Ȯ��
�������� ������ ��ġ�Ѵٸ�, -1 ���, ����
��1 ~ ��3, ��1 ~��2

�� ���� ���̸� ����

���� ���� ���� �ΰ��� ���� ū ���� �ΰ��� ���ؼ� �ι辿 �ϸ� ��
*/

bool CheckSlopeEquel()
{
	//double Slop1 = (Vertices[2].Y - Vertices[0].Y) / (Vertices[2].X - Vertices[0].X);
	//double Slop2 = (Vertices[2].Y - Vertices[1].Y) / (Vertices[2].X - Vertices[1].X);

	//if (abs(Slop2 - Slop1) < 0.0000000001)
	//	return true;
	//else
	//	return false;
	//EPSILON�� �ִ� ����� ����ó���ȴ�
	//return abs(Slop2) == abs(Slop1);	//����

	//Ȥ�� CCW�˰����� ����Ѵ�
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
