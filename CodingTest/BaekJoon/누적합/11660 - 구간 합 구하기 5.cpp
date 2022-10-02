
/*
11660 - ���� �� ���ϱ� 5


��� ���� �׳� ���Ʈ ������ �� �����༭ ���ص� �ɵ�������
�������� ������ ����.. �׷��Ƿ� �̸� �������� ���� �����ְ�
�簢�� ���̸� ������ �ش� ��ǥ������ ���� �������� ��ȯ���ش�

3�� 3�� ���� 4�� 4�������� ���Ѵٶ���ϸ�
�츮�� 4X4 �簢�����κ���  4X2�� 2X4�� ���ְ� �ι� ���ļ� ������ �κ��� 2X2�� �ٽ� �����ش�

. - ���� ������(����)
X - �ι� ������ ��ġ�� �κ�
/ - ����� �� �κ�
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
		//(X,Y)��ǥ������ �ƴϴ�!  X�� Y���� �����ϹǷ� XY�� �ٲپ��ش� 
		cout << DPTable[Endpos.X][Endpos.Y] - DPTable[Endpos.X][StartPos.Y - 1] - DPTable[StartPos.X - 1][Endpos.Y] + DPTable[StartPos.X - 1][StartPos.Y - 1] << "\n";
	}
	return 0;
}
