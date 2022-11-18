/*
 *1562 - ��ܼ�
 *

 BottomUp�� ���� TopDown�� Ǯ������
 �̹����� TopDown�� ���ϴ�

�⺻ DP��[����][���� ��ȣ][�湮 ��Ʈ]�� ����Ѵ�
���⼭ ������ ���� ��Ʈ�� �ΰ��� ������ �ȴٴ� ���̴�
������ ������ 0~ 9�� ��� �湮�� ������ �ʿ��ϹǷ�
0���� 9���� �湮�� �ΰ��� ��Ʈ�� ������ �ȴ�.

�׸��� ����Ž������ ��͸� ������ ���ܴ� ����,  �ߺ��� return���� �޸������̼� ���ش�(return DP[Size][CurrentNum][Bit];)
�� �Ŀ� ������ �ϼ��Ǿ������� �˻����ش�
�� ���� ���̿� �����ߴ����� 0���� 9���� �湮�ߴٸ�
��Ģ�� ���� +1 -1 �湮�� ��Ű�Ƿ� ������ �ϼ����� ����ȴ� (+1)
(0�� 9�� ��� -1�� 10�� ���ܸ� 0���� �����ϵ��� �����Ѵ�)
�� ������ ���ļ� �ٽ� �������� ���ƿ´� Size 0�� �迭�� ������

������ 0�� �迭�� 1~9��ȣ���ۿ� �ش��ϴ� ������ ��� �����Ͽ� ����Ѵ�
(������ ��ȣ 0 ������ �����Ͽ����Ƿ� 1���� ���۽�Ų��)

�� �ջ꿡�� Mod ������ �� ó��������

 *
 */
 //TopDown
#include <iostream>

using namespace std;

#define LIMIT 1000000000

int DP[101][10][4]{};
int N = 0;



int MakeDP(int const& Size, int const& CurrentNum, int Bit)
{

	//DP[Size][CurrentNum][Bit] �� ã�ڴ�
	//���̰� Size�̰� ���� �湮��ȣ�� CurrentNum�̸� �湮��Ʈ�� Bit�� ���¿��� ����� ���� ����� ���ϰڴ�.
	if (CurrentNum < 0 or CurrentNum>9) return 0;

	//�޸������̼�
	if (DP[Size][CurrentNum][Bit] != 0)
		return DP[Size][CurrentNum][Bit];
	//�������� ��Ʈ ������Ʈ
	if (CurrentNum == 0)
		Bit = Bit | 1;
	else if (CurrentNum == 9)
		Bit = Bit | 1 << 1;

	if (Size == N - 1)	//���� ���� ����
	{
		if (Bit == 3) return 1;// �����ϸ� 1 ���� �ϳ��� ���Դٴ� ��
		else return 0;
	}

	return DP[Size][CurrentNum][Bit] = (MakeDP(Size + 1, CurrentNum - 1, Bit) + MakeDP(Size + 1, CurrentNum + 1, Bit)) % LIMIT;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int Sum = 0;
	for (int i = 1; i < 10; i++) //���� ��ȣ
	{
		Sum = (Sum + MakeDP(0, i, 0)) % LIMIT;
	}
	cout << Sum;
	return 0;
}

//BottomUp
//���������� 0�� 0, �ܴ̿� 1�� �־��ְ� ������ ������ ��ȣ�� �������� �ջ��Ѵ�

//#include <iostream>
//using namespace std;
//
//# define LIMIT  1000000000
//int DP[101][10][1024]{};
//
//int N = 0;
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	cin >> N;
//
//	for (int i = 1; i < 10; i++)
//		DP[1][i][static_cast<int>(1 << i)] = 1;
//
//
//	for(int i=1; i<=N;i++)
//	{
//		//i ����
//		for(int num=0; num<10; num++)
//		{
//			//��������ȣ num ���� ����
//			//0�� ���� �������� 1���� �ʿ��ϰ�  9�� �������� 8�� �ʿ���
//			//������ 1~ 8 ������Ʈ�� ���� +-1�� �ʿ���
//
//			for(int bit=0; bit<1024; bit++)
//			{
//				//�湮ó�� bit�� ���� �湮�������̹Ƿ� ���Ӱ� Num�� or ����
//				int sum = 0;
//				if (num == 0)
//					sum = DP[i - 1][1][bit];
//				else if(num == 9)
//					sum = DP[i - 1][8][bit];
//				else
//				{
//					sum += DP[i - 1][num-1][bit];
//					sum = (sum +DP[i - 1][num+1][bit]) %LIMIT;
//
//				}
//				//if(sum>=1 and i>2)
//					DP[i][num][bit | 1<<num] = (DP[i][num][bit | 1 << num]+ sum) %LIMIT ;
//			}
//			
//		}
//	}
//	int Answer = 0;
//
//	for (int i = 0; i < 10; i++)
//	{
//		Answer = (Answer+DP[N][i][1023])%LIMIT;
//	}
//
//	cout << Answer;
//	return 0;
//}