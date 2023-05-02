/*
 * 14499 - �ֻ��� ������
 *
 *�Է� �޴� ��ǥ�谡 (��,��) �� (Y,X) ���� �Է¹޴´�.
 *
 *�ֻ����� �����̴� �κ��� ������ ���� �����Ѵ�
 *
 *int Dice[6]{}
 *0 - �߾�, 1 - ����, 2 - ��, 3 - ��, 4 - ��, 5 - ����
 *
 *�ֻ����� ������ �������� �����δٸ� �׻� ���� �ε��� ������ �������ش�.
 *
 *�̷��� �Ѵٸ� � ȸ���� �͵� ���� �迭���� ��ü�� �ֻ��� �� ���� ���� �����ϴ�.
 *
 *
 *�� �Է¹޴� ������ ���⿡ ���� ���� ��ǥ�� ���� �����ְ�,
 *
 *�ش� ��ǥ�� Map�� ���� �ȿ� ��ȿ�ϴٸ� �ֻ����� �����̰�,
 *0�� ���� ��ü�۾��� 5��(����)��� �۾��� ���ش�.
 *
 *
 *
 *
 *
 *�� ������ ������ ������ �� �а� �״�� �����ϸ� �Ǵ� ��������.
 *
 *(r,c)��ǥ���̱� ������ ��, ���� �Ųٷ� �Է¹޴´�.
 *
 *�Ϻη� �򰥸��� (x,y) �� ������ǥ�� �޴´ٰ� ����� ������ ���縦...
 *
 *
 *
 *���� �̸��� [�ֻ��� ������]�̱� ������ �ֻ����� ���� ������ ��� Map���� �����ؿ��� ������
 *������ ���ִ�. ������ �ݴ�� Map�� �ش� ĭ�� �������� ���۽��Ѿ� �Ѵ�.
 *
 *�ֻ����� �Ʒ����� ��� ����� ����.
 *���� �ֻ����� ���� ĭ�� ��������� �����ϰ�, ĭ�� ���ڰ� �ִٸ� �ֻ����� ���̰� ĭ�� 0�� �ȴ�.
 *
 */

#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

int Map[20][20]{};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,-1}, {0,1} };

// 0 - �߾�, 1 - ����, 2 - ��, 3 - ��, 4 - ��, 5 - �ݴ��� 
int Dice[6]{};

void MoveDice(int const NumOfDirection)
{
	int NextNum = Dice[5];
	if (NumOfDirection == 0)
	{
		//������ ���, ������ ����, 0�� ��������, 1�� 0����
		Dice[5] = Dice[2];
		Dice[2] = Dice[0];
		Dice[0] = Dice[1];
		Dice[1] = NextNum;
		return;
	}
	if (NumOfDirection == 1)
	{
		//������ ���, ������ ����, 0�� ��������, ������ 0����

		Dice[5] = Dice[1];
		Dice[1] = Dice[0];
		Dice[0] = Dice[2];
		Dice[2] = NextNum;
		return;

	}
	if (NumOfDirection == 2)
	{
		//������ ���, ������ ����, ���� 0��, 0�� ���� ����
		Dice[5] = Dice[4];
		Dice[4] = Dice[0];
		Dice[0] = Dice[3];
		Dice[3] = NextNum;
		return;

	}
	if (NumOfDirection == 3)
	{
		//������ ���, ������ ����, �Ͽ� 0��, 0�� ���� ����
		Dice[5] = Dice[3];
		Dice[3] = Dice[0];
		Dice[0] = Dice[4];
		Dice[4] = NextNum;
		return;

	}
	//�ֻ��� ȸ�� �Ϸ�
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	_int2 Size{}, Pos{};
	int NumOfMove = 0;
	cin >> Size.Y >> Size.X >> Pos.Y >> Pos.X >> NumOfMove;
	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			cin >> Map[y][x];
		}
	}
	while (NumOfMove--)
	{
		int NumOfDirection = 0;
		cin >> NumOfDirection;
		NumOfDirection--;
		if (Pos.X + Direction[NumOfDirection].X >= 0 and Pos.X + Direction[NumOfDirection].X < Size.X
			and Pos.Y + Direction[NumOfDirection].Y >= 0 and Pos.Y + Direction[NumOfDirection].Y < Size.Y)
		{
			Pos.X += Direction[NumOfDirection].X;
			Pos.Y += Direction[NumOfDirection].Y;

			MoveDice(NumOfDirection);

			if (Map[Pos.Y][Pos.X] == 0)
			{
				//������ Map�� �ڸ��� ���ڰ� 0�̸� �ֻ������� ����
				Map[Pos.Y][Pos.X] = Dice[0];
			}
			else
			{
				//������ Map�� �ڸ��� ���ڰ� �ִٸ� �ֻ����� �Űܰ��� Map�� 0
				Dice[0] = Map[Pos.Y][Pos.X];
				Map[Pos.Y][Pos.X] = 0;
			}
			cout << Dice[5] << "\n";
		}
	}

	return 0;
}