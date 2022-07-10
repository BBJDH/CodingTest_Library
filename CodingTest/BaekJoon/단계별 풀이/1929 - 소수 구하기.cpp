#include<iostream>
#include<math.h>
using namespace std;

int Marked_Nums[1000001]{};
void Mark_Multiple()
{
	//�迭�� 2���� Ȯ�� ����
	// �迭���Ұ� 1�̶�� �Ѿ
	// 0�ΰ��� �Ҽ����ȴ�
	// �׸��� �� �Ҽ��� ���ؼ� ����μ��� ��� 1�� ��ŷ ���ش�
	// �����迭 ���� Ž��
	// ���� 1,000,000���� ������ 1000���� �ϸ� �ȴ�
	//
	int Max_Num = sqrt(1000001);
	Marked_Nums[1] = 1;
	for (int i = 2; i < Max_Num; i++)
	{
		if (Marked_Nums[i] == 1)
		{
		}
		else
		{
			for (int j = i * i; j < 1000001; j += i)
			{
				Marked_Nums[j] = 1;
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int Start_Num = 0;
	int End_Num = 0;

	cin >> Start_Num >> End_Num;

	Mark_Multiple();

	for (int i = Start_Num; i <= End_Num; i++)
	{
		if (Marked_Nums[i] == 0)
			cout << i << "\n";
	}
	return 0;
}