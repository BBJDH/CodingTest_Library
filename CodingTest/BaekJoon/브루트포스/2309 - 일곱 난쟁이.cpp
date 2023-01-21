/*
 *2309 - �ϰ� ������
 *
 *
 *�������� ���� 9�� �����̰� ���� �θ��� ��󳻸� �ȴ�
 *
 *�Է��� ������ �̸� ��� �����̵��� Ű�� ���� ���صΰ�,
 *
 *���� ���տ��� ������ ������ ���� Ű�� ���� �������Ѵ�.
 *
 *9*9 �� N^2���� ��� Ȯ���ؼ�(���Ʈ ����) ���ǿ� �����ϸ�
 *
 *���� ������ �����̵��� ����ϰ� �����Ѵ�.
 *
 *������ǿ� ���߾� �Է� ���� �迭�� �������־�� �Ѵ�.
 *
 *
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;


void PrintWithoutTwoElem(int const Index1, int const Index2, int const* const PrintArr)
{
	for (int i = 0; i < 9; i++)
	{
		if (i == Index1 or i == Index2)continue;;

		cout << PrintArr[i] << "\n";
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Dwarf[9]{};

	int Sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> Dwarf[i];
		Sum += Dwarf[i];
	}
	sort(&Dwarf[0], &Dwarf[9]);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Sum - (Dwarf[i] + Dwarf[j]) == 100)
			{
				PrintWithoutTwoElem(i, j, Dwarf);
				return 0;
			}
		}
	}


	return 0;
}