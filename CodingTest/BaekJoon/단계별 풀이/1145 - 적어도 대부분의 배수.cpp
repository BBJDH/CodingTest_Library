#include <iostream>
#include <algorithm>
using namespace std;

int Target_Nums[5]{};

int main()
{

	for (int i = 0; i < 5; i++)
		cin >> Target_Nums[i];

	sort(Target_Nums, &Target_Nums[5]);

	int Check = 0;
	int Mul = 0;
	while (Check < 3)
	{
		Mul++;
		Check = 0;
		for (int i = 0; i < 5; i++)
		{
			if ((Mul % Target_Nums[i]) == 0)
				Check++;
		}
	}
	cout << Mul;

	return 0;

}