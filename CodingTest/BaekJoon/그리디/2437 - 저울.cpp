/*
 *2437 - ����
 *
 *�Է¹��� �ߵ��� ������������ ������ ��
 *���� �� ���� �������� �������� ���±��� ������ ������+1��
 *������ �ö�� �����ߺ��� �۴ٸ� ���� ������+1�� ����Ѵ�.
 *
 * 7
 * 3 1 6 2 7 30 1
 * 1 1 2 3 6 7 30
 *
 * ������
 * 1 2 4 7 13 20
 *            ���⼭ 20 + 1 �� ���� ���� 30���� �����Ƿ� 21�� ���
 *
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Nums{};
vector<int> DP{};

void Solution()
{
	sort(Nums.begin(), Nums.end());


	int sum = 0;

	for (int i = 0; i < Nums.size(); i++)
	{
		if (sum + 1 < Nums[i])
		{
			cout << sum + 1;
			return;
		}
		sum += Nums[i];
	}
	cout << sum + 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		Nums.push_back(inputNum);
	}

	Solution();


	return 0;
}