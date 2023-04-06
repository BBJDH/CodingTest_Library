/*
 *3190 - 뱀
 *
 *문제의 요구사항대로 구현 및 시뮬레이션 결과를 출력하는 문제이다.
 *뱀의 이동경로를 큐에 기록, 이동할때마다 맵에 꼬리를 3으로 기록하고 현재위치를 큐에 Push
 *사과를 먹지 못했다면 큐에서 꺼내 해당 위치를 0으로 수정(꼬리가 3)
 *사과를 먹었다면 위의 Push 과정을 하지만 Pop은 하지 않음
 *
 *3을 밟거나 맵을 이탈한다면 해당 Time을 출력
 *
 *첫 예제
 *
 *S 0 0 0 0 0 0
 *0 0 0 0 2 0 0
 *0 0 0 2 0 0 0
 *0 0 0 0 0 0 0
 *0 0 2 0 0 0 0
 *0 0 0 0 0 0 0
 *
 *사과를 2로 기록
 *3 초에서 D방향(오른쪽으로 회전) 직진 후 5초에서 사과를 먹고 9초에서 맵을 이탈
 *맵을 이탈한 9초를 출력
 *
 *D(오른쪽 회전)와 L(왼쪽 회전)을 어떻게 처리할까?
 *Direction[4]를 만들어 인덱스 0을 오른쪽으로 시작하여 시계방향으로 방향을 설정,
 *
 *즉 +1이 된다면 오른쪽 회전, -1이 된다면 왼쪽 회전을 인덱스로 접근 가능해진다.
 *입력받은 방향역시 큐로 보관하여 가장 처음 입력받은 방향 회전부터 시간에 맞춰 처리한다.
 *
 *
 *
 */


#include <iostream>
#include <queue>

using namespace std;

struct _int2
{
	int X;
	int Y;
	//_int2를 좌표와 TimeRotation으로 둘다 사용하기 위해 이름 재정의
	int Time()const { return X; }
	int Rotation()const { return Y; }
};

queue<_int2>LocationOfTail{};
queue<_int2>NextRotation{};
int Map[101][101]{};
int Size = 0;

//오른쪽 아래 왼쪽 위쪽
_int2 Direction[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };



bool IsInGame(_int2 const& LocationOfSnake)
{
	bool IsOver = false;

	//게임의 종료조건을 or 연산하여 그 반대를 반환 (게임 지속가능하다면 true 반환)
	IsOver |= LocationOfSnake.X == 0;
	IsOver |= LocationOfSnake.X > Size;
	IsOver |= LocationOfSnake.Y == 0;
	IsOver |= LocationOfSnake.Y > Size;
	IsOver |= Map[LocationOfSnake.Y][LocationOfSnake.X] == 3;

	return not IsOver;
}

void Solution()
{
	_int2 LocationOfSnake{ 1,1 };
	int CurrentTime = 0;
	int CurrentDirection = 0;


	while (IsInGame(LocationOfSnake))
	{

		//사과를 먹지 못했다면
		if (not LocationOfTail.empty() and Map[LocationOfSnake.Y][LocationOfSnake.X] != 2)
		{
			_int2 const EndOfTail = LocationOfTail.front();
			LocationOfTail.pop();
			Map[EndOfTail.Y][EndOfTail.X] = 0;
		}
		//이동경로 꼬리로 기록
		LocationOfTail.push(LocationOfSnake);
		Map[LocationOfSnake.Y][LocationOfSnake.X] = 3;

		//방향 설정
		if (not NextRotation.empty() and NextRotation.front().Time() == CurrentTime)
		{
			CurrentDirection += NextRotation.front().Rotation();
			NextRotation.pop();

			if (CurrentDirection < 0)
			{
				CurrentDirection = 3;
			}
			CurrentDirection = CurrentDirection % 4;
		}

		LocationOfSnake.X = LocationOfSnake.X + Direction[CurrentDirection].X;
		LocationOfSnake.Y = LocationOfSnake.Y + Direction[CurrentDirection].Y;
		CurrentTime++;
	}
	cout << CurrentTime;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	int CountOfApple = 0;
	int CountOfDirection = 0;

	cin >> CountOfApple;

	for (int i = 0; i < CountOfApple; i++)
	{
		_int2 LocationOfApple{};
		cin >> LocationOfApple.Y >> LocationOfApple.X;
		//사과는 2
		Map[LocationOfApple.Y][LocationOfApple.X] = 2;
	}
	cin >> CountOfDirection;
	for (int i = 0; i < CountOfDirection; i++)
	{
		_int2 InputRotation{};
		char CharOfRotation{};
		cin >> InputRotation.X >> CharOfRotation;
		//_int2로 파싱
		if (CharOfRotation == 'D')
		{
			InputRotation.Y = 1;
		}
		if (CharOfRotation == 'L')
		{
			InputRotation.Y = -1;
		}
		//큐 삽입
		NextRotation.push(InputRotation);
	}

	Solution();

	return 0;
}