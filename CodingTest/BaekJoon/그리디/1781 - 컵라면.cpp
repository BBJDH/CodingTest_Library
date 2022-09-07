/*
1781 - 컵라면

각 각 DeadLine 별로 가능한 최대의 Task 목록을 작성
먼저 입력 받은 Tasks를 DeadLine 순으로 정렬되어 출력되도록하고(DeadLine 가까운순, 보상 높은 순)
DeadLine이 1인 Task는 한개만 실행, DeadLine이 9인 Task들은 최대 9개 까지 수행 가능하므로

각 Level 별로 (큐가 비어있지 않다면)
Level = 1 이라면 DeadLine이 1인 Task들 중 가장 큰 보상 1개 까지를 우선순위큐 에 삽입, 1개만 남기고 가장 작은 보상을 삭제
 => 1Level 에서의 최대 보상 완성 (큐에서 1개만 뽑기 가능)
Level = 2 이라면 DeadLine이 2인 Task들 중 가장 큰 보상 2개 까지를 우선순위큐 에 삽입, 2개만 남기고 가장 작은 보상을 삭제
Level 1 자료를 포함하므로 2Level 에서의 최대 보상 완성 (큐에서 2개만 뽑기 가능)
Level = 3 이라면 DeadLine이 3인 Task들 중 가장 큰 보상 3개 까지를 우선순위큐 에 삽입, 3개만 남기고 가장 작은 보상을 삭제
3Level 에서의 최대 보상 완성 (큐에서 3개만 뽑기 가능)

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
1부터 CurrentLevel 시작, 해당 레벨보다 작거나 같은 DeadLine들을 현재 레벨 수만큼 삽입()
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