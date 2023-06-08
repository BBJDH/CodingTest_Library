/*
 *1339 - 단어 수학
 * 
 * 문자의 등장위치마다 가중치를 누적하고 이 총합을 정렬하여 그리디로 풀어나간다.
 *
 *가장 긴 문자열의 앞 문자는 가장 큰 숫자를 배정한다.
 *
 *같은 위치에 존재하는 알파벳들이 존재한다면 중복되는 횟수가 많은 알파벳이 우선된다.
 *
 *자리수 별로 알파벳의 가중치를 부여하기위해 Count 배열을 만든다.
 *
 *ACDEB 의 단어를 만난경우
 *
 *11111 의 가중치를 나눠서 가진다
 *
 *A의 경우 10000
 *C의 경우 1000
 *D의 경우 100
 *E의 경우 10
 *B의 경우 1이 되는 것이다.
 *
 *차후 중복된 문자가 다른 위치에 등장할 수 있으므로 위와같이 가중치를 책정하고
 *AlphabetCount에 인덱스를 알파벳-'A'로 하여 매핑해둔다
 *
 *이후 가중치 순으로 알파벳들을 정렬하고 AlphabetToNum 배열에 각 숫자 문자를 배정해 준다.
 *
 *이제 입력받았던 문자들을 숫자로 바꾸어 모두 더해주기만 하면 된다.
 *각 문자열을 AlphabetToNum로부터 할당된 숫자들로 바꾸어준 후,
 *stoi를 통해 모두 합산하여 결과를 출력한다.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Node
{
	char Alphabet;
	int Count;
};

bool operator>(Node const& Left, Node const& Right)
{
	return Left.Count > Right.Count;
}
bool operator<(Node const& Left, Node const& Right)
{
	return Left.Count < Right.Count;
}

char AlphabetToNum[26]{};
int AlphabetCount[26]{};



int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<string> Alphabets{};
	vector<Node> AlphabetToSort{};

	int Size = 0;

	cin >> Size;
	for (int i = 0; i < Size; i++)
	{
		string InputStr{};
		cin >> InputStr;

		Alphabets.push_back(InputStr);

		for (int i = 0; i < InputStr.size(); i++)
		{
			int const AlphabetIndex = InputStr[i] - 'A';
			int Count = 1;
			int Pos = static_cast<int>(InputStr.size()) - i - 1;
			while (Pos--)
			{
				Count = Count * 10;
			}

			AlphabetCount[AlphabetIndex] += Count;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (AlphabetCount[i] != 0)
		{
			AlphabetToSort.push_back({ static_cast<char>('A' + i), AlphabetCount[i] });
		}
	}
	sort(AlphabetToSort.begin(), AlphabetToSort.end(), greater<>());

	int CurrentNum = 9;
	for (int i = 0; i < AlphabetToSort.size(); i++)
	{
		int const AlphabetIndex = AlphabetToSort[i].Alphabet - 'A';
		char MappedNumchar = CurrentNum + '0';
		CurrentNum--;

		AlphabetToNum[AlphabetIndex] = MappedNumchar;
	}

	int Result = 0;

	for (string& Elem : Alphabets)
	{
		for (int i = 0; i < Elem.size(); i++)
		{
			int const AlphabetIndex = Elem[i] - 'A';
			Elem[i] = AlphabetToNum[AlphabetIndex];
		}
		Result += stoi(Elem);
	}
	cout << Result;
	return 0;
}