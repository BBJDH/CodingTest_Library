/*
 * 27866 - ���ڿ� ���ڿ�
 *
 * ���ڿ��� �ٷ�� ���� ������ ����
 *
 * string���� �Է� �޾� �Է¹��� InputNum-1 ��° �ε����� ���ڸ� ����Ѵ�.
 *
 *
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};
	int InputNum = 0;


	cin >> InputStr >> InputNum;

	cout << InputStr[InputNum - 1];

	return 0;
}