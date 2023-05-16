/*
 *11656 - 접미사 배열
 *
 *입력 받은 문자열을 string에 저장한다
 *
 *이후 0번 인덱스로부터 각각 문자열을 substr로 잘라서 벡터에 삽입한다.
 *
 *삽입된 벡터를 string 사전순 정렬을 시행한다.
 *
 *정렬된 결과를 출력한다.
 *
 */


#include<iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};
	vector<string> Suffix{ };

	cin >> InputStr;

	for (int i = 0; i < InputStr.size(); i++)
	{
		Suffix.push_back(InputStr.substr(i, InputStr.size() - i));
	}
	sort(Suffix.begin(), Suffix.end());

	for (string const& Elem : Suffix)
	{
		cout << Elem << "\n";
	}


	return 0;
}