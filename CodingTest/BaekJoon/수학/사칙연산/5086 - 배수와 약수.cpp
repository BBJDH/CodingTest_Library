/*
 *5086 - ����� ���
 *
 * ����� ����� �ڵ�� ��� �ĺ��ؾ��ϴ��� ����� ��������
 *
 * %�����ڸ� �̿��� ����� ����� �Ǻ��Ѵ�.
 * ���� ���� �� �ƴ϶�� �ش� �Է¿� ���Ͽ� neither�� ���
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int FirstNumOfInput = -1, SecondNumOfInput = -1;


	while (true)
	{
		cin >> FirstNumOfInput >> SecondNumOfInput;

		if (FirstNumOfInput == 0 and SecondNumOfInput == 0)
		{
			break;
		}

		if (SecondNumOfInput % FirstNumOfInput == 0)
		{
			cout << "factor\n";
			continue;
		}
		if (FirstNumOfInput % SecondNumOfInput == 0)
		{
			cout << "multiple\n";
			continue;
		}

		cout << "neither\n";
	}

	return 0;
}