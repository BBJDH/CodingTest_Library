/*
 *
 *1051 - 숫자 정사각형
 *
 * Min좌표와 Max 좌표를 입력받아 정사각형인지 확인하는 함수를 작성해
 *
 * 브루트포스로 완전 탐색한다.
 *
 * 입력 받은 사이즈 X,Y에 대해 둘중 작은 사이즈가 정사각형의 최대크기이다.
 *
 * 최대크기부터 1씩 줄여가며 모든 좌표에서 정사각형이 가능한지 확인한다.
 *
 * 큰 크기부터 작은 크기로 완전탐색 하므로 첫 정사각형이 탐색되면 해당 넓이를 출력 후 종료한다.
 *
 */

#include<iostream>
#include <string>

using namespace std;


struct _int2
{
	int X;
	int Y;
};

_int2 Size{};

int Map[50][50]{};

bool IsSquare(_int2 const& Min, _int2 const& Max)
{
	if (Map[Min.Y][Min.X] == Map[Min.Y][Max.X] and
		Map[Min.Y][Min.X] == Map[Max.Y][Min.X] and
		Map[Min.Y][Min.X] == Map[Max.Y][Max.X])
	{
		return true;
	}
	return false;
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> Size.Y >> Size.X;

	for (int y = 0; y < Size.Y; y++)
	{
		string InputStr{};
		cin >> InputStr;
		for (int x = 0; x < InputStr.size(); x++)
		{
			Map[y][x] = InputStr[x] - '0';
		}
	}
	int SquareSize = min(Size.X, Size.Y);
	while (true)
	{
		if (SquareSize == 1)
		{
			cout << 1;
			break;
		}
		for (int y = 0; y <= Size.Y - SquareSize; y++)
		{
			for (int x = 0; x <= Size.X - SquareSize; x++)
			{
				if (IsSquare({ x,y }, { x + SquareSize - 1,y + SquareSize - 1 }))
				{
					cout << SquareSize * SquareSize;
					return 0;
				}
			}
		}

		SquareSize--;
	}

	return 0;
}