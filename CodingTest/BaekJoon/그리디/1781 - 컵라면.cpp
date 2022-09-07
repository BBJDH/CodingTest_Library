/*
1781 - �Ŷ��

�� �� DeadLine ���� ������ �ִ��� Task ����� �ۼ�
���� �Է� ���� Tasks�� DeadLine ������ ���ĵǾ� ��µǵ����ϰ�(DeadLine ������, ���� ���� ��)
DeadLine�� 1�� Task�� �Ѱ��� ����, DeadLine�� 9�� Task���� �ִ� 9�� ���� ���� �����ϹǷ�

�� Level ���� (ť�� ������� �ʴٸ�)
Level = 1 �̶�� DeadLine�� 1�� Task�� �� ���� ū ���� 1�� ������ �켱����ť �� ����, 1���� ����� ���� ���� ������ ����
 => 1Level ������ �ִ� ���� �ϼ� (ť���� 1���� �̱� ����)
Level = 2 �̶�� DeadLine�� 2�� Task�� �� ���� ū ���� 2�� ������ �켱����ť �� ����, 2���� ����� ���� ���� ������ ����
Level 1 �ڷḦ �����ϹǷ� 2Level ������ �ִ� ���� �ϼ� (ť���� 2���� �̱� ����)
Level = 3 �̶�� DeadLine�� 3�� Task�� �� ���� ū ���� 3�� ������ �켱����ť �� ����, 3���� ����� ���� ���� ������ ����
3Level ������ �ִ� ���� �ϼ� (ť���� 3���� �̱� ����)

*/
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;


struct Task
{
	int Deadline;
	int Reward;
};
struct CMP
{
	bool operator()(Task const& A, Task const& B)
	{
		if (A.Deadline == B.Deadline)
			return A.Reward < B.Reward;
		return A.Deadline > B.Deadline;
	}
};

priority_queue<Task, vector<Task>, CMP> Tasks{};
priority_queue<int> Rewards{};
int CurrentLevel = 1;
int TaskSize = 0;


void PushReward()
{
	int MaxPush = CurrentLevel;
	while (!Tasks.empty() and Tasks.top().Deadline <= CurrentLevel)
	{
		if (MaxPush != 0)
		{
			Rewards.push(-Tasks.top().Reward);
			MaxPush--;
		}
		Tasks.pop();
	}
	while (Rewards.size() > CurrentLevel)Rewards.pop();
}
/*
1���� CurrentLevel ����, �ش� �������� �۰ų� ���� DeadLine���� ���� ���� ����ŭ ����()
*/
void Solution()
{
	while (!Tasks.empty())
	{
		PushReward();

		CurrentLevel++;
	}
	//Print
	int Sum = 0;
	while (!Rewards.empty())
	{
		Sum += -Rewards.top();
		Rewards.pop();
	}
	cout << Sum;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> TaskSize;

	while (TaskSize--)
	{
		int InputDeadLine = 0;
		int InputReward = 0;
		cin >> InputDeadLine >> InputReward;
		Tasks.push({ InputDeadLine , InputReward });
	}

	Solution();
	return 0;
}