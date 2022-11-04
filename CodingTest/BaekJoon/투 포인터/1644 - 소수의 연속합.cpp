/*
1644 - �Ҽ��� ������

�����佺�׳׽��� ü�� �Ҽ��� ã��
�̿� ���� ������ �迭�� �����Ѵ�
�̰��� �������ͷ� �������� Ž��(Left Right �����Ͱ� �������� �����Ѵ�)
Ž���ϸ� ��ġ�ϴ� ���� �����ϸ� Count ���� �� ���� ���

*/



#include <iostream>
#include <vector>

using namespace  std;

bool Nums[4000001]{};
vector<int> PrimeNums{};
int TargetNum = 0;


void MarkNonPrime()
{
	Nums[0] = true;
	Nums[1] = true;
	for (int i = 2; i * i <= 4000000; i++)
	{
		if (Nums[i] == false)
		{
			for (int j = 2; j * i <= 4000000; j++)
			{
				Nums[i * j] = true;
			}
		}
	}
}
void PushPrimeNum()
{
	int Sum = 0;

	PrimeNums.emplace_back(Sum);
	for (int i = 2; i <= 4000000; i++)
	{
		if (Nums[i] == false)
		{
			Sum += i;
			PrimeNums.emplace_back(Sum);
		}
	}
}

void FindCountSum()
{
	int Left = 0;
	int Right = 1;
	int Count = 0;
	while (Left < Right and Right < PrimeNums.size())
	{
		int Sum = PrimeNums[Right] - PrimeNums[Left];
		if (Sum == TargetNum)
			Count++;
		if (Sum <= TargetNum)
			Right++;
		else
			Left++;
	}
	cout << Count;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	MarkNonPrime();
	PushPrimeNum();

	cin >> TargetNum;

	FindCountSum();

	return 0;
}