/*
 *1316 - 그룹 단어 체커
 *
 *단어 하나에 대하여 생각해본다
 *중복을 체크해줄 26개의 소문자 배열을 만들고
 *새로운 단어라면 배열에 체크하고 같은문자를 모두 건너뛴다
 *이후로 다시 문자가 등장하면 false를 리턴
 *
 *
 */



#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Str{};
int StringCount = 0;



bool IsGroupStr(string const& Str)
{
	bool checkChar[26]{};

	for (int i = 0; i < Str.size(); i++)
	{
		int newVisit = Str[i] - 'a';

		if (checkChar[newVisit])
			return false;
		else
		{
			checkChar[newVisit] = true;
			char overlapChar = Str[i];
			//겹치는 문자 건너뛰기
			while (overlapChar == Str[i])i++;

			//다음문자로 넘어가있으므로 한번 되돌림, 다음 for문에서 i++후 시작되므로
			i--;
		}
	}
	return true;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> StringCount;
	int Count = 0;
	for (int i = 0; i < StringCount; i++)
	{
		string inputStr{};
		cin >> inputStr;
		if (IsGroupStr(inputStr))
			Count++;
	}
	cout << Count;

	return 0;
}