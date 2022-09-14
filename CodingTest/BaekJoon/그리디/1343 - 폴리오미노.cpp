/*
1343 - �������̳�
.�� .���� �״�� ����ϰ�
4�� ����� 2�� ���´ٸ� ������ BB�� �������� �ѹ� ����ϰԵȴ�
�� �ܴ̿� ��� 4�� ������ ���Ƿ� ����/4 ��ŭ AAAA�� ���

*/

#include<iostream>
#include<string>
#include<vector>


using namespace std;

vector<int>Xs{};

void PrintPolyomino(int const Num)
{
	int AAAA = Num / 4;
	int BB = 0;
	if (Num % 4 == 2)
	{
		BB = 1;
	}
	while (AAAA--)
	{
		cout << "AAAA";
	}
	if (BB)
		cout << "BB";

}

void Solution()
{
	for (int i = 0; i < Xs.size(); i++)
	{
		if (Xs[i] == 0)
			cout << ".";
		else
			PrintPolyomino(Xs[i]);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	cin >> InputStr;

	int Index = 0;
	while (Index < InputStr.size())
	{
		int Size = 0;
		if (InputStr[Index] == '.')
		{
			Xs.push_back(0);
			Index++;
		}
		else
		{
			while (InputStr[Index] == 'X')
			{
				Size++;
				Index++;
			}
			if (Size % 2)
			{
				cout << -1;
				return 0;
			}
			Xs.push_back(Size);
		}
	}
	Solution();

	return 0;
}