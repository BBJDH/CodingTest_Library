/*
 * 2630 - ������ �����
 *
 *
 *���� ������ ��͸� ���� Ǯ����
 *
 *�����̸� ������ �䱸�ϴ¹ٿ� ���� 4������� ���� �����Ѵ�
 *
 *���̻� �ڸ� �� ���� Size==1 �� ���¿� �����Ѵٸ� �ش� ������ �÷��� ��ȯ�Ѵ�.
 *
 *��ȯ���� ������ ��(�Ͼ��, �Ķ���)�� �� ������ ��� ī���� �ߴ��� �����̴�.
 *0�� �Ͼ�� 1�� �Ķ��� 2�� �ش� ������ �Ϸ�Ǿ����� ��Ÿ����.
 *
 *���ҵ� 4������ ���� �迭�� �����Ͽ� ��� ������ ���� ��ġ�ϴ����� Ȯ���Ѵ�
 *
 *��ġ���� �ʴ´ٸ� �ش� ������ ���� ������ ������ ī�����ϰ�
 *
 *�Ϸ�� ������ �ǹ��� 2�� ��ȯ�Ѵ�.
 *
 *�̿� ���� ��� ������ ���Ͽ� ������ �Ϸ�ǰ� ī������ �Ϸ�Ǿ��ٸ�
 *
 *�ش� ������� ����Ѵ�.
 *
 *���������� ���� ū ���̰� 1 Ȥ�� 0���� ��� ���� ���� ��츦 ����Ѵ�.
 *
 */


#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

int Paper[128][128]{};
int Result[2]{};
int Size = 0;
int PaperOfWhite = 0;
int PaperOfBlue = 0;


int DivideAndConquer(_int2 const PosOfStart, int const Size)
{
	if (Size == 1)
	{
		return Paper[PosOfStart.Y][PosOfStart.X];
	}
	int const NewSize = Size / 2;
	int ResultOfDivide[4]{};
	ResultOfDivide[0] = DivideAndConquer(PosOfStart, NewSize);
	ResultOfDivide[1] = DivideAndConquer({ PosOfStart.X + NewSize, PosOfStart.Y }, NewSize);
	ResultOfDivide[2] = DivideAndConquer({ PosOfStart.X,PosOfStart.Y + NewSize }, NewSize);
	ResultOfDivide[3] = DivideAndConquer({ PosOfStart.X + NewSize,PosOfStart.Y + NewSize }, NewSize);

	if (ResultOfDivide[0] == ResultOfDivide[1] and ResultOfDivide[1] == ResultOfDivide[2]
		and ResultOfDivide[2] == ResultOfDivide[3] and ResultOfDivide[3] != 2)
	{
		return ResultOfDivide[0];
	}
	for (int i = 0; i < 4; i++)
	{
		if (ResultOfDivide[i] == 2)
		{
			continue;
		}
		int const ColorOfPaper = ResultOfDivide[i];
		Result[ColorOfPaper]++;
	}
	//�� ������ ���� ���� ��� ī���� �Ϸ� �����Ƿ� 2
	return 2;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			cin >> Paper[y][x];
		}
	}
	int ColorOfPaper = DivideAndConquer({ 0,0 }, Size);
	if (ColorOfPaper != 2)
	{
		Result[ColorOfPaper]++;
	}

	cout << Result[0] << "\n" << Result[1];
	return 0;
}