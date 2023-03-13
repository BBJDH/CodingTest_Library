/*
 *17276 - 배열 돌리기
 *
 *
 *각 돌릴 배열을 그대로 좌표를 계산해 대입하려하면 어렵다
 *
 *지정 외곽 배열을 기준으로 큐에 삽입하여 원하는 만큼 돌리고,
 *
 *지정위치로부터 다시 출력한다.
 *
 *항상 사이드마다 2개씩 큐에 삽입 또는 출력하는 규칙을 사용하며
 *
 *방향 또한 시계방향으로 고정한다.
 *
 *	-45면 PopAndPush 1회 ....-315면 7회
 *	 45면 PopAndPush 7회 .... 315면 1회
 *
 *위의 규칙을 이용해 큐를 돌려주고 큐를 만들때와 마찬가지로 똑같이 배열에 기록한다.
 *
 *위의 과정을 입력받은 Size/2를 기준으로 반복문안에서 하나씩 줄여가며
 *배열을 모두 돌려준다(CurrentLine이 0인경우는 중앙 배열 하나뿐이므로 회전이 불필요)
 *
 *반복문 탈출 후 돌려진 배열을 출력한다.
 *
 */

#include<iostream>
#include <queue>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

_int2 Direction[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int Board[500][500]{};

//지정 회전 수 0 45 90 135 180 225 270 315 360에 따라 큐를 밀어놓는 함수 작성
void RotateQueue(queue<int>& QueueToRotate, int const Degree)
{
	//-45면 popandpush 1회 ....-315면 7회
	// 45면 popandpush 7회 .... 315면 1회
	int CountOfRotate = 0;
	if (Degree < 0)
	{
		CountOfRotate = (((Degree * -1) % 360) / 45);
	}
	else
	{
		CountOfRotate = (8 - ((Degree % 360) / 45));
	}

	while (CountOfRotate--)
	{
		int const Current = QueueToRotate.front();
		QueueToRotate.pop();
		QueueToRotate.push(Current);
	}

}

//배열을 큐에 집어넣는 함수 작성 시작은 항상 입력받은 N을 2로 나눈것으로 시행 (LineOfSize)
//입력받은 CurrentLine기준 (LineOfSize-CurrentLine ,LineOfSize-CurrentLine)부터 시계방향으로 입력
void MakeQueue(queue<int>& QueueToRotate, int const CurrentLine, int const LineOfSize)
{
	_int2 PosOfBoard = { LineOfSize - CurrentLine ,LineOfSize - CurrentLine };

	for (int i = 0; i < 4; i++)
	{
		int CurrentPushCount = 0;
		while (CurrentPushCount < 2)
		{
			QueueToRotate.push(Board[PosOfBoard.Y][PosOfBoard.X]);
			PosOfBoard.X = PosOfBoard.X + Direction[i].X * CurrentLine;
			PosOfBoard.Y = PosOfBoard.Y + Direction[i].Y * CurrentLine;
			CurrentPushCount++;
		}
	}

}

//큐에서 배열에 기록하는 함수 작성 마찬가지로 입력받은 CurrentLine기준 (LineOfSize-CurrentLine ,LineOfSize-CurrentLine)부터 시계방향으로 입력
void SetBoardFromQueue(queue<int>& RotatedQueue, int const CurrentLine, int const LineOfSize)
{
	_int2 PosOfBoard = { LineOfSize - CurrentLine ,LineOfSize - CurrentLine };

	for (int i = 0; i < 4; i++)
	{
		int CurrentPushCount = 0;
		while (CurrentPushCount < 2)
		{
			Board[PosOfBoard.Y][PosOfBoard.X] = RotatedQueue.front();
			RotatedQueue.pop();
			PosOfBoard.X = PosOfBoard.X + Direction[i].X * CurrentLine;
			PosOfBoard.Y = PosOfBoard.Y + Direction[i].Y * CurrentLine;
			CurrentPushCount++;
		}
	}

}

//위의 함수들을 활용할 Solution 함수 작성
void Solution(queue<int>& QueueToRotate, int const DegreeOfRotate, int const Size)
{
	for (int i = Size / 2; i > 0; i--)
	{
		MakeQueue(QueueToRotate, i, Size / 2);
		RotateQueue(QueueToRotate, DegreeOfRotate);
		SetBoardFromQueue(QueueToRotate, i, Size / 2);
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		int N = 0, Degree = 0;
		queue<int> QueueToRotate{};
		cin >> N >> Degree;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cin >> Board[y][x];
			}
		}
		Solution(QueueToRotate, Degree, N);

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cout << Board[y][x] << " ";
			}
			cout << "\n";
		}
	}


	return 0;
}