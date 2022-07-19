#include <iostream>

using namespace std;


int Recursion_CallCount = 0;

int Fibonacci_Recursion(int const n)
{
	if (n == 1 or n == 2)
	{
		Recursion_CallCount++;
		return 1;
	}
	else return(Fibonacci_Recursion(n - 1) + Fibonacci_Recursion(n - 2));
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int FibNum = 0;

	cin >> FibNum;
	Fibonacci_Recursion(FibNum);
	cout << Recursion_CallCount << " " << FibNum - 2;
}
