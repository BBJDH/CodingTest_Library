
/*
1213 - �縰��� �����

�׳� �Է� ������� ���ĺ� ���� ī�������ְ�
Ȧ���� ���ĺ��� 1���� �ʰ��Ѵٸ� �� ���ڿ��� ��Ī�� ���� �� ����. I'm Sorry!
�����ϴٸ� ����2��ŭ ����, Ȧ�����ڰ��ִٸ� ����� ������ְ�, ���� �̷��� ���������

*/

#include<iostream>

using namespace std;

int AlphabetNum[26]{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	cin >> InputStr;

	for (int i = 0; i < InputStr.size(); i++)
	{
		int Index = InputStr[i] - 'A';
		AlphabetNum[Index] ++;
	}

	int Count = 0;
	int OddAlphabet = 0;
	for (int i = 0; i < 26; i++)
	{
		if (AlphabetNum[i] % 2)
		{
			OddAlphabet = i;
			Count++;
		}
		AlphabetNum[i] /= 2;
	}
	if (Count > 1)
		cout << "I'm Sorry Hansoo";
	else
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < AlphabetNum[i]; j++)
				cout << static_cast<char>(i + 'A');
		}
		if (Count == 1)
			cout << static_cast<char>(OddAlphabet + 'A');
		for (int i = 25; i >= 0; i--)
		{
			for (int j = 0; j < AlphabetNum[i]; j++)
				cout << static_cast<char>(i + 'A');
		}
	}

	return 0;
}
