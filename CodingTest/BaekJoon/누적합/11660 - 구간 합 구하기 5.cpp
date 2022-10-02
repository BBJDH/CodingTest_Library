
/*
11660 - 구간 합 구하기 5


언뜻 보면 그냥 브루트 포스로 다 합해줘서 구해도 될듯하지만
쿼리수가 굉장히 많다.. 그러므로 미리 누적합을 몽땅 구해주고
사각형 넓이를 빼듯이 해당 좌표구간에 대한 누적합을 반환해준다

3행 3열 부터 4행 4열까지를 구한다라고하면
우리는 4X4 사각형으로부터  4X2와 2X4를 빼주고 두번 겹쳐서 빼지는 부분인 2X2를 다시 더해준다

. - 구할 누적합(넓이)
X - 두번 빼져서 겹치는 부분
/ - 빼줘야 할 부분
XX//
XX//
//..
//..
*/
#include<iostream>

using namespace std;

int Table[1025][1025]{};

int DPTable[1025][1025]{};
int TableSize = 0;
int QueryCount = 0;

struct _int2
{
	int X;
	int Y;
};
void DP()
{
	for (int y = 1; y <= TableSize; y++)
	{
		for (int x = 1; x <= TableSize; x++)
		{

			DPTable[y][x] += Table[y][x];
			DPTable[y][x] += DPTable[y - 1][x] - DPTable[y - 1][x - 1];
			DPTable[y][x] += DPTable[y][x - 1];
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> TableSize >> QueryCount;

	for (int y = 1; y <= TableSize; y++)
	{
		for (int x = 1; x <= TableSize; x++)
		{
			int InputNum = 0;
			cin >> InputNum;
			Table[y][x] = InputNum;
		}
	}
	DP();
	while (QueryCount--)
	{
		_int2 StartPos{}, Endpos{};

		cin >> StartPos.X >> StartPos.Y >> Endpos.X >> Endpos.Y;
		//(X,Y)좌표접근이 아니다!  X행 Y열로 접근하므로 XY를 바꾸어준다 
		cout << DPTable[Endpos.X][Endpos.Y] - DPTable[Endpos.X][StartPos.Y - 1] - DPTable[StartPos.X - 1][Endpos.Y] + DPTable[StartPos.X - 1][StartPos.Y - 1] << "\n";
	}
	return 0;
}
