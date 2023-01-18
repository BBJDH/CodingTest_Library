/*
 *1427 - ��Ʈ�λ��̵�
 *
 *�Է¹��� ������ 10���� ���� �������� �迭�� �����Ѵ�
 *������ �迭�� ������������ ���� �� ���
 *���������� ����� �����Ѵ�.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> Nums{};
	int inputNum = 0;
	cin >> inputNum;

	while (inputNum)
	{
		int Num = inputNum % 10;
		inputNum /= 10;
		Nums.push_back(Num);
	}
	sort(Nums.begin(), Nums.end(), greater<>());

	for (auto const& elem : Nums)
		cout << elem;
	return 0;
}