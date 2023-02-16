/*
 *10816 - ���� ī�� 2
 *
 *�̺�Ž���� ���� Ǯ����.
 *
 *ó�� �Է¹��� N�� �迭(InputSequence)�� �����Ѵ�.
 *���� ���� �Է¹��� ������ �̺�Ž������ InputSequence���� Ž���Ѵ�.
 *lower_bound()�� ���� ù ���ۼ��� ã�´�
 *���� ã�� ���� ��ġ�ϴ��� Ȯ���Ͽ� ���� ã�� ���ߴٸ� 0�� ��½�Ų��
 *���� ã�Ҵٸ� upper_bound()�� ���� end ������ ã�� lower_bound()������ ���� ����Ѵ�.
 *
 *(����, nlogn, �̺�Ž�� logn)
 *
 *
 *
 *
 *�ذ��� 2(���� ��� 1)
 *
 *�迭���� ������ �̿��� �ð��� �����ų �� �ִ�.
 *
 *�ԷµǴ� ���� -õ�� ~ +õ�� �̹Ƿ� 2õ������ �迭�� �����ϰ� ���⿡ �Է¹��� ������ �����Ѵ�.
 *�Է¹��� ���� �ε����� �����Ͽ� ++ ó���Ѵ�. �̷��� �Էµ� ������ �迭�� �����ϰ�
 *
 *���� M���� ���ڵ��� �ԷµǸ� �迭�� ���� �о ����ϸ� �ȴ�
 *
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

	vector<int>InputSequence{};
	vector<int>SearchNums{};
	int N = 0, M = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		InputSequence.push_back(inputNum);
	}
	sort(InputSequence.begin(), InputSequence.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		vector<int>::iterator Start = lower_bound(InputSequence.begin(), InputSequence.end(), inputNum);
		if (*Start != inputNum)
		{
			cout << 0 << " ";
			continue;
		}
		vector<int>::iterator End = upper_bound(InputSequence.begin(), InputSequence.end(), inputNum);
		cout << End - Start << " ";

	}

	return 0;
}