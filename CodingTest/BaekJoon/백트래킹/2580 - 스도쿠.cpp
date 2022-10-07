/*
2580 - ������

��� ĭ�� ��ĭ�� ��츦 �����غ���, (log9)^81 ������ �ȴ� ���� BFS ������δ� �ذ� �Ұ���
���� �������� ���� ���� �̿��Ͽ� �ϴ� ������ ��Ģ�� ���� ���� ä��� ��Ʈ��ŷ ������� Ǯ�����
�� ĭ�� ���� �ߺ����� �ʴ� ���� ã�� ������ ä��� ����ĭ������ �����ϰ� �����Ѵ�
ä�������� ���� �ǽð����� �� �Լ��� �����ϸ�, �Լ��� �߸��� ���� ä���־ ���� �ϼ��� �� ���� ���,
��� �Լ� ���� �� 0�� �ٽ� ĥ�ϰ� ���ͼ� ���� �Լ� ȣ�⿡�� ���� �����Ҽ� �ֵ��� �Ѵ�.

*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

vector<_int2> ToFindNums{};


int Sudoku[9][9]{};

void PrintSudoku()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
			cout << Sudoku[y][x] << " ";
		cout << "\n";
	}
}

bool CalcNum(int CurrentIndex = 0)
{
	if (CurrentIndex == static_cast<int>(ToFindNums.size()))
		return true;
	bool NumCheck[10]{};
	_int2 const CurrentPos = ToFindNums[CurrentIndex];

	for (int i = 0; i < 9; i++)
	{
		if (Sudoku[CurrentPos.Y][i] != 0)
			NumCheck[Sudoku[CurrentPos.Y][i]] = true;
		if (Sudoku[i][CurrentPos.X] != 0)
			NumCheck[Sudoku[i][CurrentPos.X]] = true;

		//0~ 8 ���� ���� X, Y ������ǥ�� /3���� �������ְ�
		//X�� 0~2�� ���� ���� Y�� /3���� �����ȴ�
		NumCheck[Sudoku[(CurrentPos.Y / 3) * 3 + i / 3][(CurrentPos.X / 3) * 3 + i % 3]] = true;
	}

	for (int i = 1; i < 10; i++)
	{
		if (NumCheck[i] == false)
		{
			Sudoku[CurrentPos.Y][CurrentPos.X] = i;
			if (CalcNum(CurrentIndex + 1))
				return true;
		}
	}
	Sudoku[CurrentPos.Y][CurrentPos.X] = 0;
	return false;
}



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			int inputNum = 0;
			cin >> inputNum;
			Sudoku[y][x] = inputNum;
			if (inputNum == 0)
				ToFindNums.push_back({ x,y });
		}
	}
	CalcNum(0);
	PrintSudoku();


	return 0;
}
