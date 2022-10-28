/*
1799 - ���

row ���� 0 ~ (N-1)X2  => X+Y�� ���� �밢��(���� - ���ϴ�)���� ���� ����
col ���� 0 ~ (N-1)X2  => ���������� �̹��� �»�� - ���ϴ� �밢���� X-Y�� ��ġ�Ѵ�
								(������ ������ �߻��ϹǷ� X-Y+N-1 �� �湮���)


01234
1
2
3
4

0���� : 0 2 4 ��ѱ�
		1 3 5 ��ѱ�
		0 2 4...
		=> Ȧ���ε��� Ȧ�� ���� (0�̸� (��+0)%2 �� ����)
1���� : 1 3   ��ѱ�
		0 2 4 ��ѱ�
		1 3
		¦�� �ε��� Ȧ�� ���� ((��+1)%2�� ����)
*/

#include<iostream>
#include<vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

vector<bool> Row_Visit{};
vector<bool> Col_Visit{};

bool Blocked[10][10]{};
int Size = 0;
int ZeroColorMaxCount = 0;
int OneColorMaxCount = 0;

void DeployBishop(int Row, int Count, int const& StartColor)
{
	for (int y = Row; y < Size; y++)
	{

		for (int x = (y + StartColor) % 2; x < Size; x += 2)
		{
			int RowIndex = x + y;
			int ColIndex = x - y + Size - 1;
			if (Blocked[y][x] == true and Row_Visit[RowIndex] == false and Col_Visit[ColIndex] == false)
			{
				Row_Visit[RowIndex] = true;
				Col_Visit[ColIndex] = true;
				DeployBishop(y, Count + 1, StartColor);
				Row_Visit[RowIndex] = false;
				Col_Visit[ColIndex] = false;
			}
		}
	}

	if (StartColor)
		OneColorMaxCount = max(OneColorMaxCount, Count);
	else
		ZeroColorMaxCount = max(ZeroColorMaxCount, Count);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	Row_Visit.resize((Size - 1) * 2 + 1);
	Col_Visit.resize((Size - 1) * 2 + 1);

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			bool Input = false;
			cin >> Input;
			Blocked[y][x] = Input;
		}
	}

	DeployBishop(0, 0, 0);
	DeployBishop(0, 0, 1);

	cout << OneColorMaxCount + ZeroColorMaxCount;
	return 0;
}
