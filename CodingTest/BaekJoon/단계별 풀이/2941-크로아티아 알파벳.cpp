#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>
#include <stack>
#include<sstream>
using namespace std;
string Croatia_Alphabat[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

void Change_Single_Alpabat(string& target)
{
	string replace_str = "a";

	for (int i = 0; i < 8; i++)
	{

		while (target.find(Croatia_Alphabat[i]) != string::npos)
		{

			target.replace
			(
				target.find(Croatia_Alphabat[i]),
				Croatia_Alphabat[i].length(),
				replace_str
			);
		}

	}
	int debug = 0;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string input_string = "";
	cin >> input_string;

	Change_Single_Alpabat(input_string);
	cout << input_string.length();

	return 0;
}
