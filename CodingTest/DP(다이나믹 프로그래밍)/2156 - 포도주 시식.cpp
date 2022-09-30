/*
������ �ý�
DP ������ �Ǵٽ� �Ųٷ� ������ �����غ���

�����ִ� ���� ���� ���� ������ ���� ������ �Դ� ����Ǽ��� � ����
.... OOX
.... OXO
.... XOO
�� ����� �� ���̴�
�ٽ� �����ϸ�
.... OOX n-1
.... OXO n-2 + n��°��
.... XOO n-3 + n-1��°, n��° ��

DP[0] = 0 0���� ���ô� ���� 0
DP[1] = 1
DP[2] = 2
DP[3] =

*/

#include<iostream>
#include<algorithm>

using namespace std;

int DP[10001]{};
int Wines[10001]{};

int GlassesNum = 0;


void Solution()
{
	DP[1] = Wines[1];
	DP[2] = Wines[1] + Wines[2];
	// 3���� ����

	/*
	.... OOX n-1
	.... OXO n-2 + n��°��
	.... XOO n-3 + n-1��°, n��° ��

	DP[n-1] ��
	DP[n-2]+Wines[n],
	DP[n-3]+Wines[n-1]+Wines[n]
	�� ���߿� ���� ū���� DP[n]���� ��


	*/

	for (int i = 3; i <= GlassesNum; i++)
	{
		int MaxVal = max(DP[i - 1], DP[i - 2] + Wines[i]);
		MaxVal = max(MaxVal, DP[i - 3] + Wines[i - 1] + Wines[i]);
		DP[i] = MaxVal;
	}
}

int main()
{

	scanf("%d", &GlassesNum);

	for (int i = 1; i <= GlassesNum; i++)
	{
		int InputNum = 0;
		scanf("%d", &InputNum);
		Wines[i] = InputNum;
	}
	Solution();
	printf("%d", DP[GlassesNum]);

	return 0;
}
