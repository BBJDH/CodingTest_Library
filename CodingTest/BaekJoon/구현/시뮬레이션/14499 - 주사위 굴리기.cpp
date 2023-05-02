/*
 * 14499 - 주사위 굴리기
 *
 *입력 받는 좌표계가 (행,열) 즉 (Y,X) 으로 입력받는다.
 *
 *주사위를 움직이는 부분은 다음과 같이 구성한다
 *
 *int Dice[6]{}
 *0 - 중앙, 1 - 동쪽, 2 - 서, 3 - 북, 4 - 남, 5 - 윗면
 *
 *주사위를 임의의 방향으로 움직인다면 항상 위의 인덱스 형식을 유지해준다.
 *
 *이렇게 한다면 어떤 회전이 와도 번의 배열원소 교체로 주사위 각 면을 접근 가능하다.
 *
 *
 *각 입력받는 움직임 방향에 대해 다음 좌표를 먼저 구해주고,
 *
 *해당 좌표가 Map의 범위 안에 유효하다면 주사위를 움직이고,
 *0번 면의 교체작업과 5번(윗면)출력 작업을 해준다.
 *
 *
 *
 *
 *
 *이 문제는 문제의 지문을 잘 읽고 그대로 구현하면 되는 문제였다.
 *
 *(r,c)좌표계이기 때문에 행, 열로 거꾸로 입력받는다.
 *
 *일부러 헷갈리게 (x,y) 로 시작좌표를 받는다고 써놓은 지문에 찬사를...
 *
 *
 *
 *문제 이름이 [주사위 굴리기]이기 때문에 주사위의 면이 공백인 경우 Map에서 복사해오는 것으로
 *착각할 수있다. 하지만 반대로 Map의 해당 칸을 기준으로 동작시켜야 한다.
 *
 *주사위의 아랫면이 어떻든 상관이 없다.
 *그저 주사위가 놓인 칸이 비어있으면 복사하고, 칸에 숫자가 있다면 주사위에 붙이고 칸은 0이 된다.
 *
 */

#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

int Map[20][20]{};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,-1}, {0,1} };

// 0 - 중앙, 1 - 동쪽, 2 - 서, 3 - 북, 4 - 남, 5 - 반대편 
int Dice[6]{};

void MoveDice(int const NumOfDirection)
{
	int NextNum = Dice[5];
	if (NumOfDirection == 0)
	{
		//동쪽인 경우, 서쪽이 위로, 0이 서쪽으로, 1이 0으로
		Dice[5] = Dice[2];
		Dice[2] = Dice[0];
		Dice[0] = Dice[1];
		Dice[1] = NextNum;
		return;
	}
	if (NumOfDirection == 1)
	{
		//서쪽인 경우, 동쪽이 위로, 0이 동쪽으로, 서쪽이 0으로

		Dice[5] = Dice[1];
		Dice[1] = Dice[0];
		Dice[0] = Dice[2];
		Dice[2] = NextNum;
		return;

	}
	if (NumOfDirection == 2)
	{
		//북쪽인 경우, 남쪽이 위로, 남에 0이, 0에 북이 들어옴
		Dice[5] = Dice[4];
		Dice[4] = Dice[0];
		Dice[0] = Dice[3];
		Dice[3] = NextNum;
		return;

	}
	if (NumOfDirection == 3)
	{
		//남쪽인 경우, 북쪽이 위로, 북에 0이, 0에 남이 들어옴
		Dice[5] = Dice[3];
		Dice[3] = Dice[0];
		Dice[0] = Dice[4];
		Dice[4] = NextNum;
		return;

	}
	//주사위 회전 완료
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	_int2 Size{}, Pos{};
	int NumOfMove = 0;
	cin >> Size.Y >> Size.X >> Pos.Y >> Pos.X >> NumOfMove;
	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			cin >> Map[y][x];
		}
	}
	while (NumOfMove--)
	{
		int NumOfDirection = 0;
		cin >> NumOfDirection;
		NumOfDirection--;
		if (Pos.X + Direction[NumOfDirection].X >= 0 and Pos.X + Direction[NumOfDirection].X < Size.X
			and Pos.Y + Direction[NumOfDirection].Y >= 0 and Pos.Y + Direction[NumOfDirection].Y < Size.Y)
		{
			Pos.X += Direction[NumOfDirection].X;
			Pos.Y += Direction[NumOfDirection].Y;

			MoveDice(NumOfDirection);

			if (Map[Pos.Y][Pos.X] == 0)
			{
				//움직인 Map의 자리에 숫자가 0이면 주사위에서 복사
				Map[Pos.Y][Pos.X] = Dice[0];
			}
			else
			{
				//움직인 Map의 자리에 숫자가 있다면 주사위에 옮겨가고 Map은 0
				Dice[0] = Map[Pos.Y][Pos.X];
				Map[Pos.Y][Pos.X] = 0;
			}
			cout << Dice[5] << "\n";
		}
	}

	return 0;
}