/*
2239 - ������

�� 0���� �ڸ��� ��ȣ�� �ϳ��� ���� �ִ��� ���ʷ� Ȯ���� ������ ���� �����̴�
��Ʈ��ŷ���� �ݺ����� ���� ȣ���Ѵ�
�� �Լ��ȿ��� ���� �迭�� �湮 ������ ���ڸ� �ѹ��� ����Ѵ�

*/

#include<iostream>
#include<vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

vector<_int2> InputList{};
int Sudoku[9][9]{};

bool Ended = false;

void BackTrack(int const Index)
{
	if (Index == InputList.size())
	{
		Ended = true;
		return;
	}
	bool NumChecked[10]{};
	_int2 Current = { InputList[Index].X,InputList[Index].Y };
	_int2 SectionStart = { (Current.X / 3) * 3,(Current.Y / 3) * 3 };

	for (int i = 0; i < 9; i++)
	{
		int X = SectionStart.X + i % 3;
		int Y = SectionStart.Y + i / 3;
		NumChecked[Sudoku[Y][X]] = true;
		NumChecked[Sudoku[Current.Y][i]] = true;
		NumChecked[Sudoku[i][Current.X]] = true;

	}

	for (int i = 1; i <= 9; i++)
	{
		if (NumChecked[i] == false)
		{
			Sudoku[Current.Y][Current.X] = i;

			BackTrack(Index + 1);
			if (Ended)
				return;
			Sudoku[Current.Y][Current.X] = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int y = 0; y < 9; y++)
	{
		int InputNum = 0;
		cin >> InputNum;
		for (int x = 8; x >= 0; x--)
		{
			Sudoku[y][x] = InputNum % 10;
			InputNum /= 10;

		}
	}
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (Sudoku[y][x] == 0)
				InputList.push_back({ x,y });
		}
	}

	BackTrack(0);

	//���
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cout << Sudoku[y][x];
		}
		cout << "\n";
	}

	return 0;
}
