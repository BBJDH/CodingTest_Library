/*
 *9019 - DSLR
 *
 *BFS를 통해 접근했다
 *
 *각 분기별 처리 :
 *
 *D : 2곱한 수에 10000의 나머지를 넣어준다
 *
 *S : 들어온 수가 0이라면 9999 이외의 수는 -1
 *
 *L : 숫자를 왼쪽으로 밀어야 하므로 1234 중 234가 보존되어야한다
 *	따라서 1000으로 나눈 나머지 234를 보존후 *10을 통해 2340을 만들어 준다
 *	여기에 오른쪽에 일의 자릿수 번호를 더해준다 즉, 1234를 1000로 나눈 몫을 더해준다
 *
 *R : 숫자를 오른쪽으로 밀어야 하므로 1234 중 123이 보존된다
 *	따라서 10으로 나눈 몫 123을 보존 하고 여기에 더할 천의 자리를 구한다
 *	천의 자리는 1234의 10으로 나눈 나머지 이므로 이것에 1000을 곱하여 더한다.
 *
 *
 */
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Node
{
	int Num;
	string Path;
};

queue<Node> BFS_Queue{};
int Visit[10000]{};
char Direction[4] = { 'D','S','L','R' };
int destNum = 0;

void Push(Node const& Next)
{
	if (Visit[Next.Num] == false)
	{
		Visit[Next.Num] = true;
		BFS_Queue.push(Next);
	}
}

bool RoundEdge(Node const& Current)
{

	for (int i = 0; i < 4; i++)
	{
		Node Next{};

		switch (Direction[i])
		{
		case 'D':
		{
			Next.Num = (Current.Num * 2) % 10000;
			Next.Path = Current.Path + "D";
			break;
		}
		case 'S':
		{
			if (Current.Num == 0)
				Next.Num = 9999;
			else
			{
				Next.Num = Current.Num - 1;
			}
			Next.Path = Current.Path + "S";

			break;
		}
		case 'L':
		{
			int addNum = Current.Num / 1000;
			Next.Num = (Current.Num % 1000) * 10 + addNum;
			Next.Path = Current.Path + "L";
			break;
		}
		case 'R':
		{
			int addNum = (Current.Num % 10) * 1000;
			Next.Num = (Current.Num / 10) + addNum;
			Next.Path = Current.Path + "R";
			break;
		}
		}
		if (Next.Num == destNum)
		{
			cout << Next.Path << "\n";
			return true;
		}
		Push(Next);
	}
	return false;
}

void BFS(int StartNum)
{
	BFS_Queue = queue<Node>{};
	Push({ StartNum ,"" });
	while (!BFS_Queue.empty())
	{
		Node const Current = BFS_Queue.front();
		BFS_Queue.pop();
		if (RoundEdge(Current) == true)
		{
			return;
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int startNum = 0;
	int testCase = 0;
	cin >> testCase;
	while (testCase--)
	{
		fill_n(Visit, 10000, false);
		cin >> startNum >> destNum;
		BFS(startNum);
	}


	return 0;
}