/*
10986 - ������ ��

6 2
1 3 3 1 1 3
�� ���÷� �����غ���

�������� ���غ���
1 4 7 8 9 12 ���� �ذ� ������ ��츦 �̾ƺ���
1, 7, 9		�� ���鿡�� ������ ���ϸ� �ݵ�� ���� M���� ����������
4, 8, 12	�� ���鿡�� ������ ���ϸ� �ݵ�� ���� M���� ����������
���� ������� ��� ������ ���� ���� ���Ѵ�
�ٽ� �����غ���, {1, 7, 9}(������ 1), {4, 8, 12}(������0)
�������� ���� ���ڿ� ���� ������ �̴´� �������� ���� �ĺ���̼� 2

���� ���������� ���� �������� �������� ���� ������ ī���� ���־�� �ϹǷ�(�ռ� ���ߵ� ������ ���̴� �߿����� �ʴ�)

���� �� �Ѱ��� ���ҷ� ���������� ��츦 �߻�
�Է� ������ �̸� ���� �� ���� 0�� �Ǵ°�츦 ī���� ���ش�

����� ���� �������� ������ ������ int�� �ʰ��Կ� ����
*/
#include<iostream>
#include<vector>
using namespace std;

vector<long long> Nums{};

int ModNum = 0;
long long Count = 0;
void Solution()
{

	for (int i = 0; i < Nums.size(); i++)
	{
		Count += (Nums[i] * (Nums[i] - 1)) / 2;
	}
	cout << Count;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int NumSize = 0;

	cin >> NumSize >> ModNum;
	long long Sum = 0;
	Nums.resize(ModNum);

	while (NumSize--)
	{
		int InputNum = 0;
		cin >> InputNum;
		Sum += InputNum;
		Nums[Sum % ModNum]++;
		if (Sum % ModNum == 0)
			Count++;
	}
	Solution();

	return 0;
}