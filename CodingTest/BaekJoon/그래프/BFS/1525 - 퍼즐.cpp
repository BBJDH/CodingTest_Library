/*
 *1525 - 퍼즐
 *
 *우선 퍼즐을 이해 할 필요가 있다.
 *
 *홀수 크기의 퍼즐인 경우 1차원 배열로 수를 늘어 놓았을때,
 *각 숫자의 기준으로 다음 수들 중에 0을 제외한 작은 수가 존재하는 갯수의 총합이
 *홀수개 라면 해당 퍼즈은 풀 수 없다.
 *
 *즉
 *
 *1 2 3
 *4 5 6
 *8 7 0
 *
 *를 늘여보면 1 2 3 4 5 6 8 7 0 으로
 *
 *0을 제외 한다면 6까지는 작은 수가 존재하지 않고 8에서 다음수인 7이 존재하므로
 *총 합은 1이다. 즉, 풀수 없는 퍼즐이다
 *
 *반면에
 *1 2 3
 *4 8 5
 *7 0 6
 *은
 *1 2 3 4 8 5 7 0 6
 *0 0 0 0 3 0 1 0 0  =>4개
 *로 풀 수 있는 퍼즐이다.
 *
 *
 *BFS를 통해 모든 경우를 완전탐색진행한다.
 *용량 32MB 제한이 걸려있으므로 이를 감안하여
 *문자열로 각 퍼즐의 상태를 저장한다
 *즉 노드에는 현재 퍼즐의 상태인 string, 0의 위치, 퍼즐을 움직인 횟수를 구조체로 작성하여
 *BFSQueue에 삽입한다.
 *
 *각 상태별로 0의 위치를 저장하여 -3 -1 1 3 을 더해 퍼즐의 범위를 넘거나 왼쪽 오른쪽 벽에서
 *넘어가는 경우를 예외처리 해준다. (%3==2, %3==0인 경우)
 *
 *각각 만들어진 퍼즐의 상태인 string은 추후의 중복을 방지하기 위해 set에 삽입하여
 *방문 처리를 해야 한다.
 *
 *탐색 도중 "123456780"을 만난다면 움직인 횟수를 출력하고 종료한다.
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct Node
{
	string State;
	int Index;
	int Step;
};

set<string> Visit{};
queue<Node> BFS_Queue{};
int Direction[4] = { -3,-1,1,3 };

bool CheckSolvable(string const& Start)
{
	int count = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = i; j < 9; j++)
		{
			if (Start[j] != '0' and Start[i] > Start[j])
				count++;
		}
	}

	if (count % 2 == 1)
		return false;
	return true;
}
void Push(Node const& Next)
{
	if (Visit.find(Next.State) == Visit.end())
	{
		Visit.insert(Next.State);
		BFS_Queue.push(Next);
	}
}

bool RoundEdges(Node const& Current)
{
	string const target{ "123456780" };
	for (int i = 0; i < 4; i++)
	{
		Node Next{};
		Next.Index = Current.Index + Direction[i];

		if (Next.Index < 0 or Next.Index >8 or (Current.Index % 3 == 2 and i == 2) or (Current.Index % 3 == 0 and i == 1))
			continue;


		Next.State = Current.State;
		swap(Next.State[Next.Index], Next.State[Current.Index]);
		Next.Step = Current.Step + 1;

		if (Current.State == target)
			return true;
		Push(Next);
	}
	return false;
}

void BFS(string const Start)
{
	int result = 0;
	int const index = static_cast<int>(Start.find('0'));

	Push({ Start,index,0 });

	while (!BFS_Queue.empty())
	{
		Node const current = BFS_Queue.front();
		BFS_Queue.pop();
		if (RoundEdges(current) == true)
		{
			result = current.Step;
			break;
		}

	}
	cout << result;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int i = 0;
	string start{};
	for (int i = 0; i < 9; i++)
	{
		string inputNum{};
		cin >> inputNum;
		start += inputNum;
	}
	if (CheckSolvable(start) == false)
	{
		cout << -1;
		return 0;
	}
	BFS(start);

	return 0;
}