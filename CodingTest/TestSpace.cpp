#include <iostream>
#include <map>

using namespace std;


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		int ComputerToExponent[10]{};
		fill_n(ComputerToExponent,100, -1);
		int Num = 0, Exponent = 0, LoopNum = 0;
		cin >> Num >> Exponent;
		for(int exp=1; exp<Exponent; exp++)
		{
			Num = (Num * Num) % 10;
			if(ComputerToExponent[Num] != -1)
			{
				LoopNum = exp;
				break;
			}
			ComputerToExponent[Num] = exp;
		}
		int ModNumOfExponent = Exponent % LoopNum;
		int Result = 0;
		for(int i=0; i<10; i++)
		{
			if(ComputerToExponent[i]== ModNumOfExponent)
			{
				Result = i;
				break;
			}
		}
		cout << Result << "\n";
	}

	return 0;
}