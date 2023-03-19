/*
 *11052 - ī�� �����ϱ�
 *
 *
 *ó���� ����/ī�尹�� �� �������� �����Ͽ� Ǯ�������
 *
 *�׽�Ʈ ���̽��� ��� ����ϰ�
 *
 *���� �׽�Ʈ ���̽������� ������ ������� �˰ԵǾ���.
 *
 * 12
 * 1 1 6 8 11 1 1 1 1 1 1 1
 * Ans: 25
 *
 * ���ķ� Ǯ�� 24�� ��µǸ� ������
 * 6 8 11�� 3�� 4�� 5���� �����ؾ� �Ѵ�.
 *
 * ������ ���̳��� ���α׷����� ���� ī�� ��� ������ 1�� ������
 * �޸������̼� �ϴ� ����� �����ߴ�
 *
 * �迭�� DP[������ ī���� ��] = �ִ� ����
 *
 * ���� ���Ͽ� ���� ������� ī�� ������ DP�� �Է��ϰ�
 *
 * DP[1] = �Է� ���� �� (�� �̻� �ٸ� ������ ����)
 * DP[2] = {DP[2], DP[1]+DP[1]} ���� �ִ밪
 * DP[3] = {DP[3], DP[2]+DP[1], DP[1]+DP[1]+DP[1]} ���� �ִ밪
 *
 *	...
 *
 *	�� ������� DP�迭�� �޸������̼� �Ѵ�.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//[NumOfCard]
int DP[1000]{};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TotalNum = 0;
	cin >> TotalNum;

	for (int i = 1; i <= TotalNum; i++)
	{
		cin >> DP[i];
	}

	for (int NumOfCards = 1; NumOfCards <= TotalNum; NumOfCards++)
	{
		for (int i = 1; i <= NumOfCards; i++)
		{
			DP[NumOfCards] = max(DP[NumOfCards], DP[NumOfCards - i] + DP[i]);
		}
	}

	cout << DP[TotalNum];

	return 0;
}