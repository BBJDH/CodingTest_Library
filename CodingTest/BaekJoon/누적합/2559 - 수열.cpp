/*
2559 - ����

������ �����̴�
�־��� �µ����� ���������� �������� ���� DP �迭�� ������ �д�
�µ� : 3 -2 -4 -9  0    3   7   13   8  -3 (n�� �迭)
DP :  0 3  1 -3 -12 -12  -9  -2   11  19  16 (n+1�� �迭)

�� DP[n]�� n���� ������ �µ� �������� ����.

DP�� �տ� 0�� �߰� �� ������ ������ ����

������ ������ �µ��� ���ϱ� ���ѽ��� ���غ���
�������� �µ������� �������� start, ������ end�� �Ѵ�
start ~ end�� ������ :  DP[end] - DP[start-1] �� �ǹ��Ѵ�.
start ~ end�� start�� start+1... end ������ �µ����� ������ �̹Ƿ�
start ������ ���� �µ��� ���ִ� ���̴�.

���� ��� 3��°���� 5��°������ ���� �µ��� DP[5] - DP[2] �� ����.
�� ��� start-1���� index�� -1�� �� ���ɼ��� ����Ͽ� �տ� 0�� �߰��� �ش�
�̷ν� 1������ �������� DP[1] - DP[0] = 3���� DP[-1]������ ���� �� �� �ִ�.

*/



#include<iostream>
#include<vector>

using namespace std;

vector<int> Temporature{};
vector<int> Temporature_DP{};

int InputCase = 0;
int K = 0;

void MakeDP()
{
	Temporature_DP.emplace_back();
	int Sum = 0;
	for (int i = 1; i <= Temporature.size(); i++)
	{
		Sum += Temporature[i - 1];
		Temporature_DP.emplace_back(Sum);
	}
}
void FindMax()
{
	int StartIndex = 0;
	int EndIndex = StartIndex + K;
	int Max = -10000000;
	while (EndIndex < Temporature_DP.size())
	{
		int Sum = Temporature_DP[EndIndex] - Temporature_DP[StartIndex];
		Max = max(Max, Sum);
		StartIndex++;
		EndIndex++;
	}
	cout << Max;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> InputCase;
	cin >> K;

	while (InputCase--)
	{
		int InputTemp{};

		cin >> InputTemp;
		Temporature.emplace_back(InputTemp);
	}
	MakeDP();
	FindMax();
	return 0;
}