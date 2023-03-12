/*
 *10953 - A+B - 6
 *
 *���ڿ� �Ľ��� ���� ��Ģ������ �����ϴ� �����̴�
 *
 *���ڿ��� �Է¹޾� �̰��� stringstream�� �־� �Ľ��Ѵ�.
 *getline�� ���� stringstream�� ���� ���ڷ� �߶� string�� �ִ´�
 *�� string�� stoi�� ���� ������ �Ľ��Ͽ� �ջ��� ����� ����Ѵ�.
 *
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string InputStr{};
		string Token{};
		cin >> InputStr;
		stringstream SS_InputStr(InputStr);
		int Result = 0;
		while (getline(SS_InputStr, Token, ','))
		{
			Result += stoi(Token);
		}
		cout << Result << "\n";
	}

	return 0;
}