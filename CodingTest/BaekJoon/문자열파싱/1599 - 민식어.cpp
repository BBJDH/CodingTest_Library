/*
 *1599 - 민식어
 *
 *먼저 입력받은 문자열을 np인지 검사를 하고 아니라면 각 알파벳을 map에서 찾아 0~20순의 알파벳으로 치환하여 삽입한다.
 *
 *삽입을 vector에 시행하고, 해당 string으로 정렬을 한다 ()
 *
 *꺼낼때는 배열로 매핑해둔것을 그대로 출력한다
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, string> StringToMinSik{ {"a", "a"},{"b","b"},{"k","c"},{"d","d"},{"e","e"},{"g","f"},{"h","g"},{"i","h"},
	{"l","i"},{"m","j"},{"n","k"},{"ng","l"},{"o","m"},{"p","n"},{"r","o"},{"s","p"},{"t","q"},{"u","r"},{"w","s"},{"y","t"} };

string Dictionary[20]{ "a","b","k","d","e","g","h","i",
	"l","m","n","ng","o","p","r","s","t","u","w","y" };
vector<string> ToSortStr{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int inputCase{};
	cin >> inputCase;
	while (inputCase--)
	{
		string inputStr{};
		cin >> inputStr;
		int index = 0;
		string insertStr{};
		while (index < inputStr.size())
		{
			if (index != inputStr.size() - 1 and (inputStr[index] == 'n' and inputStr[index + 1] == 'g'))
			{
				insertStr += StringToMinSik["ng"];
				index += 2;
				continue;
			}
			string key = inputStr.substr(index, 1);
			insertStr += StringToMinSik[key];
			index++;
		}
		ToSortStr.emplace_back(insertStr);
		sort(ToSortStr.begin(), ToSortStr.end());
	}
	for (auto const& Elem : ToSortStr)
	{
		for (int i = 0; i < Elem.size(); i++)
		{
			int index = Elem[i] - 'a';
			cout << Dictionary[index];
		}
		cout << "\n";
	}
	return 0;
}