/*
 *1764 - �躸��
 *
 *�Է¹޴� �� ���ڿ� ������ �������� ���������� �����Ͽ� ����ϴ� �����̴�.
 *
 *���� �Է¹޴� �赵 ���� ������� set���� �����Ѵ�.
 *(value�� �ʿ���� Key�� ��ȸ�� �����̹Ƿ� map�� ���� �ʴ´�.)
 *
 *���� �Է¹��� ������ ���� ������� ������ �Է¹��� set������ ã�´�
 *ã���� ���ڿ��� vector�� �����Ͽ� ���� �� ����Ѵ�.
 *
 */

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	set<string> NeverHeard{};
	vector<string> Result{};
	int SizeOfNeverHeard = 0, SizeOfNeverMet = 0;
	cin >> SizeOfNeverHeard >> SizeOfNeverMet;

	for (int i = 0; i < SizeOfNeverHeard; i++)
	{
		string InputStr{};
		cin >> InputStr;
		NeverHeard.insert(InputStr);
	}
	for (int i = 0; i < SizeOfNeverMet; i++)
	{
		string InputStr{};
		cin >> InputStr;
		if (NeverHeard.find(InputStr) != NeverHeard.end())
		{
			Result.push_back(InputStr);
		}
	}
	sort(Result.begin(), Result.end());

	cout << Result.size() << "\n";
	for (string const& elem : Result)
	{
		cout << elem << "\n";
	}

	return 0;
}