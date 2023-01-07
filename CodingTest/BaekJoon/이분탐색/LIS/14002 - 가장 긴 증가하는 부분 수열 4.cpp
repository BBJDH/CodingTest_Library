/*
 *14003 - ���� �� �����ϴ� �κ� ���� 4
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
 * ������ �������� �䱸�ϴ°��� ���� ���� �������� �Ӹ��ƴ϶� �ش� ������ ����̴�.
 * ���� Ǯ�̹�����δ� 0 2 4�� ���ذ� �� �� ���� (���ش� 1 2 4 �Ǵ� 1 3 4 �̴�)
 *
 * ������ ������ ���� �˰����� �߰��Ѵ�.
 *
 *�ԷµǴ� inputNum�� ���� LIS_Sequence�� ��ü�ǰų� �߰��Ǵ� �ε����� ����صд�
 *�� ���� �迭�� ����� ������̸� ���ϴ°������� LIS_Sequence�� �����ߴ� �ε����� ����صξ��ٰ�
 *������̸� ���� �� ��ϵ� �ε����� ���� ������� ������ ��� ���ڸ� ã�Ƴ��� ���̴�.
 *
 *���� ������ ���ø� ���ٸ�
 *
 * 1�� ���� �ְ�,
 * 1									-> [1(0) 3 2 4 0] ()���� ǥ�õǴ� �ε����̴�
 * 1 3 ->3�� 1���� ũ�Ƿ� �ڿ� �߰��Ѵ�   -> [1(0) 3(1) 2 4 0]
 * 1 2 ->�������� 2�̹Ƿ� 2���� ū ù ���� lower_bound�� �˻��Ͽ� ��ü�Ѵ�.	-> [1(0) 3(1) 2(1) 4 0]
 * 1 2 4 ->4�� 2���� ũ�Ƿ� �ڿ� �߰�	-> [1(0) 3(1) 2(1) 4(2) 0]
 * 0 2 4 -> 0���� ū ù ����1�� ��ü	-> [1(0) 3(1) 2(1) 4(2) 0(0)]
 *
 * �̷��� �Ϸ�� [1(0) 3(1) 2(1) 4(2) 0(0)] �� ���� N�� ����� �鿩 ������ ã�Ƴ���.
 * ������ ũ��� ������ 3���� ���������Ƿ� ������ ũ�Ⱑ 3�� �迭���� �̸� �� �� �ִ�
 *
 * ���� [1(0) 3(1) 2(1) 4(2) 0(0)] ���� �ڿ������� Ž���Ͽ� 2���� ���ʴ�� 0���� ã�Ƴ�����
 * -> 4 2 1 ������ ã������(����� N)
 *
 * �̰��� �Ųٷ� ����ϱ� ���� stack�� ����ߴ�.
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct _int2
{
	int Num;
	int Index;
};

vector<_int2> Nums{};
vector<int> LIS_Sequence{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		_int2 inputNum{};

		cin >> inputNum.Num;

		if (i == 0)
		{
			LIS_Sequence.push_back(inputNum.Num);
			inputNum.Index = static_cast<int>(LIS_Sequence.size()) - 1;
			Nums.push_back(inputNum);
			continue;
		}

		auto iter = lower_bound(LIS_Sequence.begin(), LIS_Sequence.end(), inputNum.Num);

		if (iter != LIS_Sequence.end())
		{
			*iter = inputNum.Num;
			inputNum.Index = static_cast<int>(iter - LIS_Sequence.begin());
		}
		else
		{
			LIS_Sequence.push_back(inputNum.Num);
			inputNum.Index = static_cast<int>(LIS_Sequence.size()) - 1;
		}
		Nums.push_back(inputNum);
	}
	//������ ����������� ����ϱ� ���� stack ���
	int index = static_cast<int>(LIS_Sequence.size()) - 1;
	stack<int> result{};

	for (int i = static_cast<int>(Nums.size()) - 1; i >= 0; i--)
	{
		if (Nums[i].Index == index)
		{
			result.push(Nums[i].Num);
			index--;
		}
	}
	cout << result.size() << "\n";
	while (!result.empty())
	{
		cout << result.top() << " ";
		result.pop();
	}
	return 0;
}