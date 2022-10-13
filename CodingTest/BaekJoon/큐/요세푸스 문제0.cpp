
/*
11866 - 요세푸스 문제 0

단순 큐 문제, 원하는 수만 골라서 빼내고,
나머지 수들은 다시 Push를 반복
큐가 비면 탈출

*/


#include<iostream>
#include<queue>

using namespace std;

queue<int> Josephus_Queue{};
int MaxNum = 0;
int K = 0;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> MaxNum >> K;

	for (int i = 1; i <= MaxNum; i++)
		Josephus_Queue.push(i);

	int PushCount = 0;
	cout << "<";
	while (!Josephus_Queue.empty())
	{
		int PopNum = Josephus_Queue.front();
		Josephus_Queue.pop();
		PushCount++;

		if (PushCount % K)
			Josephus_Queue.push(PopNum);
		else
		{
			cout << PopNum;
			if (Josephus_Queue.empty())
				cout << ">";
			else
				cout << ", ";
		}

	}

	return 0;
}
