/*
 *
 *2501 - ��� ���ϱ�
 *
 *�Է¹��� �� N�� �� �����̹Ƿ� ���Ʈ������ Ǯ�� �����ϴ�
 *
 *1���� �����Ͽ� N���� ���������� ���� ��� ���� �迭�� �ִ´�
 *
 *���� �Է¹��� K��° ���� ���, ���� K�� ��ü ��� �迭���� ũ�ٸ� 0�� ����Ѵ�.
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0, K = 0;
	vector<int> Factors{};

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			Factors.push_back(i);
		}
	}

	if (K > Factors.size())
	{
		cout << 0;
	}
	else
	{
		cout << Factors[K - 1];
	}



	return 0;
}