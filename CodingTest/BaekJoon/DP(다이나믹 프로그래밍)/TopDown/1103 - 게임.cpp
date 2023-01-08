/*
 *1103 - ����
 *
 *50*50 2500 ĭ�� ��� �湮�ص� �ִ� ī��Ʈ�� 2500 �̹Ƿ�
 *INF�� 3000���� ��´�.
 *
 *�׳� DFS�� �����Ͽ� �� ��ƾ���� �湮�� ���� �ٽ� �湮�ϰ� �ȴٸ�
 *�����̹Ƿ� -1�� ������ �Ѵ�
 *
 *����� ���̱� ���� DP�� ���� TopDown���� �����Ѵ�
 *
 *�� DP[Y][X]������ ���� �ش� �������� ������ �� �ִ� �ִ� ī��Ʈ�̴�
 *
 *�� ������ ���������� ������ ���� �ѹ��� �����ϹǷ� ���������� 1,
 *���� ������ 2, �� ���������� 3 �̷������� DP�� �׾ƿ´�
 *DFS�� �����Ͽ� �ٸ� ��ƾ���� �湮�� ���� ������ �̹� �ű⼭ DP�� ����� �ξ����Ƿ�
 *�߰� ȣ����� �ش� DP�� �޾ƿ´�
 *
 *�� ������ �׹����̹Ƿ� �׹��⿡ ���� �ִ� ī��Ʈ�� ���� ���� DP�� ����Ѵ�.
 *�̷��� ���������� �Ųٷ� �׾ƿ���
 *DP[0][0]�� �ִ� �̵� ī��Ʈ�� ����ִ�.
 *
 */
#include <iostream>
#include <string>
#define INF 3000

using namespace std;

struct _int2
{
	int X;
	int Y;
};

string Map[50]{};
int DP[50][50]{};
bool Visit[50][50]{};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int SizeX = 0;
int SizeY = 0;

int DFS(_int2 const& Current)
{
	int mul = Map[Current.Y][Current.X] - '0';
	int maxCount = 0;

	if (DP[Current.Y][Current.X] != 0)
		return DP[Current.Y][Current.X];

	Visit[Current.Y][Current.X] = true;
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Current.X + Direction[i].X * mul;
		Next.Y = Current.Y + Direction[i].Y * mul;

		//���� ��Ż�ϸ� ���� ��ġ���� �̵������� ���� 1
		if (Next.X < 0 or Next.Y < 0 or Next.X >= SizeX or Next.Y >= SizeY)
		{
			maxCount = max(maxCount, 1);
			continue;
		}

		if (Map[Next.Y][Next.X] == 'H')
		{
			maxCount = max(maxCount, 1);
			continue;
		}

		if (Visit[Next.Y][Next.X] == true)
			return DP[Current.Y][Current.X] = INF;

		maxCount = max(maxCount, DFS(Next) + 1);
	}
	Visit[Current.Y][Current.X] = false;

	return DP[Current.Y][Current.X] = maxCount;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SizeY >> SizeX;

	for (int i = 0; i < SizeY; i++)
	{
		cin >> Map[i];
	}
	DFS({ 0,0 });

	if (DP[0][0] >= INF)
	{
		cout << -1;
		return 0;
	}

	cout << DP[0][0];
	return 0;
}
