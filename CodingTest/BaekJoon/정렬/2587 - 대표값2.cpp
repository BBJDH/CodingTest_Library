/*
 *2587 - ��ǥ��2
 *
 *�ռ� ����Ʈ�� ���� �����Ͽ� ������ Ǯ������,
 *
 *����� algorithm���� �����Ǵ� ����Ʈ �Լ��� ����ϸ� ���� �ذ� �����ϴ�.
 *
 *
 */

#include<iostream>
#include <algorithm>

using namespace std;


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Nums[5]{};
	int Sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> Nums[i];
		Sum += Nums[i];
	}
	sort(Nums, &Nums[5]);
	cout << Sum / 5 << "\n" << Nums[2];

	return 0;
}