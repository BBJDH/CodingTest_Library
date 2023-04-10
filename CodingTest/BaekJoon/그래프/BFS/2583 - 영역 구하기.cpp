/*
 *2583 - ���� ���ϱ�
 *
 * �� ��ǥ������ �׷����� �ٷ�� �ʺ�켱 Ž���� ���� Ǯ����.
 *
 * �Է� ���� ������ ��� 1�� ����ϰ�, 0�� ������ BFS �Ѵ�
 * ������ Visit�� ���� �ߺ� �湮�� ���´�.
 *
 * BFS�� �����ϸ� �ش� ������ �Ѱ��� ����Ѵ�.
 * �� �ش� BFS���� Pop �ɶ����� ������ ũ�⸦ ++�Ͽ�
 * BFS����� �� ����� ��� ��Ͽ� �߰��Ѵ�.
 *
 * �̰��� �ݺ��Ͽ� �������� Results�� ũ���
 * �����Ͽ� ����� ����Ѵ�.
 *
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

queue<_int2> BFS_Queue{};
vector<int> Results{};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int Map[100][100]{};
bool Visit[100][100]{};
_int2 Size{};


bool Push(_int2 const& Next)
{
	if (Visit[Next.Y][Next.X] == false and Map[Next.Y][Next.X] == 0)
	{
		Visit[Next.Y][Next.X] = true;
		BFS_Queue.push(Next);
		return true;
	}
	return false;

}

void RoundEdges(_int2 const& Current)
{
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Current.X + Direction[i].X;
		Next.Y = Current.Y + Direction[i].Y;
		if (Next.X >= 0 and Next.X < Size.X and Next.Y >= 0 and Next.Y < Size.Y)
		{
			Push(Next);
		}
	}
}

void BFS(_int2 const& Start)
{
	if (Push(Start) == false)
	{
		return;
	}
	int Result = 0;

	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		RoundEdges(Current);
		Result++;
	}
	Results.push_back(Result);
}

void Solution()
{
	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			BFS({ x,y });
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);


	int NumOfZone = 0;
	cin >> Size.Y >> Size.X >> NumOfZone;

	while (NumOfZone--)
	{
		_int2 MinPos{};
		_int2 MaxPos{};
		cin >> MinPos.X >> MinPos.Y >> MaxPos.X >> MaxPos.Y;

		for (int y = MinPos.Y; y < MaxPos.Y; y++)
		{
			for (int x = MinPos.X; x < MaxPos.X; x++)
			{
				Map[y][x] = 1;
			}
		}
	}
	Solution();
	sort(Results.begin(), Results.end());
	cout << Results.size() << "\n";
	for (int const elem : Results)
	{
		cout << elem << "\n";
	}
	return 0;
}