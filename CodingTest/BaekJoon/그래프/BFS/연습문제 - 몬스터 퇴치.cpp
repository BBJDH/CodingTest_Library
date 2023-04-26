/*
 *==========================
 *�������� - ���� ��ġ
 *
 *BFS�� ���� Ǯ�� �����ϴ�
 *
 *Skills�� Edges�� �Ͽ� ������ HP�� 0�� �� ������ BFS�� �����Ѵ�.
 *
 *�䱸���׿� ���߾� HP�� X���ϰ� �ȴٸ� HP�� ������ ��ŭ ȸ������ ť�� �����Ѵ�.
 *
 *
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct _int2
{
	int Hp;
	int Count;
};

int X = 0, Y = 0, M = 0;
vector<int> Edges{  };
queue<_int2> BFS_Queue{};
bool Visit[400001]{};
void Push(_int2 const& Next)
{
	if(Visit[Next.Hp]==false)
	{
		BFS_Queue.push(Next);
		Visit[Next.Hp] = true;
	}
}

int RoundEdges(_int2 const& Current)
{
	for (int const elem : Edges)
	{
		_int2 Next{};
		Next.Hp = Current.Hp - elem;
		Next.Count = Current.Count + 1;

		if (Next.Hp <= 0)
		{
			return Next.Count;
		}
		if (Next.Hp <= X)
		{
			Next.Hp = Next.Hp + Y;
		}

		Push(Next);
	}
	return -1;
}

int BFS()
{
	Push({ M,0 });

	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();

		int const Result = RoundEdges(Current);
		if (Result != -1)
		{
			return Result;
		}
	}
	return -1;
}


int solution(int x, int y, int m, vector<int> skills)
{
	int answer = 0;
	Edges = skills;
	X = x;
	Y = y;
	M = m;
	answer = BFS();
	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cout << solution(4,5,9,{5,1});
	//cout << solution(30,10,50,{1,5,10,15});
	//cout<< solution(180000, 110000, 200000, { 110001 });

	return 0;
}