/*
 *14500 - 테트로미노
 *
 *정사각형과 긴 바는 따로 계산하고 나머지 도형들은 가로세로 6칸을 반드시 차지한다
 *
 *따라서 횡으로 2*3 차지하는 배열과
 *종으로 2*3 차지하는 배열을 미리 만들어
 *
 *모든 경우의 수를 기록해 두고
 *
 *브루트 포스로 완전 탐색한다.
 *
 *
 *횡으로 2*3 차지하는 배열
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
 *종으로 2*3 차지하는 배열
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
 * 이후 정사각형과 긴 막대를 따로 탐색한다
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
	{{false,false,true} ,{true,true,true}}, {{true,false,false} ,{true,true,true}}, //여기까지 ㄱ모양
	{{false,true,true} ,{true,true,false}}, {{true,true,false} ,{false,true,true}}, // Z 모양
	{{false,true,false} ,{true,true,true}}, {{true,true,true} ,{false,true,false}}, // ㅗ 모양
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
	{false,true}}, //여기까지 ㄱ모양

	{{true,false},
	{true,true},
	{false,true}},

	{{false,true},
	{true,true},
	{true,false}}, // Z모양

	{{false,true},
	{true,true},
	{false,true}},

	{{true,false},
	{true,true},
	{true,false}}, // ㅗ모양
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
	//오른쪽으로 뻗은 2*3 검사
	for (int y = 0; y <= Max.Y - 2; y++)
	{
		for (int x = 0; x <= Max.X - 3; x++)
		{
			Sum_Tetromino_Right({ x,y });
		}
	}

	//아래로 뻗은 2*3 검사
	for (int y = 0; y <= Max.Y - 3; y++)
	{
		for (int x = 0; x <= Max.X - 2; x++)
		{
			Sum_Tetromino_Up({ x,y });
		}
	}
	//정사각형 검사
	for (int y = 0; y <= Max.Y - 2; y++)
	{
		for (int x = 0; x <= Max.X - 2; x++)
		{
			Sum_Tetromino_Rect({ x,y });
		}
	}
	//직선 검사
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
