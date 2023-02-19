/*
 *1049 - ��Ÿ��
 *
 *���� ���� ��Ű�����ݰ� ���� ������ �̿���
 *�����ظ� ���س����� �����̴�
 *
 *�׽�Ʈ���̽����� ������ ��Ű���� �����ϴ°�캸��
 *������ �����ϴ°� �� �� ��찡 �����Ѵ�.
 *
 *N�� 6���� ���� ��ŭ�� ��Ű�� �������� �����ϰ�
 *������ ��°��� ��Űġ �ѹ��� ������ ���� �������� ���Ѵ�
 *
 *���������� �����θ� �����ϴ°�찡 �� �� ��쵵 �����ϹǷ�
 *�̸� ���� ����Ѵ�.
 *
 *���������ʰ� vector�� �ʿ���� min������ ���Ͽ� ��Ű���� ����������
 *�ּҰ��ݸ� ������ ����ϴ°��� �����ϴ�.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
vector<int> PricePackage{};
vector<int> PriceAnItem{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Result = 0;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int package = 0, anItem = 0;
		cin >> package >> anItem;
		PricePackage.push_back(package);
		PriceAnItem.push_back(anItem);
	}
	sort(PricePackage.begin(), PricePackage.end());
	sort(PriceAnItem.begin(), PriceAnItem.end());

	Result += (N / 6) * PricePackage[0];

	Result += min((N % 6) * PriceAnItem[0], PricePackage[0]);

	if (N * PriceAnItem[0] > Result)
		cout << Result;
	else
		cout << N * PriceAnItem[0];


	return 0;
}