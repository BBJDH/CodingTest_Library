/*
 * 1365 - ���� ������
 *
 *���� �Ϲ����� �����ص�, ������� �����ص�
 *
 *�Է� ���� ������ �����ϴ� �κ� ������ ������ �ȴ�.
 *
 *�� �� �������� �ʴ� ������ ���� ������ �̹Ƿ�
 *
 *�����ϴ� �κм����� ������̸� ���ϰ� �̰��� N���� ������ ������ ��µȴ�.
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
	cin >> N;
	vector<int> Sequence{};

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		if (i == 0)
		{
			Sequence.emplace_back(inputNum);
			continue;
		}

		if (inputNum > Sequence[Sequence.size() - 1])
		{
			Sequence.emplace_back(inputNum);
		}
		else
		{
			//�������� �ΰ��̻� ���� �����뿡 ����Ǿ� ���� �����Ƿ�
			//else�� �κм����� ���� ū�� ���� inputNum�� ���� ��� �̴�.

			auto iter = lower_bound(Sequence.begin(), Sequence.end(), inputNum);
			*iter = inputNum;
		}
	}

	int const result = N - static_cast<int>(Sequence.size());
	cout << result;

	return 0;
}