#include"stdafx.h"

using namespace std;


void SubString_Char(string const& Origin_String, char const& Erase_Char, string& Dest_String)
{
	stringstream string_stream(Origin_String);
	string token;
	while (getline(string_stream, token, Erase_Char))
	{
		Dest_String += token;
	}
}


int main()
{
	//std::vector<int> numbers = { 1,1,1,1,1 };
	//std::vector<int> binery_code;

	//Make_Binery_Code(binery_code, 11, 8);

	//cout << solution(numbers, 3);



	string str = { "aerg-123524635-aerg-ath.gif" };
	string result;
	SubString_Char(str, '-', result);

	cout << result;
	//stringstream ss(str);
	//while (getline(ss, token, '-'))
	//{
	//	cout << token << endl;
	//}

	return 0;
}