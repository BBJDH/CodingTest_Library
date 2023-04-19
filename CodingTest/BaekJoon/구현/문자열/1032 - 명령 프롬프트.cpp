/*
 *1032 - ��� ������Ʈ
 *
 *
 *�ܼ� �������� Ǯ�� �����ϴ�.
 *
 *�Է� �޴� CountOfDir�� �ڿ����̹Ƿ� �ּ��� �Ѱ��̻� �Է¹޴� ���� �̿��Ѵ�.
 *
 *�̸� Result�� Dir�� �����صΰ�
 *
 *�Է¹��� ��ü Dir��� Result�� ���Ͽ� �ϳ��� �ٸ� ���ڰ� �����Ѵٸ�
 *
 *Result�� �ش� �ε����� ���ڸ� '?'�� ��ü�Ѵ�.
 *
 *�ݺ��� ����� Result�� ����Ѵ�.
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfDir = 0;
	vector<string> Dir{};
	string Result{};
	cin >> CountOfDir;

	while (CountOfDir--)
	{
		string InputDir{};
		cin >> InputDir;
		if (CountOfDir == 0)
		{
			Result = InputDir;
		}
		Dir.push_back(InputDir);
	}


	for (int i = 0; i < Dir[0].size(); i++)
	{
		for (int j = 0; j < Dir.size(); j++)
		{
			if (Result[i] != Dir[j][i])
			{
				Result[i] = '?';
			}

		}
	}
	cout << Result;

	return 0;
}