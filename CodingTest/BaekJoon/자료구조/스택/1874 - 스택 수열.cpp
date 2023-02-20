/*
 *1874 - ���� ����
 *
 *������ �Ѱ� �����صΰ� ���⿡ �����������θ� �����Ѵ�
 *
 *�����ϴ� ������ 1���� ������ N���� Push �Ѵ�
 *
 *���ÿ��� Pop�� �Ѵٸ� �� ���� ������ ��ϵȴ�.
 *
 *�� ���� 4 3 6 8 7 5 2 1 �� ����ٸ�
 *
 *1 2 3 4 ������ ���ÿ� �ְ�(+ �׹�) ���⼭ �ٽ� 4 3 �� �̴´� (-�ι�)
 *
 *���� �־��� ���� 5�����̹Ƿ� 5 6�� �ְ�(+�ι�) �ٽ� ���⼭ 6�� �̴´� (-)
 *
 *���� ���� 7 �� ���� push �ϰ� (+�ι�) �� ���ڴ� 1 2 5 7 8 ��
 *
 *������ top�� 8���� �� �̾Ƽ� ������ ����Ѵ�.(- 5��)
 *
 *
 *
 *������ ���� ������� ���� �� ���� ���� � ����ΰ�?
 *
 *N������ ��ȣ�� ��� Push �ϰ� �ش� ������ȣ�� ã�� �� ���� ��� �̴�
 *
 *�� �̷���츦 ������ PushNum�� N�� �ʰ��Ͽ� ���þȿ� ���ԵǷ� �Ѵ�.
 *
 *������ �� ��� NO�� ����ϰ� ���α׷��� ����ó���Ѵ�.
 *
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	vector<int> Sequence{};
	stack<int>Temp{};
	vector<char> Result{};
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		Sequence.push_back(inputNum);
	}

	int index = 0;
	int pushNum = 1;
	while (index < N)
	{
		if (Temp.empty() or Temp.top() != Sequence[index])
		{
			if (pushNum > N)
			{
				cout << "NO";
				return 0;
			}

			Temp.push(pushNum);
			pushNum++;
			Result.push_back('+');
			continue;
		}

		Temp.pop();
		index++;
		Result.push_back('-');


	}

	for (char const elem : Result)
	{
		cout << elem << "\n";
	}


	return 0;
}