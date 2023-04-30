/*
 *10798 - �����б�
 *
 *�Է¹޴� ���ڿ��� 5���� char 2���� �迭�� ���� �ִ´�.
 *
 *vector�� �̿��� 2���� �迭�� �����Ͽ� �� �ึ�� ����� �� �� �ְ� �ߴ�.
 *
 *���� ������ ��ǥ�� ������ ���͸� �Ѱ��ָ� �ش� ��ġ�� ���ڸ� ������ִ� �Լ��� �ۼ��Ѵ�.
 *
 *���� �ش� ��ǥ�� ������ ���� ����� �Ѿ��ٸ� �ƹ��͵� ������� �ʴ´�.
 *
 *�̰��� ������ �䱸��� X�δ� 15�� y�δ� 5�� ��ŭ ��ȯ�Ͽ� ����Ѵ�.
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintChar(vector<vector<char>> const& InputChar, int const X, int const Y)
{
	if (X >= InputChar[Y].size())
	{
		return;
	}
	cout << InputChar[Y][X];
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<vector<char>> InputChar{};
	InputChar.resize(5);
	for (int i = 0; i < 5; i++)
	{
		string InputStr{};
		getline(cin, InputStr);
		for (char const elem : InputStr)
		{
			if (elem == ' ')
			{
				break;
			}
			InputChar[i].push_back(elem);
		}
	}

	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			PrintChar(InputChar, x, y);
		}
	}

	return 0;
}