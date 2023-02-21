/*
 *1158 - �似Ǫ�� ����
 *
 *������ �䱸���״�� �����غ��� ������ ���� ����ȴ�.
 *
 *
 *1 2 3 4 5 6 7 - 3
 *4 5 6 7 1 2   - 6
 *7 1 2 4 5     - 2
 *4 5 7 1       - 7
 *1 4 5         - 5
 *1 4           - 1
 *4             - 4
 *
 *�� K��°�� �ö����� ť���� pop�Ͽ� push�� �ݺ��Ѵ�.
 *�̿ܿ� ", "�� ">" ����ó���� ���ָ� �ȴ�.
 *
 */

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, K = 0;
	queue<int> Josephus_Queue{};
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		Josephus_Queue.push(i);
	}
	cout << "<";
	int count = 0;
	while (!Josephus_Queue.empty())
	{
		int currentNum = Josephus_Queue.front();
		Josephus_Queue.pop();
		count++;

		if (count == K)
		{
			cout << currentNum;
			count = 0;

			if (Josephus_Queue.empty())
				cout << ">";
			else
				cout << ", ";

			continue;
		}
		Josephus_Queue.push(currentNum);
	}


	return 0;
}