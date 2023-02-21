/*
 *1158 - 요세푸스 문제
 *
 *문제의 요구사항대로 연산해보면 다음과 같이 진행된다.
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
 *즉 K번째가 올때까지 큐에서 pop하여 push를 반복한다.
 *이외에 ", "와 ">" 구분처리를 해주면 된다.
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