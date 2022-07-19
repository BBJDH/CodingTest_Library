#include<iostream>

using namespace std;
int LengthNum = 0;
int MarkNums[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int Solution()
{
	if (LengthNum == 1)
		return 10;
	int StartNum = 1;
	int anwser = 0;
	while (StartNum < LengthNum)
	{
		for (int i = 9; i > 0; i--) //0번은 항상 1일것이므로
		{
			int sum = 0;
			for (int j = 0; j <= i; j++)
			{
				sum += MarkNums[j];
			}
			sum %= 10007;
			MarkNums[i] = sum;
		}
		StartNum++;
	}
	for (int i = 0; i < 10; i++)
	{
		anwser += MarkNums[i];
		anwser %= 10007;
	}
	return anwser;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> LengthNum;
	cout << Solution();


	return 0;
}