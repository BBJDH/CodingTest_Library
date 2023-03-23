/*
 *
 * 1759 - 암호 만들기
 *
 * 백트래킹을 이용해 풀었다.
 *
 * 조합을 구하기 위해 시작점과 자음과 모음 개수, 주어진 비밀번호 길이를 이용해
 *
 * 백트래킹으로 입력된 알파벳 중 비밀번호의 길이에 해당하는 모든 조합을 구한다.
 *
 * 구해진 알파벳의 모음과 자음 갯수가 충족된다면 Result 배열에 추가하고 그렇지 않다면 종료한다.
 *
 * 백트래킹이 끝난후 구해진 Result 배열을 출력하고 종료한다.
 *
 * 주어진 비밀번호의 크기, 입력받은 문자들, 결과는 복제될 필요가 없으므로 참조전달한다.
 *
 * 이외에 각 백트래킹에서 만들어지고 사라져야할 조합된 비밀번호, 이에 따른 탐색범위, 자음과 모음 갯수들은 참조전달 하지 않는다.
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void BackTracking(int const IndexOfStart, int const CountOfVowel, int const CountOfConsonant, int const& PasswordLength,
	vector<char> const& InputAlphabets, vector<string>& ResultOfPassWords, string Password)
{
	if (Password.size() == PasswordLength)
	{
		if (CountOfVowel >= 1 and CountOfConsonant >= 2)
		{
			ResultOfPassWords.push_back(Password);
		}

		return;
	}

	for (int i = IndexOfStart; i < InputAlphabets.size(); i++)
	{
		if (InputAlphabets[i] == 'a' or InputAlphabets[i] == 'e' or InputAlphabets[i] == 'i' or InputAlphabets[i] == 'o' or InputAlphabets[i] == 'u')
		{
			BackTracking(i + 1, CountOfVowel + 1, CountOfConsonant, PasswordLength, InputAlphabets, ResultOfPassWords, Password + InputAlphabets[i]);

		}
		else
		{
			BackTracking(i + 1, CountOfVowel, CountOfConsonant + 1, PasswordLength, InputAlphabets, ResultOfPassWords, Password + InputAlphabets[i]);
		}
	}
}

void Solution(vector<char>& InputAlphabets, int const PasswordLength)
{
	sort(InputAlphabets.begin(), InputAlphabets.end());
	vector<string> ResultOfPassWords{};
	BackTracking(0, 0, 0, PasswordLength, InputAlphabets, ResultOfPassWords, string{});

	for (string const& elem : ResultOfPassWords)
	{
		cout << elem << "\n";
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<char> InputAlphabets{};
	int PasswordLength = 0;
	int InputCount = 0;

	cin >> PasswordLength >> InputCount;

	for (int i = 0; i < InputCount; i++)
	{
		char Input{};
		cin >> Input;
		InputAlphabets.push_back(Input);
	}

	Solution(InputAlphabets, PasswordLength);
	return 0;
}