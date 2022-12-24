/*
 *11399 - ATM
 *
 *���� ���� ������ ��ٸ��� ���� �ִܽð� �̹Ƿ�
 *
 *�Է� ���� ������ ������������ ����,
 *
 *�� ���������� ������ ����Ѵ�.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> inputNums{};

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		inputNums.push_back(inputNum);
	}

	sort(inputNums.begin(), inputNums.end());

	int sum = 0;
	int result = 0;
	for (int i = 0; i < inputNums.size(); i++)
	{
		sum += inputNums[i];
		result += sum;
	}
	cout << result;
	return 0;
}