/*
 *10886 - 0 = not cute / 1 = cute
 *
 *
 *0�� ������ 1�� ������ ���� 1���� �迭�� �̸� �����
 *
 *����� ��ŭ �Է¹޾� �迭�� �����ջ��Ѵ�.
 *
 *��� �Է¹��� �� �ε��� 0�� 1�� ������ ���� ��� ���� ���Ͽ� ����� ����Ѵ�.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfPeople = 0;
	int CuteOrNot[2]{};
	cin >> CountOfPeople;

	while (CountOfPeople--)
	{
		int Input = 0;
		cin >> Input;
		CuteOrNot[Input]++;
	}

	if (CuteOrNot[0] > CuteOrNot[1])
	{
		cout << "Junhee is not cute!";
	}
	else
	{
		cout << "Junhee is cute!";
	}

	return 0;
}