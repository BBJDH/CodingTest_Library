/*
 *1520 - ������ ��
 *
 *DFS�� �Ȱ��� �������� ���� ã�ư��� �ð��ʰ��� �߻��Ѵ�.
 *
 *������ DFS�� DP�� �̿��� �������� ���� �ߴٸ� 1�� ��ȯ �ϵ��� ó���ϰ�
 *
 *���� �������� �̹� �湮 �ߴ� ��� ���ٸ�
 *�ش� �������� �̹� �� �������κ��� �湮���� �� ��� ����� ���� ��ϵǾ� �����Ƿ�
 *���� �������� DP�� �޾Ƽ� �ջ��Ѵ�
 *
 *������ �̷��Ը� ó���Ѵٸ� ���ٸ��濡 �����Ѱ�쿡 ���� �ߺ� �湮 ó���� ���� �ʴ´�
 *�������� ���� ������ ���ٸ����� ������ �̰��� �ߺ����� �����ٸ� ���� �ð������ �Ҹ��Ѵ�.
 *
 *������ ������ ���� ó���Ѵ�.
 *
 *���� -1�� DP�� �ʱ�ȭ
 *������ ������ 1��ȯ
 *���ٸ��� ������ 0��ȯ
 *
 *���� �������� -1�� �ƴ�DP���̶�� �װ��� �޾ƿ�
 *(���⼭ ���ٸ���� ���°�δ� 0�̹Ƿ� ���̻� Ž���� ������� �ʴ´�.)
 *
 *���⼭���ʹ� ���� �������� DP = -1 ��� �� �湮�غ��� ���� ����̴�.
 *
 *�̰��� �� �����¿쿡 ���� Ž���� �����Ѵ�
 *Map�� ������ �Ѿ�� �ʴ���, ���������� �´��� Ȯ���� ��
 *���� DFS�� ȣ���� �ش� �� ����� �ش� ��ġ�� DP���� ������ �� ��ȯ����ϰ�
 *���� �Լ��� ��ȯ�� ������ �ջ��Ͽ� ���� ��ġ������ DP�� ��� �� ��ȯ ó���Ѵ�.
 *
 *���� ������ ��ġ�� ��� ����� ������ ������Ƿ�
 *
 *DP[0][0]�� ����� ��� ����� ���� ���� ����� ��ϵǾ� �ִ�.
 *
 */

#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int Map[500][500]{};
int DP[500][500]{};
int SizeX = 0;
int SizeY = 0;

int DFS(_int2 const& Pos)
{
	int elem = Map[Pos.Y][Pos.X];
	if (Pos.X == SizeX - 1 and Pos.Y == SizeY - 1)
	{
		return DP[Pos.Y][Pos.X] = 1;
	}
	if (DP[Pos.Y][Pos.X] != -1)
		return DP[Pos.Y][Pos.X];

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Pos.X + Direction[i].X;
		Next.Y = Pos.Y + Direction[i].Y;
		if (Next.X >= SizeX or Next.Y >= SizeY or Next.X < 0 or Next.Y < 0)
			continue;
		if (Map[Pos.Y][Pos.X] <= Map[Next.Y][Next.X])
			continue;
		sum += DFS(Next);
	}

	return DP[Pos.Y][Pos.X] = sum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SizeY >> SizeX;


	for (int y = 0; y < SizeY; y++)
	{
		for (int x = 0; x < SizeX; x++)
		{
			cin >> Map[y][x];
			DP[y][x] = -1;
		}
	}
	DFS({ 0,0 });
	cout << DP[0][0];
	return 0;
}