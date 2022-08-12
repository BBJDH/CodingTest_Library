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
	//��ä���� ���� = r^2* ��/PI(/2*2) �ݰ��̹Ƿ� ��ȣ�κ��� ������
	return Target.Radius * Target.Radius * HalfAngle;
}


double ExtentOfTriangle(Circle const& Src, double const& Distance, double const& HalfAngle)
{
	//�ﰢ���� ���� = 1/2 * sin(���̰�) * �翷�� �� �ΰ��� ��
	//�츮�� �� �ﰢ�� ������ �ι谡 �ʿ� �ϹǷ� 2�� ���Ѵ� 1/2*2�� ����
	return  Src.Radius * Distance * sin(HalfAngle);
}

double CalcHalfAngle(double const& SrcRadius, double const& DestRadius, double const& Distance)
{
	//cos(r1��ä�� �� / 2) = (r1 ^ 2 + d ^ 2 - r2 ^ 2) / (2r1 * d)
	return acos((SrcRadius * SrcRadius + Distance * Distance - DestRadius * DestRadius) / (2 * SrcRadius * Distance));
}

/*
���� �ο��� �������ְų� ������ �ȿ� ������ ���Ե� ���
���� 0 Ȥ�� ���� ���� ũ��� ��ȯ
���� ���Ե��� �����鼭 ������ ��� ���

�� ���� ������ ������ ���� ��ä�ó��� �ΰ��� ���� ����
r1, r2, D(�� �� ������ �Ÿ�)�� �׸��� �ﰢ���� �ﰢ���� ���� �ΰ���ŭ�� ���̸� ���ش�

��ä���� ���̸� ���ϱ� ���� ��ä���� ���� ���Ѵ�
������ ��ä���� ���� 180���� �Ѿ �� �����Ƿ� ������ ������ �ﰢ�Լ� ������ Ȱ���Ѵ�

�Ÿ�D�� �����ϰ� ���� ���Ʒ��� r1 r2�� ���� �ﰢ���� ����غ���
���⼭ �� ���� ��ä�ÿ� ���� ���� ���Ѵ�

r1�� ��ä�� ��(�ڻ��� ��Ģ) Cos(A) =( b^2 + c^2 - a^2 ) / (2bc) [a�� ��A�� �����ϴ� ���̴�]
cos(r1��ä�� ��/2) =   (r1^2 + d^2 -r2^2) / (2r1*d)

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
