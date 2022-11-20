/*
 *11653 - ���μ�����
 *
 *�ݺ��� - 2���� ����, ������ �ִٸ� ���̻� ���� �� ���������� ����, �Ҽ���� ��ü �״�� ��������
 *���� ���� 1���� ũ�ٸ� ���
 *
 *��� - �����Ǽ��� �޾Ƽ� 2���� ������ ���������ٸ� �� ���� ���, ���� ���� ���ȣ��
 *���������� �ʴ´ٸ� �״�� ��������, 1���� ũ�ٸ� ���
 */

#include <iostream>

using namespace std;


//�ݺ���

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputNum = 0;
	cin >> inputNum;

	for (int i = 2; i * i <= inputNum; i++)
	{
		while (inputNum % i == 0)
		{
			inputNum /= i;
			cout << i << "\n";
		}
	}
	if (inputNum > 1)
		cout << inputNum;

	return 0;
}


//���
//int DivideNum(int const &Num)
//{
//	for(int i=2; i<Num; i++)
//	{
//		if(Num%i ==0)
//		{
//			cout << i << "\n";
//			return DivideNum( Num / i);
//		}
//	}
//	return Num;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int inputNum = 0;
//	cin >> inputNum;
//	if(inputNum!=1)
//		cout << DivideNum(inputNum);
//
//	return 0;
//}
