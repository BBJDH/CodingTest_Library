/*

12100 - 2048

그냥 있는 그대로 5번 판을 돌려보자
백트래킹으로 4*4*4*4*4를 다 해본다

 */


#include <iostream>
#include <vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};


int Size = 0;
int MaxNum = 0;
void Solution(vector<vector<int>> Board, int Count);
void Up(vector<vector<int>> Board, int Count)
{
	for (int x = 0; x < Size; x++)
	{
		int searchY = 0;
		int currentNum = 0;

		_int2 setPos{ x,searchY };
		while (searchY < Size)
		{
			if (Board[searchY][x] == 0)
			{
				//다음 탐색
				searchY++;
				continue;
			}
			else if (currentNum != Board[searchY][x])
			{
				//다른 수 발견, 처음발견한것이라면 currentNum을 업데이트

				if (currentNum != 0)
				{
					//기존 수가 있는데 다른 수라면 setPos에 기존 수 currentNum을 저장후 다음위치로 Pos 이동
					//currentNum 업데이트
					Board[setPos.Y][setPos.X] = currentNum;
					setPos.Y++;
				}
				currentNum = Board[searchY][x];
				Board[searchY][x] = 0;
			}
			else if (currentNum == Board[searchY][x])
			{
				//수가 같아면 currentPos에 지정 수의 두배로 저장 Pos 다음으로 옮김
				//찾은 수가 있는 곳은 0으로 업데이트
				//여기서 합쳐진 최대수를 비교
				Board[setPos.Y][setPos.X] = currentNum * 2;
				Board[searchY][x] = 0;
				//다시 새로운 수를 찾을 수 있게 0으로 바꿔줌
				currentNum = 0;

				MaxNum = max(MaxNum, Board[setPos.Y][setPos.X]);
				setPos.Y++;
			}

			searchY++;
		}
		//마지막 보존된 수를 Pos에 저장
		Board[setPos.Y][setPos.X] = currentNum;
	}
	Solution(Board, Count + 1);
}
void Down(vector<vector<int>> Board, int Count)
{
	for (int x = 0; x < Size; x++)
	{
		int searchY = Size - 1;
		int currentNum = 0;

		_int2 setPos{ x,searchY };
		while (searchY >= 0)
		{
			if (Board[searchY][x] == 0)
			{
				//다음 탐색
				searchY--;
				continue;
			}
			else if (currentNum != Board[searchY][x])
			{

				if (currentNum != 0)
				{
					//기존 수가 있는데 다른 수라면 setPos에 기존 수 currentNum을 저장후 다음위치로 Pos 이동
					//currentNum 업데이트
					Board[setPos.Y][setPos.X] = currentNum;
					setPos.Y--;
				}
				// currentNum을 새로발견한 수로 업데이트
				currentNum = Board[searchY][x];
				Board[searchY][x] = 0;
			}
			else if (currentNum == Board[searchY][x])
			{
				//수가 같아면 currentPos에 지정 수의 두배로 저장 Pos 다음으로 옮김
				//찾은 수가 있었던 곳은 0으로 업데이트
				//여기서 합쳐진 최대수를 비교
				Board[setPos.Y][setPos.X] = currentNum * 2;
				Board[searchY][x] = 0;
				//다시 새로운 수를 찾을 수 있게 0으로 바꿔줌
				currentNum = 0;

				MaxNum = max(MaxNum, Board[setPos.Y][setPos.X]);
				setPos.Y--;
			}

			searchY--;
		}
		//마지막 보존된 수를 Pos에 저장
		Board[setPos.Y][setPos.X] = currentNum;
	}
	Solution(Board, Count + 1);

}
void Left(vector<vector<int>> Board, int Count)
{
	for (int y = 0; y < Size; y++)
	{
		int searchX = 0;
		int currentNum = 0;

		_int2 setPos{ searchX,y };
		while (searchX < Size)
		{
			if (Board[y][searchX] == 0)
			{
				//다음 탐색
				searchX++;
				continue;
			}
			else if (currentNum != Board[y][searchX])
			{

				if (currentNum != 0)
				{
					//기존 수가 있는데 다른 수라면 setPos에 기존 수 currentNum을 저장후 다음위치로 Pos 이동
					//currentNum 업데이트
					Board[setPos.Y][setPos.X] = currentNum;
					setPos.X++;
				}
				// currentNum을 새로발견한 수로 업데이트
				currentNum = Board[y][searchX];
				Board[y][searchX] = 0;
			}
			else if (currentNum == Board[y][searchX])
			{
				//수가 같다면 currentPos에 지정 수의 두배로 저장 Pos 다음으로 옮김
				Board[setPos.Y][setPos.X] = currentNum * 2;
				//찾은 수가 있었던 곳은 0으로 업데이트
				Board[y][searchX] = 0;
				//다시 새로운 수를 찾을 수 있게 0으로 바꿔줌
				currentNum = 0;

				//여기서 합쳐진 최대수를 비교
				MaxNum = max(MaxNum, Board[setPos.Y][setPos.X]);
				setPos.X++;
			}

			searchX++;
		}
		//마지막 보존된 수를 Pos에 저장
		Board[setPos.Y][setPos.X] = currentNum;
	}
	Solution(Board, Count + 1);

}
void Right(vector<vector<int>> Board, int Count)
{
	for (int y = 0; y < Size; y++)
	{
		int searchX = Size - 1;
		int currentNum = 0;

		_int2 setPos{ searchX,y };
		while (searchX >= 0)
		{
			if (Board[y][searchX] == 0)
			{
				//다음 탐색
				searchX--;
				continue;
			}
			else if (currentNum != Board[y][searchX])
			{

				if (currentNum != 0)
				{
					//기존 수가 있는데 다른 수라면 setPos에 기존 수 currentNum을 저장후 다음위치로 Pos 이동
					//currentNum 업데이트
					Board[setPos.Y][setPos.X] = currentNum;
					setPos.X--;
				}
				// currentNum을 새로발견한 수로 업데이트
				currentNum = Board[y][searchX];
				Board[y][searchX] = 0;
			}
			else if (currentNum == Board[y][searchX])
			{
				//수가 같다면 currentPos에 지정 수의 두배로 저장 Pos 다음으로 옮김
				Board[setPos.Y][setPos.X] = currentNum * 2;
				//찾은 수가 있었던 곳은 0으로 업데이트
				Board[y][searchX] = 0;
				//다시 새로운 수를 찾을 수 있게 0으로 바꿔줌
				currentNum = 0;

				//여기서 합쳐진 최대수를 비교
				MaxNum = max(MaxNum, Board[setPos.Y][setPos.X]);
				setPos.X--;
			}

			searchX--;
		}
		//마지막 보존된 수를 Pos에 저장
		Board[setPos.Y][setPos.X] = currentNum;

	}
	Solution(Board, Count + 1);

}

void Solution(vector<vector<int>> Board, int Count)
{
	if (Count == 5)
		return;
	Up(Board, Count);
	Down(Board, Count);
	Right(Board, Count);
	Left(Board, Count);

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<vector<int>> Board{};
	cin >> Size;

	Board.resize(Size);
	for (int i = 0; i < Size; i++)
		Board[i].resize(Size);

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			int inputNum = 0;
			cin >> inputNum;
			MaxNum = max(MaxNum, inputNum);
			Board[y][x] = inputNum;
		}
	}
	Solution(Board, 0);
	cout << MaxNum;
	return 0;
}