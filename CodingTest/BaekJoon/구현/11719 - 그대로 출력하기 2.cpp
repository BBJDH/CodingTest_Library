/*
 *11719 - �״�� ����ϱ� 2
 *
 *������ �䱸������ �״�� �����ߴ�
 *�ִ� 100���̰� ������ �����ϹǷ�
 *getline���� 100�� ���ڿ��� ���δ����� �޾� ��½�Ų��.
 *����� �ʱ�ȭó���� �ʼ�, ���� �Է��� ���� �� �ִ�.
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string inputStr{};

	for (int i = 0; i < 100; i++)
	{
		getline(cin, inputStr);
		//if (inputStr.empty())
		//	break;

		cout << inputStr << "\n";
		inputStr.clear();
	}


	return 0;
}