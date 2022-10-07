/*
2580 - 스도쿠

모든 칸이 빈칸인 경우를 생각해보면, (log9)^81 정도가 된다 절대 BFS 방식으로는 해결 불가능
따라서 스도쿠의 게임 룰을 이용하여 일단 끝까지 규칙에 맞춰 수를 채우는 백트래킹 방식으로 풀어나간다
각 칸에 대해 중복되지 않는 수를 찾아 무작정 채우고 다음칸에대해 동일하게 수행한다
채워나가는 수는 실시간으로 각 함수가 공유하며, 함수가 잘못된 수를 채워넣어서 답을 완성할 수 없는 경우,
재귀 함수 종료 전 0을 다시 칠하고 나와서 다음 함수 호출에서 정상 동작할수 있도록 한다.

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

		//0~ 8 까지 돌며 X, Y 시작좌표는 /3으로 결정해주고
		//X가 0~2로 도는 동안 Y가 /3으로 고정된다
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
