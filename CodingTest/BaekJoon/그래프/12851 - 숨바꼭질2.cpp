/*
12851 - ���ٲ��� 2

�湮ó���� ť�� �ֱ����� ó���ϴ°� �ƴ϶�, ť���� �����鼭 �湮ó���� ���ָ� �ȴ�.

������ ����غ���

5
[4 6 10] 5�湮
6 10 [3 X 8] 4�湮
10 3 8 [X 7 12] 6�湮
3 8 7 12 [9 11 20] 10�湮
8 7 12 9 11 20 [2 X X] 3�湮
7 12 9 11 20 2 [7 9 16] 8�湮
12 9 11 20 2 7 9 16 [X X 14] 7�湮
9 11 20 2 7 9 16 [11 13 24] 12�湮
11 20 2 7 9 16 11 13 24 [X X 18] 9�ߺ�
11 20 2 7 9 (16) 11 13 24 (18)
.
.
.
���⼭ (16)�� (18)�� ���� �̾��� �����鼭 17�� ��ϵǰ�,
������ ������ �ʰ��ϰų� �湮��Ͽ� �ɷ��� 17�� ���� �� ������

�� �����ϸ� ó�� �ʺ�Ž�� 17�� �Ǵ� Time�� �ߺ��湮�� ����ϰ�,
�� ���� Ž���� �ߺ��湮�� ������� �ʴ� ������̴�.

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


