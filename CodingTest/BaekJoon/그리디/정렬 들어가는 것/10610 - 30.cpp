/*
 *10610 - 30
 *
 *ó������ ��� ���� ���ؼ� �������κ��� ���� ������ ����Ž���ϰ��� �Ͽ���.
 *������ �Է� �޴� ���� ������ 10��5������  10�����̴� �ð����⵵�� ����ϰ�
 *10�����ڸ����� ��� ������ ������ ���� ����.
 *
 *������ � ��Ģ�� ������ �����غ��ٰ� �ᱹ ��Ģ�� ã�ƺ��� �Ǿ���..
 *
 *����� 30�� ����� ������ ��Ȯ�� ������ �����Ѵ�.
 *
 *���� ���ڿ��ӿ� 0�� �Ѱ��� �����ؾ� �ϸ�,
 *�� ��� �ڸ����� ���� 3�� ������� �Ѵ�
 *
 *�ش� ������ �����Ѵٸ� �� ���ڵ��� �������� �����Ͽ� 30�� ����� ���� �� �ִ�.
 *(��Ű ����� ��� �������� ��������.)
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string inputStr{};
	bool IsInZero = false;
	int Sum = 0;
	vector<int>Nums{};
	cin >> inputStr;

	for (char const elem : inputStr)
	{
		if (elem == '0')
			IsInZero = true;

		int parseNum = elem - '0';
		Sum += parseNum;
		Nums.push_back(parseNum);
	}

	if (IsInZero == false or Sum % 3 != 0)
	{
		cout << -1;
		return 0;
	}
	sort(Nums.begin(), Nums.end(), greater<>());

	for (int const elem : Nums)
	{
		cout << elem;
	}

	return 0;
}