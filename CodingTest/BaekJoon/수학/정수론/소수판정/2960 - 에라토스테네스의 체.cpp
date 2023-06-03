/*
 *2960 - �����佺�׳׽��� ü
 *
 *�Է¹޴� MaxNum�� ũ��� 1000���� �̹Ƿ�
 *
 *1000 ���� ���������� ����� IsNumErased �����迭�� �̸� ����� �д�.
 *
 *
 *���� �����佺�׳׽��� ä�� ����, ����� K(TargetCount)��° �������� ���� ã�� ����
 *���� ���� �� ���� K(TargetCount)�� ���ҽ�Ų��.
 *
 *���ҽ�Ų TargetCount�� 0�� �����Ѵٸ� �̶� �ش� ���� ��� �� ����
 *
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	bool IsNumErased[1001]{};
	fill_n(IsNumErased, 1001, true);

	int MaxNum = 0, TargetCount = 0;
	cin >> MaxNum >> TargetCount;

	for (int Num = 2; Num < 1001; Num++)
	{
		if (IsNumErased[Num] == true)
		{
			for (int mul = 1; Num * mul <= MaxNum; mul++)
			{
				if (IsNumErased[Num * mul] == true)
				{
					TargetCount--;
					IsNumErased[Num * mul] = false;
				}
				if (TargetCount == 0)
				{
					cout << Num * mul;
					return 0;
				}
			}

		}
	}

	return 0;
}