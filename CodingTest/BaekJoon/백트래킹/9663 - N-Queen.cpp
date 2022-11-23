/*
 *N-Queen - 9663
 *
 *가로 세로 오른대각 왼대각 방문을 기록한다
 *
 *예를들어 3,5 열에 퀸을 놓을지 질의한다면
 *X배열에 3 방문 처리가 되어있는지(즉 X축 3번 라인에 퀸이 한개라도 있는지, 방문배열 크기 15)
 *Y배열에 5 방문 처리가 되어있는지(즉 Y축 5번 라인에 퀸이 한개라도 있는지, 방문배열 크기 15)
 *
 *오른대각은 모두 XY의 차가 일정함을 이용하여 크기 30 배열  +14(0,14), -14(14,0) => 1 ~ 29
 *왼 대각은 XY의 합이 같음을 이용, 배열 30크기(위와 마찬가지로 29개이지만 그냥 30 0~ 28)
 *
 *
 *라고 생각하고 시도해봤더니 12에서 시간초과가 뜬다
 *생각해보니 어차피 한행씩 위에서 방문하면 다음행부터 방문시도를 시작할 것이므로
 *YVisit은 있을 필요가 없다(미방문상태가 확정이다)
 * Y를 한개씩 넘겨가며 해당 행의 XY에 대해 방문을 검사한다
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