#include <iostream>
#include <vector>
using namespace std;

int Nums[10001]{};

void Mark_Prime()
{
	int Max_Num = 100;
	Nums[1] = 1;
	for (int i = 2; i <= Max_Num; i++)
	{

		if (Nums[i] == 1)
		{
		}
		else
		{
			for (int j = i * i; j < 10001; j += i)
			{
				Nums[j] = 1;
			}
		}
	}
}
void Print_Goldbach(int const Target_Num)
{
	for (int i = Target_Num / 2; i > 0; i--)
	{
		if (Nums[i] == 0 and Nums[Target_Num - i] == 0)
		{
			cout << i << " " << Target_Num - i << "\n";
			break;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> Input_Nums;

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		int Input_Num = 0;
		cin >> Input_Num;
		Input_Nums.push_back(Input_Num);
	}
	Mark_Prime();
	for (auto& i : Input_Nums)
	{
		Print_Goldbach(i);
	}
	return 0;
}
