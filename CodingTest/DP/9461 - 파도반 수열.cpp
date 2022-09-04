/*
9461 - �ĵ��� ����
 { 0,1,1,1,2,2,3,4,5,7,9 } ������ ��Ģ�� ã���� ����, ��ȭ������ ����Ѵ�
 ���ķδ� n = n-1 + n-5 �ǰ��谡 �����Ѵ�

 �����һ��� : ���ڰ� 9õ�� ������ �ö󰣴�(100��° �ﰢ�� 8õ8�鸸) ������ �����͸� ��������
*/
#include<iostream>

using namespace std;

long long DP[101] = { 0,1,1,1,2,2,3,4,5,7,9 };

void MakeDP()
{
	for (int i = 11; i < 101; i++)
		DP[i] = DP[i - 1] + DP[i - 5];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;

	MakeDP();

	cin >> TestCase;
	while (TestCase--)
	{
		int InputNum = 0;
		cin >> InputNum;
		cout << DP[InputNum] << "\n";
	}


	return 0;
}