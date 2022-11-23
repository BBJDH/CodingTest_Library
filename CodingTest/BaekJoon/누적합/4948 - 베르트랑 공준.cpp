/*
 *4948 - ����Ʈ�� ����
 *
 *�����佺�׳׽��� ü�� �̿��� �Ҽ� �迭�� ���,
 *������ �迭(DP)�� ����� �ִ� �� ������ �Ҽ� ������ ����
 *
 *�Է¹��� ���� ���� DP[i*2] - DP[i] �� ����Ѵ�
 *
 *�ٸ� ��ĵ� ���������� ���� �ڵ�� �Ҽ��� �������� �̿��� Ǯ��´�.
 *
 */



#include <iostream>

using  namespace  std;

#define MAX 246913
bool PrimeNum[MAX]{};
int DP[MAX]{};

void MarkPrimNum()
{
	PrimeNum[0] = PrimeNum[1] = true;
	for (int i = 2; i * i < MAX; i++)
	{
		if (PrimeNum[i] == false)
		{
			for (int mul = 2; mul * i < MAX; mul++)
			{
				PrimeNum[i * mul] = true;
			}
		}
	}
}
void MakeDP()
{
	//������ ����
	int count = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (PrimeNum[i] == false)
			count++;
		DP[i] = count;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	MarkPrimNum();
	MakeDP();

	while (true)
	{
		int inputNum = 0;
		cin >> inputNum;
		if (inputNum == 0)
			break;
		cout << DP[inputNum * 2] - DP[inputNum] << "\n";

	}

	return 0;
}