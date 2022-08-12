#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> InputNums{};
vector<int> SubNums{};
vector<int> Divisors{};

int GreatestCommomDenominator(int const BigNum, int const SmallNum)
{
	if (BigNum % SmallNum == 0)
		return SmallNum;

	return GreatestCommomDenominator(SmallNum, BigNum % SmallNum);
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int NumSize = 0;

	cin >> NumSize;

	while (NumSize--)
	{
		int InputNum = 0;
		cin >> InputNum;
		InputNums.push_back(InputNum);
	}
	sort(InputNums.begin(), InputNums.end());

	for (int i = 1; i < InputNums.size(); i++)
	{
		SubNums.push_back(InputNums[i] - InputNums[i - 1]);
	}
	sort(SubNums.begin(), SubNums.end());

	int GreatestCommonDenominetor = SubNums[0];
	for (int i = 1; i < SubNums.size(); i++)
	{
		GreatestCommonDenominetor = GreatestCommomDenominator(SubNums[i], GreatestCommonDenominetor);
	}

	Divisors.push_back(GreatestCommonDenominetor);
	for (int i = 2; i * i <= GreatestCommonDenominetor; i++)
	{
		if (GreatestCommonDenominetor % i == 0)
		{
			Divisors.push_back(i);
			if (i * i != GreatestCommonDenominetor)
				Divisors.push_back(GreatestCommonDenominetor / i);
		}
	}
	sort(Divisors.begin(), Divisors.end());

	for (int i = 0; i < Divisors.size(); i++)
		cout << Divisors[i] << " ";

	return 0;
}
