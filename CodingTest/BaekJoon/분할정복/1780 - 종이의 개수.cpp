/*
 *1780 - ������ ����
 *
 *���������� ���� Ǯ�� �����ϴ�.
 *
 *9�������� ������ ���� ������ ũ�Ⱑ 1�� �ɶ����� �����Ѵ�
 *
 *���ҵ� ������ 1, 0, 1- ������ �����Ͽ� ���� ��ȯ�޴´�
 *
 *��ȯ���� 9������ ��� ��ġ�Ѵٸ� �ش� ������ 1, 0, -1 ������ �Ǻ��Ͽ� ��ȯ�Ѵ�.
 *
 *��ġ���� �ʴ´ٸ� 1, 0, -1�� ������ ī�����ϰ� 2�� ��ȯ�Ѵ�
 *(2�� �ش� ������ ����ġ �����̸� �� ������ ���̻� ī������ �ʿ� ���ٴ� �ǹ̷� ����Ѵ�.)
 *
 *�־����� �Էµ� ģ���ϰ� 3���Ҿ� �����ϵ��� 3�� ������ ���´�.
 *������ ���� ����� {0,0}�� ���� ������ ����� �Ѱ� ���������� �� ���̰� ����¥�� ���������� Ȯ�����ش�.
 *
 *���� ������ ī��Ʈ���� �䱸���״�� ������ش�.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};
vector<vector<int>> Map{};
int CountOfZero = 0;
int CountOfOne = 0;
int CountOfMinusOne = 0;
int DivideAndConquer(_int2 const& StartPos, int const Size)
{
	if (Size == 1)
	{
		return Map[StartPos.Y][StartPos.X];
	}

	int CurrentZeroCount = 0;
	int CurrentOneCount = 0;
	int CurrentMinusCount = 0;

	for (int y = StartPos.Y; y < StartPos.Y + Size; y = y + (Size / 3))
	{
		for (int x = StartPos.X; x < StartPos.X + Size; x = x + (Size / 3))
		{
			int Result = DivideAndConquer({ x,y }, Size / 3);
			if (Result == -1)
			{
				CurrentMinusCount++;
				continue;
			}
			if (Result == 0)
			{
				CurrentZeroCount++;
				continue;
			}
			if (Result == 1)
			{
				CurrentOneCount++;
				continue;
			}
		}
	}

	//9���� ��ġ�ϴ� ���
	if (CurrentMinusCount == 9)
	{
		return -1;
	}
	if (CurrentZeroCount == 9)
	{
		return 0;
	}
	if (CurrentOneCount == 9)
	{
		return 1;
	}

	//�ϳ��� ��ġ�����ʴ´ٸ� ī���� �÷��ְ� ����ġ ��ȯ
	CountOfZero += CurrentZeroCount;
	CountOfOne += CurrentOneCount;
	CountOfMinusOne += CurrentMinusCount;
	return 2;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Size = 0;
	cin >> Size;
	Map.resize(Size);
	for (int y = 0; y < Size; y++)
	{
		Map[y].resize(Size);
		for (int x = 0; x < Size; x++)
		{
			cin >> Map[y][x];
		}
	}

	int const Result = DivideAndConquer({ 0,0 }, Size);
	if (Result == 1)
	{
		CountOfOne++;
	}
	if (Result == 0)
	{
		CountOfZero++;
	}
	if (Result == -1)
	{
		CountOfMinusOne++;
	}
	cout << CountOfMinusOne << "\n";
	cout << CountOfZero << "\n";
	cout << CountOfOne << "\n";

	return 0;
}