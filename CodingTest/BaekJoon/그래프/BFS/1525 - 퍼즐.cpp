/*
 *1525 - ����
 *
 *�켱 ������ ���� �� �ʿ䰡 �ִ�.
 *
 *Ȧ�� ũ���� ������ ��� 1���� �迭�� ���� �þ� ��������,
 *�� ������ �������� ���� ���� �߿� 0�� ������ ���� ���� �����ϴ� ������ ������
 *Ȧ���� ��� �ش� ������ Ǯ �� ����.
 *
 *��
 *
 *1 2 3
 *4 5 6
 *8 7 0
 *
 *�� �ÿ����� 1 2 3 4 5 6 8 7 0 ����
 *
 *0�� ���� �Ѵٸ� 6������ ���� ���� �������� �ʰ� 8���� �������� 7�� �����ϹǷ�
 *�� ���� 1�̴�. ��, Ǯ�� ���� �����̴�
 *
 *�ݸ鿡
 *1 2 3
 *4 8 5
 *7 0 6
 *��
 *1 2 3 4 8 5 7 0 6
 *0 0 0 0 3 0 1 0 0  =>4��
 *�� Ǯ �� �ִ� �����̴�.
 *
 *
 *BFS�� ���� ��� ��츦 ����Ž�������Ѵ�.
 *�뷮 32MB ������ �ɷ������Ƿ� �̸� �����Ͽ�
 *���ڿ��� �� ������ ���¸� �����Ѵ�
 *�� ��忡�� ���� ������ ������ string, 0�� ��ġ, ������ ������ Ƚ���� ����ü�� �ۼ��Ͽ�
 *BFSQueue�� �����Ѵ�.
 *
 *�� ���º��� 0�� ��ġ�� �����Ͽ� -3 -1 1 3 �� ���� ������ ������ �Ѱų� ���� ������ ������
 *�Ѿ�� ��츦 ����ó�� ���ش�. (%3==2, %3==0�� ���)
 *
 *���� ������� ������ ������ string�� ������ �ߺ��� �����ϱ� ���� set�� �����Ͽ�
 *�湮 ó���� �ؾ� �Ѵ�.
 *
 *Ž�� ���� "123456780"�� �����ٸ� ������ Ƚ���� ����ϰ� �����Ѵ�.
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