
/*
9184 - �ų��� �Լ� ����

������ �������� �Լ�ȣ���� �ƴ� �迭�� �̸� ����صд�

�ش��Լ��� ������ �׻� ���� ��ȣ���� ���� ��ȣ�� ȣ������ �̿��Ͽ�
for�� �Ʒ����� ���� �ö󰡸鼭 ȣ��� �� �ִ� ��� ����� ���� ��� ���

51 * 51 * 51 = 132651 ��ŭ�� ������ �Ϸ��ϸ�
��� ���� ��ϰ����ϴ�

���ܻ���:
������ ���´ٸ� ���ǿ� ���� 1�� ������ָ�ȴ�
*/
#include<iostream>

using namespace std;

int Results[21][21][21]{};

int FindDP(int A, int B, int C)
{
	if (A <= 0 or B <= 0 or C <= 0)
		return 1;

	if (A < B and B < C)
		return Results[A][B][C - 1] + Results[A][B - 1][C - 1] - Results[A][B - 1][C];

	return Results[A - 1][B][C] + Results[A - 1][B - 1][C] + Results[A - 1][B][C - 1] - Results[A - 1][B - 1][C - 1];
}

void DP()
{

	for (int A = 0; A < 21; A++)
	{
		for (int B = 0; B < 21; B++)
		{
			for (int C = 0; C < 21; C++)
			{
				Results[A][B][C] = FindDP(A, B, C);
			}
		}
	}
}

/*
��������� �����ֱ����� ���� printf�� ����Ѵ�
	ios_base::sync_with_stdio(false); ������ �����߱⿡
printf cout�� ��ũ�� ���� �ʴ´� ȥ�������� �ʵ��� ��������
*/

//void Solution(int A, int B, int C)
//{
//	printf("w(%d, %d, %d) = ", A, B, C);
//	if (A <= 0 or B <= 0 or C <= 0)
//	{
//		printf("%d\n", 1);
//		return;
//	}
//	if (A <= 20 and B <= 20 and C <= 20)
//	{
//		printf("%d\n",Results[A][B][C]);
//		return;
//	}
//	printf("%d\n", Results[20][20][20]);
//}
void Solution(int A, int B, int C)
{
	printf("w(%d, %d, %d) = ", A, B, C);
	//cout << "w(" << A << ", " << B << ", " << C << ") = ";
	if (A <= 0 or B <= 0 or C <= 0)
	{
		cout << 1 << "\n";
		return;
	}
	if (A <= 20 and B <= 20 and C <= 20)
	{
		cout << Results[A][B][C] << "\n";
		return;
	}
	cout << Results[20][20][20] << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	DP();
	while (true)
	{
		int A = 0, B = 0, C = 0;
		cin >> A >> B >> C;

		if (A == -1 and B == -1 and C == -1)
			break;
		Solution(A, B, C);
	}
	return 0;
}
