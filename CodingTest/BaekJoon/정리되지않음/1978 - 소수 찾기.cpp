#include<iostream>
#include<vector>
using namespace std;

int Prime_Count = 0;

void Check_Prime(int const Target_Num)
{
	int count = 0;
	for (int i = 1; i <= Target_Num; i++)
	{
		if (Target_Num % i == 0)
			count++;


	}
	if (count == 2)
	{
		Prime_Count++;
		return;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> Nums;
	int TestCase = 0;

	cin >> TestCase;
	Nums.resize(TestCase);

	for (int i = 0; i < TestCase; i++)
		cin >> Nums[i];
	for (int i = 0; i < TestCase; i++)
		Check_Prime(Nums[i]);

	cout << Prime_Count;

	return 0;
}