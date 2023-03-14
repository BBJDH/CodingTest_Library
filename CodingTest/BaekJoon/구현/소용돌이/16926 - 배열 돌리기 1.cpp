/*
 *16926 - �迭 ������ 1
 *
 *
 *SizeX �� SizeY �� ���� ���� ¦���� �־����ٴ� ������ �����Ƿ�
 *�̴� ������ ȸ���� ȸ���� �� ���� ���ٸ� ���ԵǴ°�츦 ���������� �����ߴ�.
 *
 *�� �ܰ��� ���� �־� ������ ���� ������� �迭�� �ٽ� ����Ѵ�.
 *
 *ó������ ť�� �����Ͽ����� ť�δ� Rotate�� 2��� ��ü ������ -2 ��ŭ pop and push �ؾ��ϱ⿡
 *
 *���� �̿��� popback�Ͽ� pushfront�� countofrotate��ŭ �����Ѵ�
 *
 *rotate�� 1000���� ��ȿ�ϹǷ� �ð������ ���̱� ����
 *�ܰ� �ѷ����̷� mod �����Ͽ� ���� rotate�Ѵ�.
 *
 *
 *	�� ���̵庰 PushCount ���
 *
 *	3 2 �ΰ��
 *	***
 *	***
 *	���� ������ y Push ī��Ʈ�� 1 x Push ī��Ʈ�� 2�� �������� Ǫ��
 *	���� ���� y�Ǵ� x�� �ִ� Push ī��Ʈ�� 0���϶�� ������ �ߴ��Ѵ�.
 *
 *	SizeX SizeY�� �־����ٸ�
 *  SizeX-1 SizeY-1 �� �ִ� Ǫ��ī��Ʈ�� �ǰ�,
 *	���� ���� ������ Ǫ�� ī��Ʈ�� SizeX-3 SizeY-3 �� �Ǵ� ��Ģ���� �����Ѵ�.
 *
 *	���� ���� ������ ã��
 *
 *	6 4 �ΰ��
 *
 *	******
 *	******
 *	******
 *	******
 *	���� ù �������� 0,0 ������ 1,1 �̰�
 *
 *	5 4
 *
 *	*****
 *	*****
 *	*****
 *	*****
 *
 *	������ ���������� �������� 0,0 ������ 1,1�� �־�����
 *	�ܼ� 1�� ���ذ��� �������� ã���ָ� �ȴ�.
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


//�迭���� ������ ������ �Լ�
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

//������ �迭�� ����ϴ� �Լ�
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

//���� ������ �Լ�
void RotateDeque(deque<int>& DequeToRotate, int  CountOfRotate)
{
	while (CountOfRotate--)
	{
		int const CurrentNum = DequeToRotate.back();
		DequeToRotate.pop_back();
		DequeToRotate.push_front(CurrentNum);
	}
}

//�� ���Լ��� �ܰ����κ��� �����ϴ� �Լ� �ۼ�

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