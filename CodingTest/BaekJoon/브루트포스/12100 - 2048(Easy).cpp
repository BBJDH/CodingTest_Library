/*

12100 - 2048

�׳� �ִ� �״�� 5�� ���� ��������
��Ʈ��ŷ���� 4*4*4*4*4�� �� �غ���

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
				//���� Ž��
				searchY++;
				continue;
			}
			else if (currentNum != Board[searchY][x])
			{
				//�ٸ� �� �߰�, ó���߰��Ѱ��̶�� currentNum�� ������Ʈ

				if (currentNum != 0)
				{
					//���� ���� �ִµ� �ٸ� ����� setPos�� ���� �� currentNum�� ������ ������ġ�� Pos �̵�
					//currentNum ������Ʈ
					Board[setPos.Y][setPos.X] = currentNum;
					setPos.Y++;
				}
				currentNum = Board[searchY][x];
				Board[searchY][x] = 0;
			}
			else if (currentNum == Board[searchY][x])
			{
				//���� ���Ƹ� currentPos�� ���� ���� �ι�� ���� Pos �������� �ű�
				//ã�� ���� �ִ� ���� 0���� ������Ʈ
				//���⼭ ������ �ִ���� ��
				Board[setPos.Y][setPos.X] = currentNum * 2;
				Board[searchY][x] = 0;
				//�ٽ� ���ο� ���� ã�� �� �ְ� 0���� �ٲ���
				currentNum = 0;

				MaxNum = max(MaxNum, Board[setPos.Y][setPos.X]);
				setPos.Y++;
			}

			searchY++;
		}
		//������ ������ ���� Pos�� ����
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
				//���� Ž��
				searchY--;
				continue;
			}
			else if (currentNum != Board[searchY][x])
			{

				if (currentNum != 0)
				{
					//���� ���� �ִµ� �ٸ� ����� setPos�� ���� �� currentNum�� ������ ������ġ�� Pos �̵�
					//currentNum ������Ʈ
					Board[setPos.Y][setPos.X] = currentNum;
					setPos.Y--;
				}
				// currentNum�� ���ι߰��� ���� ������Ʈ
				currentNum = Board[searchY][x];
				Board[searchY][x] = 0;
			}
			else if (currentNum == Board[searchY][x])
			{
				//���� ���Ƹ� currentPos�� ���� ���� �ι�� ���� Pos �������� �ű�
				//ã�� ���� �־��� ���� 0���� ������Ʈ
				//���⼭ ������ �ִ���� ��
				Board[setPos.Y][setPos.X] = currentNum * 2;
				Board[searchY][x] = 0;
				//�ٽ� ���ο� ���� ã�� �� �ְ� 0���� �ٲ���
				currentNum = 0;

				MaxNum = max(MaxNum, Board[setPos.Y][setPos.X]);
				setPos.Y--;
			}

			searchY--;
		}
		//������ ������ ���� Pos�� ����
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
				//���� Ž��
				searchX++;
				continue;
			}
			else if (currentNum != Board[y][searchX])
			{

				if (currentNum != 0)
				{
					//���� ���� �ִµ� �ٸ� ����� setPos�� ���� �� currentNum�� ������ ������ġ�� Pos �̵�
					//currentNum ������Ʈ
					Board[setPos.Y][setPos.X] = currentNum;
					setPos.X++;
				}
				// currentNum�� ���ι߰��� ���� ������Ʈ
				currentNum = Board[y][searchX];
				Board[y][searchX] = 0;
			}
			else if (currentNum == Board[y][searchX])
			{
				//���� ���ٸ� currentPos�� ���� ���� �ι�� ���� Pos �������� �ű�
				Board[setPos.Y][setPos.X] = currentNum * 2;
				//ã�� ���� �־��� ���� 0���� ������Ʈ
				Board[y][searchX] = 0;
				//�ٽ� ���ο� ���� ã�� �� �ְ� 0���� �ٲ���
				currentNum = 0;

				//���⼭ ������ �ִ���� ��
				MaxNum = max(MaxNum, Board[setPos.Y][setPos.X]);
				setPos.X++;
			}

			searchX++;
		}
		//������ ������ ���� Pos�� ����
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
				//���� Ž��
				searchX--;
				continue;
			}
			else if (currentNum != Board[y][searchX])
			{

				if (currentNum != 0)
				{
					//���� ���� �ִµ� �ٸ� ����� setPos�� ���� �� currentNum�� ������ ������ġ�� Pos �̵�
					//currentNum ������Ʈ
					Board[setPos.Y][setPos.X] = currentNum;
					setPos.X--;
				}
				// currentNum�� ���ι߰��� ���� ������Ʈ
				currentNum = Board[y][searchX];
				Board[y][searchX] = 0;
			}
			else if (currentNum == Board[y][searchX])
			{
				//���� ���ٸ� currentPos�� ���� ���� �ι�� ���� Pos �������� �ű�
				Board[setPos.Y][setPos.X] = currentNum * 2;
				//ã�� ���� �־��� ���� 0���� ������Ʈ
				Board[y][searchX] = 0;
				//�ٽ� ���ο� ���� ã�� �� �ְ� 0���� �ٲ���
				currentNum = 0;

				//���⼭ ������ �ִ���� ��
				MaxNum = max(MaxNum, Board[setPos.Y][setPos.X]);
				setPos.X--;
			}

			searchX--;
		}
		//������ ������ ���� Pos�� ����
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