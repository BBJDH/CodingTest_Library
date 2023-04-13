/*
 * 11404 - �÷��̵�
 *
 * �÷��̵��� �⺻ ��ȭ��
 * MinDistance[Start][Dest] = min(MinDistance[Start][Dest], MinDistance[Start][Mid] + MinDistance[Mid][Dest]);
 * �� ����Ѵ�.
 *
 * �̸� ���� ������ �迭 MinDistance[Start][Dest]�� �����Ѵ�.
 * �Է� �޴� Edges�� Start Dest �� ���� Distance�� �Է����ش�.
 *
 * �̶� �Է¹��� ���� MinDistance�� ��ҵ��� INF�� �Է��Ѵ�
 * ��� City���� min ������ �� ���̱� ������ INF�� �̸� �־��־�� �Ѵ�.
 * ���� Start�� Dest�� ���� ���� ����� 0�̹Ƿ� �̰͵� �̸� ���� �ʱ�ȭ�Ѵ�.
 *
 * ����
 * MinDistance[Start][Dest] = min(MinDistance[Start][Dest], MinDistance[Start][Mid] + MinDistance[Mid][Dest]);
 * ��ȭ�� ����� ���� Mid Start Dest ���� 3�� ������ ���� �ּҰŸ� ������ �����Ѵ�
 * (�ð� ���⵵ O(N^3))
 *
 * ������ Mid�� ��� �ٸ� Start�������� Dest������ ����� Min ������ �س����� ���� �⺻ �����̴�.
 *
 * �������� �䱸�ϴ�
 * Start Dest�� ���� Edges�� ������ �� �� �ִٴ����� ��������
 * �̸� ���� ó�� MinDistance�� Edge�� �Է��� ���� min������ �ؾ��Ѵ�.
 *
 * ���� INF�� 0���� ����ϵ��� �ؾ����� �����Ѵ�.
 *
 */


#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;


int MinDistance[101][101]{};
int NumOfCity = 0;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int NumOfEdges = 0;
	cin >> NumOfCity >> NumOfEdges;

	for (int i = 1; i <= NumOfCity; i++)
	{
		fill_n(MinDistance[i], NumOfCity + 1, INF);
		MinDistance[i][i] = 0;
	}
	//Edges �Է�
	while (NumOfEdges--)
	{
		int Start = 0, Dest = 0, Distance = 0;
		cin >> Start >> Dest >> Distance;
		MinDistance[Start][Dest] = min(MinDistance[Start][Dest], Distance);
	}

	//�÷��̵�-���� ����
	for (int Mid = 1; Mid <= NumOfCity; Mid++)
	{
		for (int Start = 1; Start <= NumOfCity; Start++)
		{
			for (int Dest = 1; Dest <= NumOfCity; Dest++)
			{
				MinDistance[Start][Dest] = min(MinDistance[Start][Dest], MinDistance[Start][Mid] + MinDistance[Mid][Dest]);
			}
		}
	}

	//���
	for (int Start = 1; Start <= NumOfCity; Start++)
	{
		for (int Dest = 1; Dest <= NumOfCity; Dest++)
		{
			if (MinDistance[Start][Dest] == INF)
			{
				cout << 0;
			}
			else
			{
				cout << MinDistance[Start][Dest];
			}
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}