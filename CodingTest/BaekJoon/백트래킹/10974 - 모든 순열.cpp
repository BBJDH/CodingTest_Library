/*
 *10974 - ��� ����
 *
 *��Ʈ��ŷ�� �̿��� ��� ����� ���� Ž���Ѵ�.
 *
 *1���� N���� �湮ó���� �ϸ� ���ʴ�� ���ڸ� �ְ�
 *��������� ���� ���ڿ��� �����ذ��� Nũ���� ������ �����
 *���� ���̰� N�� �����Ѵٸ� ���ó�� �Ѵ�.
 */


#include <iostream>
#include <vector>

using namespace std;

bool Visit[9]{};

void BackTracking(int N, vector<int> Sequence)
{
	if (Sequence.size() == N)
	{
		for (int const elem : Sequence)
			cout << elem << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (Visit[i] == false)
		{
			Sequence.push_back(i);
			Visit[i] = true;
			BackTracking(N, Sequence);
			Visit[i] = false;
			Sequence.pop_back();
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	BackTracking(N, {});

	return 0;
}