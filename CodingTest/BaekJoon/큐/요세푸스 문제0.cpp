
/*
11866 - �似Ǫ�� ���� 0

�ܼ� ť ����, ���ϴ� ���� ��� ������,
������ ������ �ٽ� Push�� �ݺ�
ť�� ��� Ż��

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
