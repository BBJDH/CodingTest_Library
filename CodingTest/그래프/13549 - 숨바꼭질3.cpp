
/*
13549 - 숨바꼭질3

순간이동은 비용이 0인것을 감안하자
한번 지정 노드에 대해서 방문을 실시할때 지정노드의 2를 곱하여 모두 방문처리를 한다
순서또한 중요하다 순간이동한 노드부터 큐에 넣은 후에 +1 -1순으로 넣어준다(방문 우선순위, +1과 -1의 순서는 무관하다)
위의 순서만 지켜준다면 큐에서 빠져나왔을때 목표지점에 도달한 노드가 가장 빠른 시간이 된다.

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
