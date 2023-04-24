/*
 *1002 - �ͷ�
 *
 *������ �����̴�
 *
 *�� ����� ��ǥ�� �ݰ��� ������ �ν��ϰ�,
 *�� ���� �浹 ������ ����� ����Ѵ�.
 *
 *�� ���� ��ġ�� �ݰ��� ��� ��ġ�Ѵٸ� �浹������ ���Ѵ�� -1
 *
 *�� �������� �Ÿ��� ���ϰ� �Ÿ��� �ο��� �ݰ��� �պ��� �ִٸ� 0
 *�ݴ�� ���ʿ��� ������ ���Ե� ��쵵 ����
 *�� �� ������ �Ÿ��� �� ���� �ݰ��� ���̺��� �۴ٸ� 0�� ��ȯ�Ѵ�.
 *
 *�� ���� ��ġ�� ���� ���� �� �Ÿ��� ���� ���� 1�� ��ȯ
 *
 *�̿��� ���� ��� �� ���� �浹�ϹǷ� 2�� ��ȯ�Ѵ�
 *
 *���� �Լ��� �ۼ��ϰ� �� TestCase�� ���Ͽ� ����Ѵ�.
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
	//������ ��ġ
	if (First.X == Second.X and First.Y == Second.Y and First.R == Second.R)
	{
		return -1;
	}

	double const Distance = sqrt((First.X - Second.X) * (First.X - Second.X)
		+ (First.Y - Second.Y) * (First.Y - Second.Y));

	//�� ���� �ָ� ������ ������ ���� ���� ���
	if (Distance > (First.R + Second.R))
	{
		return 0;
	}
	//�� ������ �ٸ� ���ʿ� ������ ���ԵǾ� ������ ���� ���� ���
	if (Distance < abs(First.R - Second.R))
	{
		return 0;
	}
	//�ȿ��� �� ���� ������ ���
	if (Distance == abs(First.R - Second.R))
	{
		return 1;
	}
	//�ٱ����� �� ���� ������ ���
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