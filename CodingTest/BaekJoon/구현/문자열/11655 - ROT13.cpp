/*
 *11655 - ROT13
 *
 *���� ����TargetChar�� StartChar(�빮�� Ȥ�� �ҹ��� A) �� �Է¹޾�
 *
 * TargetChar - StartChar �� 13 �̻��̶��
 *
 *TargetChar - 13 �� ���ڸ� ��ȯ�ϰ�
 *
 *�̿ܿ��� TargetChar + 13�� ���ڸ� ��ȯ�ϴ� �Լ��� �ۼ��Ѵ�.
 *
 *
 *������ �Է��� getline�� ���� ���� ��°�� �Է� �޾�
 *
 *���ĺ��� ��쿡�� ���� �Լ��� ȣ���ϸ� ���ڸ� ��ü�Ѵ�.
 *
 *��繮�ڰ� ��ü�� ��  �ٲ� ���ڿ��� ����Ѵ�.
 *
 */


#include<iostream>
#include <string>

using namespace std;

char GetCharNum(char const& TargetChar, char const& StartChar)
{
	if ((TargetChar - StartChar) >= 13)
	{
		return (TargetChar - 13);
	}
	return (TargetChar + 13);
}

void ROT13(string& InputStr)
{
	for (char& Elem : InputStr)
	{
		if (('A' <= Elem and Elem <= 'Z'))
		{
			Elem = GetCharNum(Elem, 'A');
		}
		if ('a' <= Elem and Elem <= 'z')
		{
			Elem = GetCharNum(Elem, 'a');
		}
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	getline(cin, InputStr);

	ROT13(InputStr);

	cout << InputStr;

	return 0;
}