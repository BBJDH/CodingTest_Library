/*
 *25487 - 단순한 문제(Large)
 *
 *진짜 무슨 규칙이 있을 줄알았는데...
 *
 *그냥 세가지 수중에 가장 작은 수만 찾아서 반환하면 되는 문제였다..
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