/*
 *
 *4883 - �ﰢ �׷���
 *
 *ù�ٿ����� DP�� ��� ������ �ջ����� ����Ѵ�
 *
 *�״������� DP�� ���ٿ����� �� �ּҰ����� ���� ���Ѵ�
 *
 *���� �������ٿ� �����ϸ� DP[3]������ �ּڰ��� ��� ���� ���� ���
 *
 *
 */



#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	int TestCase = 1;
	vector<long long>DP{};
	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
		{
			vector<long long> inputNums{};
			inputNums.resize(3);

			for (int i = 0; i < 3; i++)
			{
				cin >> inputNums[i];
			}


			if (i == 0)
			{
				DP = inputNums;
				DP[0] = 1234567890;
				DP[1] = inputNums[1];
				DP[2] = DP[1] + inputNums[2];

				continue;
			}
			if (i == 1)
			{
				//�ι�°���� ù���� ��� ������ ���õȴ�
				long long centerNum = DP[1];

				DP[0] = inputNums[0] + centerNum;
				DP[1] = inputNums[1] + min(DP[2], min(DP[0], centerNum));
				DP[2] = inputNums[2] + min(DP[2], min(DP[1], centerNum));
				continue;
			}
			long long leftDP = DP[0];
			long long centerDP = DP[1];

			DP[0] = inputNums[0] + min(DP[0], DP[1]);
			DP[1] = inputNums[1] + min(min(DP[0], leftDP), min(DP[1], DP[2]));
			DP[2] = inputNums[2] + min(DP[2], min(DP[1], centerDP));
		}
		cout << TestCase << ". " << DP[1] << "\n";
		TestCase++;
	}


	return 0;
}