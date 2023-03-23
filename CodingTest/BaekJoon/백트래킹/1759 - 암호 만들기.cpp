/*
 *
 * 1759 - ��ȣ �����
 *
 * ��Ʈ��ŷ�� �̿��� Ǯ����.
 *
 * ������ ���ϱ� ���� �������� ������ ���� ����, �־��� ��й�ȣ ���̸� �̿���
 *
 * ��Ʈ��ŷ���� �Էµ� ���ĺ� �� ��й�ȣ�� ���̿� �ش��ϴ� ��� ������ ���Ѵ�.
 *
 * ������ ���ĺ��� ������ ���� ������ �����ȴٸ� Result �迭�� �߰��ϰ� �׷��� �ʴٸ� �����Ѵ�.
 *
 * ��Ʈ��ŷ�� ������ ������ Result �迭�� ����ϰ� �����Ѵ�.
 *
 * �־��� ��й�ȣ�� ũ��, �Է¹��� ���ڵ�, ����� ������ �ʿ䰡 �����Ƿ� ���������Ѵ�.
 *
 * �̿ܿ� �� ��Ʈ��ŷ���� ��������� ��������� ���յ� ��й�ȣ, �̿� ���� Ž������, ������ ���� �������� �������� ���� �ʴ´�.
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