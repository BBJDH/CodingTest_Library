/*
 *2167 - 2차원 배열의 합
 *
 *2차원 배열 크기의 누적합을 구성하고 주어지는 InputCount 만큼 범위에 따라 누적합을 출력한다.
 *
 *누적합 구하는 방법
 *
 *입력 예시
 *
 *1 0 0 1
 *0 0 1 1
 *1 2 1 1
 *2 0 3 0
 *
 *먼저 X방향으로 누적합을 구하고 Y방향으로 누적합을 구한다.
 *
 *X방향으로 누적합 (왼쪽에서 오른쪽으로 누적합)
 *
 *1 1 1 2
 *0 0 1 2
 *1 3 4 5
 *2 2 5 5
 *
 *Y방향으로 누적합 (위에서 아래로 누적합)
 *
 *1 1 1  2
 *1 1 2  4
 *2 4 6  9
 *4 6 11 14
 *
 *위의 그래프가 누적합이 완성된 모습이다.
 *
 *각 점 (X,Y) 에 대하여
 *
 *만들어진 누적합이 DP[Y][X]의 의미는 (0,0)부터 (X,Y) 까지 그려진 사각형 안 모든 수들의 합을 의미하게 된다.
 *
 *즉 (2,2)에서 (3,3) 까지의 누적합을 구한다면,
 *
 *1 1 1 2
 *0 0 1 2
 *1 3 [4 5]
 *2 2 [5 5]
 *
 *위의 대괄호 안 모든 수의 합을 의미하고 이것은
 *
 *(3,3)까지 누적합	- (1,3)까지 누적합	- (3,1)까지 누적합	+ (1,1)까지 누적합
 *DP[3][3]			- DP[3][1]			- DP[1][3]			+ DP[1][1]
 *
 *(1,1)까지 누적합을 다시 +해주는 이유는
 *(1,3) 과 (3,1)이 빼지면서 두번 빼져버린 (1,1)까지의 누적합을 다시 더해주는 것이다.
 *
 *범위를 지정해 위처럼 계산하여 누적합을 계산해 주는 함수를 작성한다.
 *다만 문제의 좌표는 가장 왼쪽 상단점을 1,1로 여겨 입력하므로
 *함수를 호출하기전에 -1 해준다.
 *
 */

#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

int DP[300][300]{};

//2차원 배열 From위치 부터 To 위치까지의 합 반환
int GetSum(_int2 const& From, _int2 const& To)
{
	int Result = 0;
	//From-1, To.Y 까지의 합을 빼준다
	if (From.X > 0)
	{
		Result -= DP[To.Y][From.X - 1];
	}
	//To.X-1, From.Y 까지의 합을 빼준다
	if (From.Y > 0)
	{
		Result -= DP[From.Y - 1][To.X];
	}
	//위의 과정에서 From.X-1, From.Y-1 까지의 합이 두번 빼지게 되므로 다시 한번 더해준다.
	if (From.Y > 0 and From.X > 0)
	{
		Result += DP[From.Y - 1][From.X - 1];
	}
	Result += DP[To.Y][To.X];
	return Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	_int2 Size{};

	cin >> Size.Y >> Size.X;

	for (int y = 0; y < Size.Y; y++)
	{
		int Sum = 0;
		for (int x = 0; x < Size.X; x++)
		{
			int InputNum = 0;
			cin >> InputNum;
			Sum += InputNum;	//X행 누적합
			if (y > 0)
			{
				DP[y][x] += DP[y - 1][x];	//Y행 누적합
			}
			DP[y][x] += Sum;
		}
	}
	int InputCount = 0;
	cin >> InputCount;
	while (InputCount--)
	{
		_int2 From{};
		_int2 To{};

		cin >> From.Y >> From.X >> To.Y >> To.X;
		From.Y--;
		From.X--;
		To.Y--;
		To.X--;
		cout << GetSum(From, To) << "\n";
	}


	return 0;
}