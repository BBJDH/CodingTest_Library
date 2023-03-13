/*
 *17276 - �迭 ������
 *
 *
 *�� ���� �迭�� �״�� ��ǥ�� ����� �����Ϸ��ϸ� ��ƴ�
 *
 *���� �ܰ� �迭�� �������� ť�� �����Ͽ� ���ϴ� ��ŭ ������,
 *
 *������ġ�κ��� �ٽ� ����Ѵ�.
 *
 *�׻� ���̵帶�� 2���� ť�� ���� �Ǵ� ����ϴ� ��Ģ�� ����ϸ�
 *
 *���� ���� �ð�������� �����Ѵ�.
 *
 *	-45�� PopAndPush 1ȸ ....-315�� 7ȸ
 *	 45�� PopAndPush 7ȸ .... 315�� 1ȸ
 *
 *���� ��Ģ�� �̿��� ť�� �����ְ� ť�� ���鶧�� ���������� �Ȱ��� �迭�� ����Ѵ�.
 *
 *���� ������ �Է¹��� Size/2�� �������� �ݺ����ȿ��� �ϳ��� �ٿ�����
 *�迭�� ��� �����ش�(CurrentLine�� 0�ΰ��� �߾� �迭 �ϳ����̹Ƿ� ȸ���� ���ʿ�)
 *
 *�ݺ��� Ż�� �� ������ �迭�� ����Ѵ�.
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

//���� ȸ�� �� 0 45 90 135 180 225 270 315 360�� ���� ť�� �о���� �Լ� �ۼ�
void RotateQueue(queue<int>& QueueToRotate, int const Degree)
{
	//-45�� popandpush 1ȸ ....-315�� 7ȸ
	// 45�� popandpush 7ȸ .... 315�� 1ȸ
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

//�迭�� ť�� ����ִ� �Լ� �ۼ� ������ �׻� �Է¹��� N�� 2�� ���������� ���� (LineOfSize)
//�Է¹��� CurrentLine���� (LineOfSize-CurrentLine ,LineOfSize-CurrentLine)���� �ð�������� �Է�
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

//ť���� �迭�� ����ϴ� �Լ� �ۼ� ���������� �Է¹��� CurrentLine���� (LineOfSize-CurrentLine ,LineOfSize-CurrentLine)���� �ð�������� �Է�
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

//���� �Լ����� Ȱ���� Solution �Լ� �ۼ�
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