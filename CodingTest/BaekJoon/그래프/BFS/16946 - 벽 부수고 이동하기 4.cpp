/*
16946 - �� �μ��� �̵��ϱ� 4

0�� ������ ID�� ��� �������
11001
00111
00010
10101

00110
22000
22203
02040

�Ͱ��� 0������  ID�� ���(1���� ����)

ID : Count�� map�� ���

1 : 2
2 : 6
3 : 1
4 : 1
�� ��ϵ�


���� �� wall�� ���ؼ� �� ���⿡ �ִ� ID ������ Count�� �ջ� (wall���� 1�� ����)
��, ���� ������ �ջ�Ǹ� �ȵǹǷ� �������� ������ set�� �ջ��� �ߺ��� üũ

���� ������Ʈ�� wall���� ���

 */


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct _int2
{
	int X;
	int Y;
};
int Map[1000][1000]{};
int ID_Map[1000][1000]{};
bool Visit[1000][1000]{};

vector<_int2> Walls{};
vector<_int2> Zeros{};
_int2 Direction[4] = { {1,0},{-1,0} , {0,1} , {0,-1} };
queue<_int2> BFS_Queue{};
map<int, int> ID_LinkedCount{};

int N = 0;
int M = 0;
int ID = 1;
void Push(_int2 const& Next)
{
	if (Map[Next.Y][Next.X] == 0 and Visit[Next.Y][Next.X] == false)
	{
		BFS_Queue.push(Next);
		Visit[Next.Y][Next.X] = true;
	}
}

void RoundEdges(_int2 const& Current)
{
	for (auto const& elem : Direction)
	{
		_int2 Next{ Current.X + elem.X,Current.Y + elem.Y };
		if (Next.X >= 0 and Next.X < M and Next.Y >= 0 and Next.Y < N)
			Push(Next);
	}
}

void BFS(_int2 const& Start)
{
	//�� 0�� ��ǥ ����

	queue<_int2> Visit_Queue{};

	Push(Start);
	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		Visit_Queue.push(Current);
		RoundEdges(Current);
	}
	int VisitCount = static_cast<int>(Visit_Queue.size());
	ID_LinkedCount.insert(make_pair(ID, VisitCount % 10));

	while (!Visit_Queue.empty())
	{
		_int2 const Visit = Visit_Queue.front();
		Visit_Queue.pop();
		ID_Map[Visit.Y][Visit.X] = ID;
	}
	ID++;
}

void Solution()
{
	//0���� �湮�Ͽ� 0���� ���� ID�� Count�� ���
	for (auto const& elem : Zeros)
		BFS(elem);

	//ID_Map�� ���� �ָ� �������� �ջ��ؼ� Wall�� ������Ʈ
	for (auto const& wallElem : Walls)
	{
		int Sum = 1;
		set<int> IDs{};
		for (auto const& dirElem : Direction)
		{
			_int2 Next{ wallElem.X + dirElem.X,wallElem.Y + dirElem.Y };
			if (Next.X >= 0 and Next.X < M and Next.Y >= 0 and Next.Y < N)
			{
				int newId = ID_Map[Next.Y][Next.X];
				auto iter = lower_bound(IDs.begin(), IDs.end(), newId);
				if (IDs.find(newId) == IDs.end())
				{
					Sum += ID_LinkedCount[newId];
					IDs.insert(newId);
				}
			}
		}
		Map[wallElem.Y][wallElem.X] = Sum % 10;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string InputStr{};
		getline(cin, InputStr);
		for (int j = 0; j < M; j++)
		{
			int InputNum = InputStr[j] - '0';
			Map[i][j] = InputNum;

			if (InputNum == 1)
				Walls.push_back({ j,i });
			else
				Zeros.push_back({ j,i });
		}
	}
	Solution();

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
			cout << Map[y][x];
		cout << "\n";
	}
	return 0;
}

