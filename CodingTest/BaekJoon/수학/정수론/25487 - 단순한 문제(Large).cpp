/*
 *25487 - �ܼ��� ����(Large)
 *
 *��¥ ���� ��Ģ�� ���� �پ˾Ҵµ�...
 *
 *�׳� ������ ���߿� ���� ���� ���� ã�Ƽ� ��ȯ�ϸ� �Ǵ� ��������..
 *
 */
#include <iostream>

using namespace std;

int Mods[10][10]{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int testCase = 0;

	cin >> testCase;
	int minNum = 100001;

	while (testCase--)
	{
		minNum = 100001;
		for (int i = 0; i < 3; i++)
		{
			int inputNum = 0;
			cin >> inputNum;
			minNum = min(minNum, inputNum);
		}
		cout << minNum << "\n";
	}

	return 0;
}