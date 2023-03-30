/*
 *14503 - �κ� û�ұ�
 *
 *BFS�� DFS�� �����ϰ��� ������,
 *
 *�䱸������ �� ���� �κ��� �۵���Ĵ�� ���� Ž���ؾ� �Ѵ�.
 *
 *�κ��� �۵���Ĵ�� �����ϰ� �ùķ��̼� �ؾ߸� Ư�� ������ Ž������ ���ϴ� ��찡 �����
 *
 *����
 *
 *5 5		- ũ��
 *1 2 2		- (2,1) ������ �ٶ� ��� (���� ���� ����� 0,0)
 *1 1 1 1 1
 *1 0 0 0 1
 *1 1 1 0 1
 *1 1 1 0 1
 *1 1 1 1 1
 *
 *���� ��� ��� 0 ������ û������ ���Ѵ�.
 *(�ش��� 4�̴�. 2,1���� ������ �������� û���ϰ� �����Ͽ� ���� �����Ѵ�.)
 *
 *
 *������ BFS�� DFS�� ��� ����� 0������ Ž���ϰ��� �ϸ� ���信 ������ ������.
 *
 *���� �䱸���״�� �����Ͽ� �ùķ��̼��� ���� ġ�� �� ������ ����Ѵ�.
 *
 */

#include<iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

//�ݽð���� 0-��, 1-��, 2-��, 3-��
_int2 Direction[4] = { {0,-1}, {1,0}, {0,1}, {-1,0} };
int Map[50][50]{};
bool Visit[50][50]{};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int SizeY = 0, SizeX = 0;
	_int2 CurrentPos{};
	int CurrentDirection = 0;
	int Result = 0;

	cin >> SizeY >> SizeX;
	cin >> CurrentPos.Y >> CurrentPos.X >> CurrentDirection;

	for (int y = 0; y < SizeY; y++)
	{
		for (int x = 0; x < SizeX; x++)
		{
			cin >> Map[y][x];
		}
	}

	while (true)
	{
		//�����ؼ� ������ ��
		if (Map[CurrentPos.Y][CurrentPos.X] == 1)
		{
			break;
		}

		//������ ���� û���� ���ΰ��
		if (Visit[CurrentPos.Y][CurrentPos.X] == false)
		{
			Visit[CurrentPos.Y][CurrentPos.X] = true;
			Result++;
			continue;
		}

		//�ֺ� û���� �� �˻�
		bool IsExistUnCleanRoom = false;
		for (int i = 0; i < 4; i++)
		{
			_int2 NearByRoomPos{};
			NearByRoomPos.X = CurrentPos.X + Direction[i].X;
			NearByRoomPos.Y = CurrentPos.Y + Direction[i].Y;
			if (Map[NearByRoomPos.Y][NearByRoomPos.X] != 1 and Visit[NearByRoomPos.Y][NearByRoomPos.X] == false)
			{
				IsExistUnCleanRoom = true;
				break;
			}
		}
		//��� ���� �����ϸ� ����
		if (IsExistUnCleanRoom == false)
		{
			CurrentPos.X = CurrentPos.X + (Direction[CurrentDirection].X * -1);
			CurrentPos.Y = CurrentPos.Y + (Direction[CurrentDirection].Y * -1);
			continue;
		}

		//�ݽð� ����ȸ�� �� Ž��
		for (int i = 0; i < 4; i++)
		{
			CurrentDirection = CurrentDirection - 1;
			if (CurrentDirection == -1)
			{
				CurrentDirection = 3;
			}
			_int2 NextPos{};
			NextPos.X = CurrentPos.X + Direction[CurrentDirection].X;
			NextPos.Y = CurrentPos.Y + Direction[CurrentDirection].Y;
			if (Map[NextPos.Y][NextPos.X] != 1 and Visit[NextPos.Y][NextPos.X] == false)
			{
				CurrentPos.X = NextPos.X;
				CurrentPos.Y = NextPos.Y;
				break;
			}
		}

	}
	cout << Result;
	return 0;
}