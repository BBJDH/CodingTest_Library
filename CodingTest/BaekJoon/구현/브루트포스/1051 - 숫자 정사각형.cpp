/*
 *
 *1051 - ���� ���簢��
 *
 * Min��ǥ�� Max ��ǥ�� �Է¹޾� ���簢������ Ȯ���ϴ� �Լ��� �ۼ���
 *
 * ���Ʈ������ ���� Ž���Ѵ�.
 *
 * �Է� ���� ������ X,Y�� ���� ���� ���� ����� ���簢���� �ִ�ũ���̴�.
 *
 * �ִ�ũ����� 1�� �ٿ����� ��� ��ǥ���� ���簢���� �������� Ȯ���Ѵ�.
 *
 * ū ũ����� ���� ũ��� ����Ž�� �ϹǷ� ù ���簢���� Ž���Ǹ� �ش� ���̸� ��� �� �����Ѵ�.
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