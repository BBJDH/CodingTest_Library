/*
16946 - 벽 부수고 이동하기 4

0인 묶음을 ID로 기록 예를들면
11001
00111
00010
10101

00110
22000
22203
02040

와같이 0구역을  ID로 기록(1부터 시작)

ID : Count로 map에 등록

1 : 2
2 : 6
3 : 1
4 : 1
로 등록됨


이후 각 wall에 대해서 네 방향에 있는 ID 를통해 Count를 합산 (wall지역 1도 포함)
단, 동일 지역이 합산되면 안되므로 더해지는 과정을 set로 합산해 중복을 체크

이후 업데이트된 wall들을 출력

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
	//각 0인 좌표 들어옴

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
	//0마다 방문하여 0들의 묶음 ID와 Count를 기록
	for (auto const& elem : Zeros)
		BFS(elem);

	//ID_Map을 통해 주면 묶음들을 합산해서 Wall에 업데이트
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

