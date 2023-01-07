/*
 *14003 - ���� �� �����ϴ� �κ� ���� 3
 *
 *���� ���̸� ���ϴµ� ����� �迭�� �ϳ� �����Ͽ� ù ������ ����ְ� �̰Ͱ� �񱳸� ���� ������̸� ���س�����
 *����� ������ ����
 *
 *������ �迭(���� LIS_Sequence�� �Ѵ�)�� ù ���� �Է��Ѵ�.
 *���� ������(���� Num)�� LIS_Sequence�� �� �� ���ڿ� ���Ͽ� LIS_Sequence�� �������� ũ�ٸ� �ڿ� �������� ���δ�
 *(LIS_Sequence.push_back)
 *
 *����, inputNum�� LIS_Sequence�� �������� ũ�� �ʴٸ� LIS_Sequence�� ���� �߿� inputNum���� ū ù��° ���� ��ü�Ѵ�.
 *(N���� Ž���ϸ� ��ü ������ �ð����⵵�� Ŀ���Ƿ� logn�� �̺�Ž���� Ȱ���Ѵ�.
 *lower_bound(...,inputNum)�� ����� �˻��� �����ߴٸ� inputNum�� ���� ũ�� �����ߴٸ� �� ���� ��ü�Ѵ�.)
 *
 *Ǯ�� ������ ���ø� ����
 *
 * 1 3 2 4 0
 * ���� ���� ���̸� ���Ѵٸ�,
 *
 * 1�� ���� �ְ�,
 * 1
 * 1 3 ->3�� 1���� ũ�Ƿ� �ڿ� �߰��Ѵ�
 * 1 2 ->�������� 2�̹Ƿ� 2���� ū ù ���� lower_bound�� �˻��Ͽ� ��ü�Ѵ�.
 * 1 2 4 ->4�� 2���� ũ�Ƿ� �ڿ� �߰�
 * 0 2 4 -> 0���� ū ù ����1�� ��ü
 *
 * �� 1 3 2 4 0 �� ������̴� 3�̴�(0 2 4)
 *
 *���� 0 2 4 �� ���� ������� ������ �ƴϴ�.
 *�� ������ ������̸� ���ϸ� �ǹǷ� �̴�� ���������, ���ذ� �Ǵ� ������ ���ϰ� �ʹٸ� 4�� Ȥ�� 5�� Ǯ�̸� Ȯ���ϸ� �ȴ�.
 *
 */
 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> LIS_Sequence{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputNum{};

		cin >> inputNum;

		if (i == 0)
		{
			LIS_Sequence.push_back(inputNum);
			continue;
		}

		auto iter = lower_bound(LIS_Sequence.begin(), LIS_Sequence.end(), inputNum);

		if (iter != LIS_Sequence.end())
		{
			*iter = inputNum;
		}
		else
		{
			LIS_Sequence.push_back(inputNum);
		}
	}
	cout << LIS_Sequence.size();

	return 0;
}