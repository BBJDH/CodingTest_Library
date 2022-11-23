 /*
2581 - �Ҽ�

�����佺�׳׽��� ü�� �̿�,
���� ������ ��� 10000���� ���� �ڿ����̹Ƿ� �迭ũ��� 10001�� ����
���� �����佺�׳׽��� ü�� ����

���ۼ�, ������ �Է� ����

*/

#include<iostream>
#include<bitset>

using namespace std;

bitset<10001> EratosthenesNum{};
int StartNum = 0, EndNum = 0;

void Check_NonPrimeNum()
{
	EratosthenesNum.set();
	EratosthenesNum[0] = EratosthenesNum[1] = false;
	//1���Ҽ��� �ƴϴ�
	for (int i = 2; i * i < 10001; i++)
	{
		if (EratosthenesNum[i])
		{
			for (int mul = 2; i * mul < 10001; mul++)
				EratosthenesNum[i * mul] = false;
		}
	}
}

void Solution()
{
	int Sum = 0;
	int MinPrimnum = 0;
	for (int i = StartNum; i <= EndNum; i++)
	{
		if (EratosthenesNum[i])
		{
			if (MinPrimnum == 0)
				MinPrimnum = i;
			Sum += i;
		}
	}
	if (Sum == 0)
	{
		cout << -1;
		return;
	}
	cout << Sum << "\n" << MinPrimnum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Check_NonPrimeNum();
	cin >> StartNum >> EndNum;
	Solution();
	return 0;
}
