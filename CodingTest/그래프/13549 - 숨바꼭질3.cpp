
/*
13549 - ���ٲ���3

�����̵��� ����� 0�ΰ��� ��������
�ѹ� ���� ��忡 ���ؼ� �湮�� �ǽ��Ҷ� ��������� 2�� ���Ͽ� ��� �湮ó���� �Ѵ�
�������� �߿��ϴ� �����̵��� ������ ť�� ���� �Ŀ� +1 -1������ �־��ش�(�湮 �켱����, +1�� -1�� ������ �����ϴ�)
���� ������ �����شٸ� ť���� ������������ ��ǥ������ ������ ��尡 ���� ���� �ð��� �ȴ�.

*/

#include<iostream>
#include<queue>
#include<bitset>

using namespace std;

bitset<100001> Visit{};

struct Step
{
	int Pos;
	int Count;
};

queue<Step> BFS{};

int StartPos = 0;
int DestPos = 0;

void Push(Step const& NextPos)
{
	if (NextPos.Pos >= 0 and NextPos.Pos <= 100000 and Visit[NextPos.Pos] == false)
	{
		Visit[NextPos.Pos] = true;
		BFS.push(NextPos);
	}
}

void Teleport(Step const& CurrentPos)
{
	int Pos = CurrentPos.Pos;
	while (Pos <= 100000)
	{
		Push({ Pos ,CurrentPos.Count });
		Pos *= 2;
	}
}

void VisitNextNode(Step const& CurrentPos)
{
	if (CurrentPos.Pos != 0)
		Teleport(CurrentPos);
	Push({ CurrentPos.Pos - 1, CurrentPos.Count + 1 });
	Push({ CurrentPos.Pos + 1, CurrentPos.Count + 1 });
}

void Solution()
{
	Step CurrentStep{};
	while (!BFS.empty())
	{
		CurrentStep = BFS.front();
		BFS.pop();
		if (CurrentStep.Pos == DestPos)
			break;
		VisitNextNode(CurrentStep);
	}
	cout << CurrentStep.Count;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> StartPos >> DestPos;

	Push({ StartPos,0 });
	Solution();
	return 0;
}
