/*
 *14500 - ��Ʈ�ι̳�
 *
 *���簢���� �� �ٴ� ���� ����ϰ� ������ �������� ���μ��� 6ĭ�� �ݵ�� �����Ѵ�
 *
 *���� Ⱦ���� 2*3 �����ϴ� �迭��
 *������ 2*3 �����ϴ� �迭�� �̸� �����
 *
 *��� ����� ���� ����� �ΰ�
 *
 *���Ʈ ������ ���� Ž���Ѵ�.
 *
 *
 *Ⱦ���� 2*3 �����ϴ� �迭
 *
 * *** ***   * *
 *   * *   *** ***
 *
 *  ** **
 * **   **
 *
 *  *  ***
 * ***  *
 *
 *������ 2*3 �����ϴ� �迭
 *
 * *   * *   *
 * *   * ** **
 * ** **  * *
 *
 * ** **  * *
 * *   * ** **
 * *   *  * *
 *
 *
 * ���� ���簢���� �� ���븦 ���� Ž���Ѵ�
 *
 */


#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

bool Tetromino_Right[8][2][3] =
{
	{{true,true,true},{false,false,true}}, {{true,true,true},{true,false,false}},
	{{false,false,true} ,{true,true,true}}, {{true,false,false} ,{true,true,true}}, //������� �����
	{{false,true,true} ,{true,true,false}}, {{true,true,false} ,{false,true,true}}, // Z ���
	{{false,true,false} ,{true,true,true}}, {{true,true,true} ,{false,true,false}}, // �� ���
};

bool Tetromino_Up[8][3][2] =
{
	{{true,false},
	{true,false},
	{true,true}},

	{{false,true},
	{false,true},
	{true,true}},

	{{true,true},
	{true,false},
	{true,false}},

	{{true,true},
	{false,true},
	{false,true}}, //������� �����

	{{true,false},
	{true,true},
	{false,true}},

	{{false,true},
	{true,true},
	{true,false}}, // Z���

	{{false,true},
	{true,true},
	{false,true}},

	{{true,false},
	{true,true},
	{true,false}}, // �Ǹ��
};

int Map[1000][1000]{};
_int2 Max{};
int MaxSum = 0;

void Sum_Tetromino_Right(_int2 const& Pos)
{
	for (int elem = 0; elem < 8; elem++)
	{
		int sum = 0;

		for (int y = 0; y < 2; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (Tetromino_Right[elem][y][x] == true)
				{
					sum += Map[Pos.Y + y][Pos.X + x];
				}
			}
		}
		MaxSum = max(MaxSum, sum);
	}
}

void Sum_Tetromino_Up(_int2 const& Pos)
{
	for (int elem = 0; elem < 8; elem++)
	{
		int sum = 0;

		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				if (Tetromino_Up[elem][y][x] == true)
				{
					sum += Map[Pos.Y + y][Pos.X + x];
				}
			}
		}
		MaxSum = max(MaxSum, sum);
	}
}

void Sum_Tetromino_Rect(_int2 const& Pos)
{
	int sum = 0;

	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			sum += Map[Pos.Y + y][Pos.X + x];
		}
	}
	MaxSum = max(MaxSum, sum);
}

void Sum_Tetromino_Straight_Down(_int2 const& Pos)
{
	int sum = 0;

	for (int y = 0; y < 4; y++)
	{
		sum += Map[Pos.Y + y][Pos.X];
	}
	MaxSum = max(MaxSum, sum);
}

void Sum_Tetromino_Straight_Right(_int2 const& Pos)
{
	int sum = 0;
	for (int x = 0; x < 4; x++)
	{
		sum += Map[Pos.Y][Pos.X + x];
	}
	MaxSum = max(MaxSum, sum);
}

void Solution()
{
	//���������� ���� 2*3 �˻�
	for (int y = 0; y <= Max.Y - 2; y++)
	{
		for (int x = 0; x <= Max.X - 3; x++)
		{
			Sum_Tetromino_Right({ x,y });
		}
	}

	//�Ʒ��� ���� 2*3 �˻�
	for (int y = 0; y <= Max.Y - 3; y++)
	{
		for (int x = 0; x <= Max.X - 2; x++)
		{
			Sum_Tetromino_Up({ x,y });
		}
	}
	//���簢�� �˻�
	for (int y = 0; y <= Max.Y - 2; y++)
	{
		for (int x = 0; x <= Max.X - 2; x++)
		{
			Sum_Tetromino_Rect({ x,y });
		}
	}
	//���� �˻�
	for (int y = 0; y <= Max.Y; y++)
	{
		for (int x = 0; x <= Max.X - 4; x++)
		{
			Sum_Tetromino_Straight_Right({ x,y });
		}
	}
	for (int y = 0; y <= Max.Y - 4; y++)
	{
		for (int x = 0; x <= Max.X; x++)
		{
			Sum_Tetromino_Straight_Down({ x,y });
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Max.Y >> Max.X;

	for (int y = 0; y < Max.Y; y++)
	{
		for (int x = 0; x < Max.X; x++)
		{
			cin >> Map[y][x];
		}
	}
	Solution();
	cout << MaxSum;
	return 0;
}
