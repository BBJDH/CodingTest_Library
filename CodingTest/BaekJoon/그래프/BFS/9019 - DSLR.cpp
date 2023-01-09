/*
 *9019 - DSLR
 *
 *BFS�� ���� �����ߴ�
 *
 *�� �б⺰ ó�� :
 *
 *D : 2���� ���� 10000�� �������� �־��ش�
 *
 *S : ���� ���� 0�̶�� 9999 �̿��� ���� -1
 *
 *L : ���ڸ� �������� �о�� �ϹǷ� 1234 �� 234�� �����Ǿ���Ѵ�
 *	���� 1000���� ���� ������ 234�� ������ *10�� ���� 2340�� ����� �ش�
 *	���⿡ �����ʿ� ���� �ڸ��� ��ȣ�� �����ش� ��, 1234�� 1000�� ���� ���� �����ش�
 *
 *R : ���ڸ� ���������� �о�� �ϹǷ� 1234 �� 123�� �����ȴ�
 *	���� 10���� ���� �� 123�� ���� �ϰ� ���⿡ ���� õ�� �ڸ��� ���Ѵ�
 *	õ�� �ڸ��� 1234�� 10���� ���� ������ �̹Ƿ� �̰Ϳ� 1000�� ���Ͽ� ���Ѵ�.
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