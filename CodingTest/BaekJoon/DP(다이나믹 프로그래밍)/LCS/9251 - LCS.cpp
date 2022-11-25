/*
 *9251 - LCS
 *
 *DP�� ���� �κм����� ���̸� �����Ѵٰ� �����غ���
 *�� ���� ���ĺ����� ��Ī�Ͽ� �� �������� ���Ѵ�.
 *DP�� �� �࿡�� N��° ���ڱ��� üũ�� �ִ� �κ� ������ ���̸� ����Ѵ�.
 *DP�� ��� ���̽��� �ѷ� ������
 *�� i��°�� ���ڸ� �ι�°���ڿ��� j��° ���ڿ��� ���Ҷ�
 *�� ���ڰ� ��ġ�ϴ� ���, �׷��� ���� ��� �ΰ����� ������
 *
 *�� ���ڰ� ��ġ�ϴ� ��� ���� ���ڿ����� ������̿� +1���ش�, ��
 *DP[i][j] = DP[i-1][j-1]+1 ���� ���̸� �ϳ� �÷� ������Ʈ ���ش�
 *DP[i-1][j-1]�� ���� �ֱ� ������Ʈ�� �ٷ� �������ڱ����� �ִ� ���̸� �ǹ��Ѵ�.
 *
 *�� ���ڰ� ��ġ���� �ʴ� ��� ���ǰ�츦 ���� ������Ʈ�� ���� ������Ʈ ������ ���� ���� ������
 *���� ������ ���� ������Ʈ ������ ���Ͽ� ���� ū ���� ����Ѵ�
 *�� DP[i][j] = max(DP[i-1][j], DP[i][j-1]) �̴�
 *
 *�̷��� ���� �ٸ� ���ڿ� ���� ��ŭ DP�� ����س��� ��
 *�Ǹ����� DP[size][size]�� ���� ū �κ� ������ ���̰� ����ִ�.
 */


#include <iostream>
#include <string>
using namespace  std;


int DP[1001][1001]{};


void LCS(string const& First, string const& Second)
{
	for (int i = 0; i < First.size(); i++)
	{
		for (int j = 0; j < Second.size(); j++)
		{
			if (First[i] == Second[j])
				DP[i + 1][j + 1] = DP[i][j] + 1;
			else
				DP[i + 1][j + 1] = max(DP[i + 1][j], DP[i][j + 1]);
		}
	}
	cout << DP[First.size()][Second.size()];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string firstStr{};
	string secondStr{};

	cin >> firstStr >> secondStr;

	LCS(firstStr, secondStr);

	return 0;
}