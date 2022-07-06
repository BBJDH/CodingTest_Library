#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>
#include <stack>
#include<sstream>
using namespace std;

int Is_Printing = false;
void Change_Oct_to_Binery(int const num)
{
	for (int i = 2; i >= 0; i--)
	{
		int Single_Binery = num >> i & 1;
		if (Single_Binery)
			Is_Printing = true;
		if (Is_Printing)
			cout << Single_Binery;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char input[333335]{};


	cin >> input;

	if (strlen(input) == 1 and input[0] == '0')
	{
		cout << 0;
		return 0;
	}
	int index = 0;
	while (input[index])
	{

		Change_Oct_to_Binery(input[index] - '0');
		index++;
	}
	return 0;
}