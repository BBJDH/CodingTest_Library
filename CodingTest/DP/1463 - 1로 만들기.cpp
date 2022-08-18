#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
1463 - 1�� �����
���� 1,000,000 ���� �Է¹����Ƿ�
��ȣ�� �ε����� �ϴ� �迭�鸸��+1�� ����
�ε����� �ش��ȣ, �迭�� ���� ���� ������ ǥ���Ѵ�
N���� ����, 2���� ���
�� �ε��������ؼ� ���� ��갪�� 0�̶�� ������ ���� ���ڰ� �ƴϹǷ� �Ѿ
�迭�������� 1�̻����� ��ȿ�ϴٸ�
123������ ����
���� �� ��ȣ�� �������� 0�̶�� ������Ʈ, ���� �����Ѵٸ� �ΰ��� ���� �� �������� ����
*/
vector<int> NumsCalcCount{};

void Calc(int const DestIndex, int const CurrentCalcCount)
{
	if (NumsCalcCount[DestIndex] == 0)
		NumsCalcCount[DestIndex] = CurrentCalcCount + 1;
	else
		NumsCalcCount[DestIndex] = min(CurrentCalcCount + 1, NumsCalcCount[DestIndex]);
}


void SelectNum(int const Num_Index)
{
	if (Num_Index % 3 == 0)
		Calc(Num_Index / 3, NumsCalcCount[Num_Index]);
	if (Num_Index % 2 == 0)
		Calc(Num_Index / 2, NumsCalcCount[Num_Index]);
	Calc(Num_Index - 1, NumsCalcCount[Num_Index]);

}

int main()
{
	int StartNum = 0;

	scanf("%d", &StartNum);
	NumsCalcCount.resize(StartNum + 1);	 //���ǻ� ��ȣ�� 1��1 ������ ���� 1�� �߰�
	SelectNum(StartNum);
	for (int i = StartNum; i > 1; i--)
	{
		//���ȹ�ȣ�� �ƴѰ�쿡�� ������
		if (NumsCalcCount[i])
			SelectNum(i);
	}
	printf("%d", NumsCalcCount[1]);
	return 0;
}
