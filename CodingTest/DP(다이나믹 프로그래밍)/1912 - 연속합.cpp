

/*
1912 - ������

���ӵ� ���� ���� �����Ұ���, ������Ʈ �Ǵ� �������߿��� �ִ����� ������ ���� ����,
�Էµ� ��ȣ�� ���ϰ� ���� ���� ���� �տ� ����, �������� �Էµ� ��ȣ���� �۴ٸ� ��ȣ�� ����
�׸��� ������Ʈ�� �������� �������� ���� �ִ��հ� ��, ������Ʈ


*/
#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int MaxSum = -2000;
	int CurrentSum = 0;
	int NumSize = 0;
	cin >> NumSize;

	while (NumSize--)
	{
		int InputNum = 0;

		cin >> InputNum;
		CurrentSum += InputNum;
		if (CurrentSum < InputNum)
			CurrentSum = InputNum;
		if (CurrentSum > MaxSum)
			MaxSum = CurrentSum;
	}
	cout << MaxSum;

	return 0;
}
