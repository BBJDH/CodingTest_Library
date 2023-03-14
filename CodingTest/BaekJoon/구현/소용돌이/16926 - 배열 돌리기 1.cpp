/*
 *16926 - 배열 돌리기 1
 *
 *
 *SizeX 와 SizeY 중 작은 수는 짝수로 주어진다는 조건이 있으므로
 *이는 마지막 회전이 회전할 수 없는 한줄만 남게되는경우를 배제했음을 유추했다.
 *
 *각 외곽을 덱에 넣어 돌리고 같은 방식으로 배열에 다시 기록한다.
 *
 *처음에는 큐로 접근하였으나 큐로는 Rotate가 2라면 전체 사이즈 -2 만큼 pop and push 해야하기에
 *
 *덱을 이용해 popback하여 pushfront를 countofrotate만큼 시행한다
 *
 *rotate는 1000까지 유효하므로 시간비용을 줄이기 위해
 *외곽 둘레길이로 mod 연산하여 덱을 rotate한다.
 *
 *
 *	각 사이드별 PushCount 계산
 *
 *	3 2 인경우
 *	***
 *	***
 *	에서 가능한 y Push 카운트는 1 x Push 카운트는 2씩 돌려가며 푸쉬
 *	이후 다음 y또는 x의 최대 Push 카운트가 0이하라면 수행을 중단한다.
 *
 *	SizeX SizeY가 주어진다면
 *  SizeX-1 SizeY-1 이 최대 푸시카운트가 되고,
 *	다음 안쪽 라인의 푸시 카운트는 SizeX-3 SizeY-3 이 되는 규칙으로 시행한다.
 *
 *	덱에 넣을 시작점 찾기
 *
 *	6 4 인경우
 *
 *	******
 *	******
 *	******
 *	******
 *	에서 첫 시작점은 0,0 다음은 1,1 이고
 *
 *	5 4
 *
 *	*****
 *	*****
 *	*****
 *	*****
 *
 *	에서도 마찬가지로 시작점은 0,0 다음은 1,1로 주어진다
 *	단순 1씩 더해가며 시작점을 찾아주면 된다.
 *
 *
 *
 */
#include <iostream>
#include <deque>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

int Board[300][300]{};
_int2 Direction[4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
_int2 Size{};


//배열에서 덱으로 꺼내는 함수
void MakeDeque(deque<int>& QueueToRotate, _int2 const& StartPos, _int2 const& MaxCount)
{
	_int2 CurrentPos = StartPos;
	for (int i = 0; i < 4; i++)
	{
		int MaxPushCount = 0;
		int CurrentPushCount = 0;
		if ((i % 2) == 0)
		{
			MaxPushCount = MaxCount.Y;
		}
		else
		{
			MaxPushCount = MaxCount.X;
		}

		while (CurrentPushCount < MaxPushCount)
		{
			CurrentPos.X = CurrentPos.X + Direction[i].X;
			CurrentPos.Y = CurrentPos.Y + Direction[i].Y;
			QueueToRotate.push_back(Board[CurrentPos.Y][CurrentPos.X]);
			CurrentPushCount++;
		}
	}
}

//덱에서 배열로 기록하는 함수
void DequeToArray(deque<int>& DequeToRotate, _int2 const& StartPos, _int2 const& MaxCount)
{
	_int2 CurrentPos = StartPos;
	for (int i = 0; i < 4; i++)
	{
		int MaxPopCount = 0;
		int CurrentPopCount = 0;
		if ((i % 2) == 0)
		{
			MaxPopCount = MaxCount.Y;
		}
		else
		{
			MaxPopCount = MaxCount.X;
		}

		while (CurrentPopCount < MaxPopCount)
		{
			CurrentPos.X = CurrentPos.X + Direction[i].X;
			CurrentPos.Y = CurrentPos.Y + Direction[i].Y;
			Board[CurrentPos.Y][CurrentPos.X] = DequeToRotate.front();
			DequeToRotate.pop_front();
			CurrentPopCount++;
		}
	}
}

//덱를 돌리는 함수
void RotateDeque(deque<int>& DequeToRotate, int  CountOfRotate)
{
	while (CountOfRotate--)
	{
		int const CurrentNum = DequeToRotate.back();
		DequeToRotate.pop_back();
		DequeToRotate.push_front(CurrentNum);
	}
}

//위 세함수를 외곽라인부터 시행하는 함수 작성

void Solution(int const CountOfRotate)
{
	_int2 MaxCount{ Size.X - 1,Size.Y - 1 };
	_int2 StartPos{};
	deque<int>DequeToRotate{};

	while (MaxCount.X > 0 and MaxCount.Y > 0)
	{
		int const RotateCount_Calc = CountOfRotate % ((MaxCount.X + MaxCount.Y) * 2);
		MakeDeque(DequeToRotate, StartPos, MaxCount);
		RotateDeque(DequeToRotate, RotateCount_Calc);
		DequeToArray(DequeToRotate, StartPos, MaxCount);
		StartPos.X++;
		StartPos.Y++;
		MaxCount.X -= 2;
		MaxCount.Y -= 2;
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfRotate = 0;
	deque<int>DequeToRotate{};

	cin >> Size.Y >> Size.X >> CountOfRotate;

	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			cin >> Board[y][x];
		}
	}
	Solution(CountOfRotate);

	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			cout << Board[y][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}