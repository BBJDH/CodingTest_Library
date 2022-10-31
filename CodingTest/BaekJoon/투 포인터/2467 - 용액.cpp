/*
2467 - ���

���ĵ� ��ȣ����
������ ���� Left Right�� �ΰ�,
Left Right�� ���� 0���� �۴ٸ� Left�� ����
���� 0���� ũ�ٸ� Right ���ҷ� ���� ������ ���� �ݺ����� ���� ���� ����Ѵ�
���� ���� ���̰� ���� ���� ����/���

*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct _int3
{
	int Left;
	int Right;
	int Sum;
};

vector<int> Nums{};
//              1,000,000,000*2
_int3 Result{ 0,0,2000000001 };
int NumSize = 0;


void Search()
{
	int Left = 0;
	int Right = static_cast<int>(Nums.size()) - 1;

	while (Left < Right)
	{
		int const Sum = Nums[Left] + Nums[Right];

		if (abs(Sum) < Result.Sum)
		{
			Result.Left = Nums[Left];
			Result.Right = Nums[Right];
			Result.Sum = abs(Sum);
		}

		if (Sum < 0)
			Left++;
		else
			Right--;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> NumSize;
	while (NumSize--)
	{
		int InputNum = 0;
		cin >> InputNum;
		Nums.emplace_back(InputNum);
	}
	sort(Nums.begin(), Nums.end());
	Search();
	cout << Result.Left << " " << Result.Right;

	return 0;
}