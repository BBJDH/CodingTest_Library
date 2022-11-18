/*
 * 2342 - Dance Dance Revolution
 *
 *�������� 00 ���¿��� ��� DDR ������ �����ϰ� �� ��� ����� ���� �����غ���
 *��� ȣ���� ���� ��� ����� ���� �̸� ��� �� �ִ�
 *������ ���� ��� ����� ���� �����Ѵ�
 *
 *�Է�  1	2	2		4		3
 *								34
 *				22(X)	42	---	13
 *				12	---	14	---	34
 *			12					13
 *			20  20		40
 *				22(X)	24
 *		10
 *00	01				41
 *				21		24
 *			21	22(X)
 *			02	22(X)
 *				02		42
 *						04
 *
 *���� DP�� ������
 * DP[DDR �����ȣ][�޹���ġ][��������ġ]
 * ���⼭ ������ ���� DP�� ������� ������ ����� ���°��� �ƴ϶�,
 * ������ �ʿ��h ����� ����ϴ� ���̴�
 * ���� ��� DP[4��° ����][�޹�4][������2] �� ������ 3�� ������� �޹� 3 ������ 4, �޹�1 ������3  �ΰ��� ����� ���� �����Ѵ�
 * �� ���߿� �ּ��� ���(��� �̰��� �Ѵ� 3���� ����)���� �����Ѵ�. �̿��� �ٸ� ����� ���� �����Ƿ� �ٽ� ����� �ʿ䰡 ����.
 * �̷��� Top Down���� �� ���������� DP�� �׾ƿ�����
 * DP[0][0][0]�� ����� 00���� �� ������ ������ ��� �ּҺ���� ����ִ�
 *
 *
 * ���� ������ ������ �ȵȴ�. �� ���� ���Ѵ�� min ���꿡�� ���ܵǵ��� �����(00 ����)
 * ����Լ��� ��������� ����ؾ��Ѵ�
 * DP != 0 �� ���� �̹� ���Ǿ��ٸ� �ش� �б�� ���̻� ������ �ʿ䰡 ����(�޸������̼�)
 *
 *
 */

#include <iostream>
#include <vector>
#define INF 500000
using namespace std;

vector<int> DDR{};

int DP[100001][5][5]{};

int Cost[5][5]{};


void CallDP(int const CurrentStep, int const Left, int const Right)
{
	if (CurrentStep + 1 == DDR.size()) return;
	if (Left == Right and Left != 0)
	{
		DP[CurrentStep][Left][Right] = INF;
		return;
	}
	if (DP[CurrentStep][Left][Right] != 0) return;

	int NextStep = DDR[CurrentStep + 1];
	//����� �� �б�
	CallDP(CurrentStep + 1, NextStep, Right);
	CallDP(CurrentStep + 1, Left, NextStep);

	//�ռ� �бⰪ�� min���� ����
	DP[CurrentStep][Left][Right] = min
	(
		DP[CurrentStep + 1][NextStep][Right] + Cost[Left][NextStep],
		DP[CurrentStep + 1][Left][NextStep] + Cost[Right][NextStep]
	);

}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputNum = -1;
	DDR.emplace_back(0);
	while (true)
	{
		cin >> inputNum;
		if (inputNum == 0) break;
		DDR.emplace_back(inputNum);
	}
	for (int i = 1; i < 5; i++)
	{
		Cost[0][i] = 2;
		Cost[i][i] = 1;
	}

	//1(2,4), 2(1,3), 3(2,4) 4(1,3)
	Cost[1][2] = Cost[1][4] = Cost[2][1] = Cost[2][3] = Cost[3][2] = Cost[3][4] = Cost[4][1] = Cost[4][3] = 3;

	//(1,3), (2,4) (3,1) (4,2)
	Cost[1][3] = Cost[2][4] = Cost[3][1] = Cost[4][2] = 4;
	CallDP(0, 0, 0);
	cout << DP[0][0][0];
	return 0;
}