/*
12851 - 숨바꼭질 2

방문처리를 큐에 넣기전에 처리하는게 아니라, 큐에서 꺼내면서 방문처리를 해주면 된다.

예제를 계산해보면

5
[4 6 10] 5방문
6 10 [3 X 8] 4방문
10 3 8 [X 7 12] 6방문
3 8 7 12 [9 11 20] 10방문
8 7 12 9 11 20 [2 X X] 3방문
7 12 9 11 20 2 [7 9 16] 8방문
12 9 11 20 2 7 9 16 [X X 14] 7방문
9 11 20 2 7 9 16 [11 13 24] 12방문
11 20 2 7 9 16 11 13 24 [X X 18] 9중복
11 20 2 7 9 (16) 11 13 24 (18)
.
.
.
여기서 (16)과 (18)이 각각 뽑아져 나오면서 17로 기록되고,
나머지 수들은 초과하거나 방문기록에 걸려서 17에 도달 할 수없다

즉 정리하면 처음 너비탐색 17이 되는 Time의 중복방문을 허용하고,
그 다음 탐색의 중복방문은 허용하지 않는 방법론이다.

*/

#include<iostream>
#include<queue>

using namespace std;

struct _int2
{
	int Pos;
	int Time;
};

queue<_int2> BFS_Queue{};
bool Visit[100001]{};
int N = 0, K = 0;
int MinTime = -1;
int TotalCount = 0;

void Push(_int2 const& Next)
{
	if (Next.Pos >= 0 and Next.Pos < 100001 and Visit[Next.Pos] == false)
	{
		BFS_Queue.push(Next);
	}
}

void RoundEdges(_int2 const& Current)
{
	Push({ Current.Pos - 1, Current.Time + 1 });
	Push({ Current.Pos + 1, Current.Time + 1 });
	Push({ Current.Pos * 2, Current.Time + 1 });
}

void BFS()
{
	Push({ N,0 });
	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		Visit[Current.Pos] = true;
		if (Current.Pos == K)
		{
			if (MinTime == -1)
			{
				MinTime = Current.Time;
			}
			if (Current.Time == MinTime)
				TotalCount++;
		}
		RoundEdges(Current);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	BFS();
	cout << MinTime << "\n" << TotalCount;

	return 0;
}


