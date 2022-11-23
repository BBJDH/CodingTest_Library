/*
 *N-Queen - 9663
 *
 *���� ���� �����밢 �޴밢 �湮�� ����Ѵ�
 *
 *������� 3,5 ���� ���� ������ �����Ѵٸ�
 *X�迭�� 3 �湮 ó���� �Ǿ��ִ���(�� X�� 3�� ���ο� ���� �Ѱ��� �ִ���, �湮�迭 ũ�� 15)
 *Y�迭�� 5 �湮 ó���� �Ǿ��ִ���(�� Y�� 5�� ���ο� ���� �Ѱ��� �ִ���, �湮�迭 ũ�� 15)
 *
 *�����밢�� ��� XY�� ���� �������� �̿��Ͽ� ũ�� 30 �迭  +14(0,14), -14(14,0) => 1 ~ 29
 *�� �밢�� XY�� ���� ������ �̿�, �迭 30ũ��(���� ���������� 29�������� �׳� 30 0~ 28)
 *
 *
 *��� �����ϰ� �õ��غô��� 12���� �ð��ʰ��� ���
 *�����غ��� ������ ���྿ ������ �湮�ϸ� ��������� �湮�õ��� ������ ���̹Ƿ�
 *YVisit�� ���� �ʿ䰡 ����(�̹湮���°� Ȯ���̴�)
 * Y�� �Ѱ��� �Ѱܰ��� �ش� ���� XY�� ���� �湮�� �˻��Ѵ�
 */

#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

bool XVisit[15]{};
bool RightDiagonalVisit[30]{};
bool LeftDiagonalVisit[30]{};
int Size = 0;
int Count = 0;
void BackTracking(int const StartY);
void Visit(_int2 const& Pos)
{
	int const rightDiagonalIndex = Pos.Y - Pos.X + 15;
	int const leftDiagonalIndex = Pos.Y + Pos.X;
	XVisit[Pos.X] = true;
	RightDiagonalVisit[rightDiagonalIndex] = true;
	LeftDiagonalVisit[leftDiagonalIndex] = true;

}
void Exit(_int2 const& Pos)
{
	int const rightDiagonalIndex = Pos.Y - Pos.X + 15;
	int const leftDiagonalIndex = Pos.Y + Pos.X;
	XVisit[Pos.X] = false;
	RightDiagonalVisit[rightDiagonalIndex] = false;
	LeftDiagonalVisit[leftDiagonalIndex] = false;
}

void BackTracking(int const StartY, int QueenCount)
{

	if (StartY >= Size)
		return;

	for (int x = 0; x < Size; x++)
	{
		int rightDiagonalIndex = StartY - x + 15;
		int leftDiagonalIndex = StartY + x;

		if (XVisit[x] == false and RightDiagonalVisit[rightDiagonalIndex] == false and LeftDiagonalVisit[leftDiagonalIndex] == false)
		{
			if (QueenCount + 1 == Size)
			{
				Count++;
				return;
			}
			Visit({ x,StartY });
			BackTracking(StartY + 1, QueenCount + 1);
			Exit({ x,StartY });
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	BackTracking(0, 0);
	cout << Count;

	return 0;
}