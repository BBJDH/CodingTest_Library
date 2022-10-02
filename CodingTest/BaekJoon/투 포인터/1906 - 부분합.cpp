
/*
1806 - �κ���

������ DP�� �������͸� ����ϴ� �����̴�
�켱 �Է��� �����鼭 �������� ��� ���صд� (���� �κ��տ��� ���� ���� �ð����⵵ ����)
���� Left�����Ϳ� Right�����͸� �� ���ʿ������� �����Ѵ�(�κ��� ����� ���� 0�ڸ��� ���� 1���� ���ڸ� ����صд�)
Left - Right ������ ���� ��ǥ�� �̸��̶�� Right�� ���������� �÷� �հ����� �ø���
Left - Right ������ ���� ��ǥ�� �̻��̶�� Left�� ���������� �÷� �հ����� �ٿ��� �������̸� ã�´�
(���� ��ǥ�� �̻��϶����� Length�� ������Ʈ���ش�)
���� ���Ҷ��� ������ [Right] �ε����� ������  - [Left-1] �ε����� �������� Left - Right�� �������� �ȴ�
(�̶� Left�� 0���� �����ϴ� ��� -1 �迭���� ����� ����Ͽ� 0�� ����ΰ� �����͸� �����Ѵ�)
*/
#include<iostream>
#include<vector>

using namespace std;
vector<int> Sequence{};
vector<int> DP_Sum{};
int ArrSize = 0;
int TargetSum = 0;
int MinLength = 0;

int MakeSum(int const Left, int const Right)
{
	return DP_Sum[Right] - DP_Sum[Left - 1];
}


void TwoPointer()
{
	int Left = 1, Right = 1;

	while (Left <= Right and Right < Sequence.size())
	{
		int Sum = MakeSum(Left, Right);
		if (Sum >= TargetSum)
		{
			if (MinLength == 0)
				MinLength = Right - Left + 1;
			else
				MinLength = min(MinLength, Right - Left + 1);
			Left++;
		}
		else
			Right++;
	}
	cout << MinLength;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> ArrSize >> TargetSum;
	Sequence.push_back(0);
	DP_Sum.push_back(0);
	for (int i = 1; i <= ArrSize; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		Sequence.push_back(InputNum);
		DP_Sum.push_back(InputNum + DP_Sum[i - 1]);
	}
	TwoPointer();
	return 0;
}
