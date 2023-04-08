/*
 *1021 - ȸ���ϴ� ť
 *
 *
 *�׸��� �̿��� Ǯ����
 *
 * 1 2 3 4 5 6 7 8 9 10		- 0��
 * 2 3 4 5 6 7 8 9 10 1    - 1��
 * 3 4 5 6 7 8 9 10 1    - 1��
 * 1 3 4 5 6 7 8 9 10    - 2��
 * 10 1 3 4 5 6 7 8 9    - 3��
 * 9 10 1 3 4 5 6 7 8    - 4��
 * 10 1 3 4 5 6 7 8    - 4��
 * ...
 * 5 6 7 8 10 1 3 4    - 8��
 *
 *
 *�����غ��� �Էµ� ����� + -���־� ����� ����س����� �ȴ�.
 *
 * 1 2 3 4 5 6 7 8 9 10
 * 2��° �� �ʿ�, ������ 2-1�� Ȥ�� �ڷ� (10-2)+1��
 * ������ 1���� ���� 2, 9, 5 ���� 2�� ���������� ������ ������ 1��+1 ��ŭ ���� �� 7,5
 * 3 4 5 6 7 8 9 10 1	- 1��
 * 7��° �� �ʿ�, ������ 7-1�� Ȥ�� �ڷ� (9-7)+1��
 * �ڷ� 3���� ���� 7, 3���� 7���� ���� ���������� ���� �̾ƾ��� 3��° ���� 3-1��ŭ ����
 * 10 1 3 4 5 6 7 8	- 4��(7��° �� �ʿ�, ������ 7-1�� Ȥ�� �ڷ� (9-7)+1��)(7, 3)
 *
 * �ϳ��� PopNum�� �������� Result�� ����ϰ� ���� PopNum���� �����θ�ŭ �����Ѵ�.
 * PopNum���� ���۽� ������ �ǰų� ť�� ����� �Ѿ�� ��쿡 ���� ����ó���� ����� �Ѵ�.
 *
 *�䱸���״�� ���� ������ Ǯ�̵� �����ϴ�.
 *
 */

#include <iostream>
#include <vector>


using namespace std;

void MoveNums(vector<int>& PopNum, int const Index, int const MoveAmount, int& Size)
{
	if (MoveAmount >= 0)
	{

		for (int i = Index; i < PopNum.size(); i++)
		{
			PopNum[i] = (PopNum[i] + MoveAmount) % Size;
		}
	}
	else
	{
		for (int i = Index; i < PopNum.size(); i++)
		{
			PopNum[i] = (PopNum[i] + MoveAmount);
			if (PopNum[i] < 0)
			{
				PopNum[i] = Size + PopNum[i];
			}
		}
	}
	Size--;
};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int SizeOfQueue = 0, CountOfPop = 0;
	int Result = 0;
	vector<int> PopNum{};
	cin >> SizeOfQueue >> CountOfPop;
	for (int i = 0; i < CountOfPop; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		PopNum.push_back(InputNum);
	}

	for (int i = 0; i < PopNum.size(); i++)
	{
		if (PopNum[i] - 1 < (SizeOfQueue - PopNum[i]) + 1)
		{
			//���� �̵��� �� ����
			Result += PopNum[i] - 1;
			MoveNums(PopNum, i + 1, -PopNum[i], SizeOfQueue);
		}
		else
		{
			//������ �̵��� �� ����
			Result += SizeOfQueue - PopNum[i] + 1;
			MoveNums(PopNum, i + 1, SizeOfQueue - PopNum[i], SizeOfQueue);
		}
	}
	cout << Result;
	return 0;
}