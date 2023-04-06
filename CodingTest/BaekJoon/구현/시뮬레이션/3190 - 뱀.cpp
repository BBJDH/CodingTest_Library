/*
 *3190 - ��
 *
 *������ �䱸���״�� ���� �� �ùķ��̼� ����� ����ϴ� �����̴�.
 *���� �̵���θ� ť�� ���, �̵��Ҷ����� �ʿ� ������ 3���� ����ϰ� ������ġ�� ť�� Push
 *����� ���� ���ߴٸ� ť���� ���� �ش� ��ġ�� 0���� ����(������ 3)
 *����� �Ծ��ٸ� ���� Push ������ ������ Pop�� ���� ����
 *
 *3�� ��ų� ���� ��Ż�Ѵٸ� �ش� Time�� ���
 *
 *ù ����
 *
 *S 0 0 0 0 0 0
 *0 0 0 0 2 0 0
 *0 0 0 2 0 0 0
 *0 0 0 0 0 0 0
 *0 0 2 0 0 0 0
 *0 0 0 0 0 0 0
 *
 *����� 2�� ���
 *3 �ʿ��� D����(���������� ȸ��) ���� �� 5�ʿ��� ����� �԰� 9�ʿ��� ���� ��Ż
 *���� ��Ż�� 9�ʸ� ���
 *
 *D(������ ȸ��)�� L(���� ȸ��)�� ��� ó���ұ�?
 *Direction[4]�� ����� �ε��� 0�� ���������� �����Ͽ� �ð�������� ������ ����,
 *
 *�� +1�� �ȴٸ� ������ ȸ��, -1�� �ȴٸ� ���� ȸ���� �ε����� ���� ����������.
 *�Է¹��� ���⿪�� ť�� �����Ͽ� ���� ó�� �Է¹��� ���� ȸ������ �ð��� ���� ó���Ѵ�.
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
	//_int2�� ��ǥ�� TimeRotation���� �Ѵ� ����ϱ� ���� �̸� ������
	int Time()const { return X; }
	int Rotation()const { return Y; }
};

queue<_int2>LocationOfTail{};
queue<_int2>NextRotation{};
int Map[101][101]{};
int Size = 0;

//������ �Ʒ� ���� ����
_int2 Direction[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };



bool IsInGame(_int2 const& LocationOfSnake)
{
	bool IsOver = false;

	//������ ���������� or �����Ͽ� �� �ݴ븦 ��ȯ (���� ���Ӱ����ϴٸ� true ��ȯ)
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

		//����� ���� ���ߴٸ�
		if (not LocationOfTail.empty() and Map[LocationOfSnake.Y][LocationOfSnake.X] != 2)
		{
			_int2 const EndOfTail = LocationOfTail.front();
			LocationOfTail.pop();
			Map[EndOfTail.Y][EndOfTail.X] = 0;
		}
		//�̵���� ������ ���
		LocationOfTail.push(LocationOfSnake);
		Map[LocationOfSnake.Y][LocationOfSnake.X] = 3;

		//���� ����
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
		//����� 2
		Map[LocationOfApple.Y][LocationOfApple.X] = 2;
	}
	cin >> CountOfDirection;
	for (int i = 0; i < CountOfDirection; i++)
	{
		_int2 InputRotation{};
		char CharOfRotation{};
		cin >> InputRotation.X >> CharOfRotation;
		//_int2�� �Ľ�
		if (CharOfRotation == 'D')
		{
			InputRotation.Y = 1;
		}
		if (CharOfRotation == 'L')
		{
			InputRotation.Y = -1;
		}
		//ť ����
		NextRotation.push(InputRotation);
	}

	Solution();

	return 0;
}