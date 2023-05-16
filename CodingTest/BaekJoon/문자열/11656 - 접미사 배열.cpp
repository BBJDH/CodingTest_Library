/*
 *11656 - ���̻� �迭
 *
 *�Է� ���� ���ڿ��� string�� �����Ѵ�
 *
 *���� 0�� �ε����κ��� ���� ���ڿ��� substr�� �߶� ���Ϳ� �����Ѵ�.
 *
 *���Ե� ���͸� string ������ ������ �����Ѵ�.
 *
 *���ĵ� ����� ����Ѵ�.
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