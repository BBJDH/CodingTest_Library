/*
 *
 * 1100 - �Ͼ� ĭ
 *
 *
 *ü������ ũ�Ⱑ 8X8�� �̸� ����� �������� ĥ���� ü������ �����
 *��� ���غ��� ����� �����ϴ�.
 *
 *������ �� �� ��Ģ�� ã�� Ǯ��ٸ�, ������ ���� ��Ģ�� ã�� �� �ִ�.
 *
 *01234567
 *1
 *2
 *3
 *4
 *5
 *
 *O�� ���, X�� �������̶�� �Ѵٸ�
 *
 *OXOXOXOX
 *XOXOXOXO
 *OXOXOXOX
 *XOXOXOXO
 *
 *¦�� ���� ¦�� (0 2 4 6 8...)
 *Ȧ�� ���� Ȧ�� �ε������� (1 3 5 7 9...) ����� ��ĥ�ȴ�.
 *
 *���� ��Ģ�� ���� ��������� �Ǻ��ϴ� �Լ��� �ۼ�,
 *�̸� �̿��� ��� ���� ���� �����ִ��� 8x8 Ž���Ѵ�.
 *
 *
 */


#include<iostream>
#include <string>
#include <vector>

using namespace std;

bool IsWhite(int const X, int const Y)
{
	if (Y % 2 == X % 2)
	{
		return true;
	}
	return false;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<string> Board{};


	//�Է�
	for (int i = 0; i < 8; i++)
	{
		string InputStr{};
		cin >> InputStr;
		Board.push_back(InputStr);
	}

	//8X8 Ȯ�� ����
	int Result = 0;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (IsWhite(x, y) == true and Board[y][x] == 'F')
			{
				Result++;
			}
		}
	}

	cout << Result;


	return 0;
}