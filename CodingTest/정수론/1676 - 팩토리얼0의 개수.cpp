
/*
1676 - ���丮�� 0�� ����
5�� �������� ���������� ��ŭ ���ϸ� �ȴ�
*/
#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputNum = 0;
	int Count = 0;
	cin >> InputNum;

	cout << InputNum / 5 + InputNum / 25 + InputNum / 125;
	return 0;
}
