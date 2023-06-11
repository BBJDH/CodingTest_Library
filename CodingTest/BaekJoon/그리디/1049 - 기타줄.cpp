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
 *
 *
 * 23.06.11  ���� ����
 *
 *�� �Է� ���� ��Ʈ ���ݰ� �� ������ �귣��� �������
 *���� ���� ��Ʈ���ݰ� ���� ���� �Ѱ� ���ݸ��� �ʿ��ϴ�.
 *
 *����  min�� ���� ���� �ΰ����� ���Ͽ�
 *
 *���� ���� ������ 6�� �̻��̶�� ��Ʈ ���ݰ� �Ѱ����� * 6 ��  ���Ͽ� �����ϰ�
 *���� ���� ������ 6�� �̸��̶�� ��Ʈ ���ݰ� �Ѱ����� * ���Ű��� �� ���Ͽ� �ݺ����� ���� ����Ѵ�. 
 *
 */




#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int NumOfPurchases = 0;
	int BrandNum = 0;
	cin >> NumOfPurchases >> BrandNum;

	int PriceOfSet = 1001;
	int PriceOfOne = 1001;

	while (BrandNum--)
	{
		int InputSet = 0, InputOne = 0;
		cin >> InputSet >> InputOne;

		PriceOfSet = min(PriceOfSet, InputSet);
		PriceOfOne = min(PriceOfOne, InputOne);
	}

	int Result = 0;

	while ((NumOfPurchases < 6 and PriceOfSet < PriceOfOne * NumOfPurchases) or (NumOfPurchases >= 6 and PriceOfSet < PriceOfOne * 6))
	{
		Result += PriceOfSet;
		NumOfPurchases -= 6;
	}
	if (NumOfPurchases > 0)
	{
		Result += NumOfPurchases * PriceOfOne;
	}

	cout << Result;

	return 0;
}





/*
 *
 * ���� �� �ڵ�
 */
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N = 0, M = 0;
//vector<int> PricePackage{};
//vector<int> PriceAnItem{};
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	int Result = 0;
//
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int package = 0, anItem = 0;
//		cin >> package >> anItem;
//		PricePackage.push_back(package);
//		PriceAnItem.push_back(anItem);
//	}
//	sort(PricePackage.begin(), PricePackage.end());
//	sort(PriceAnItem.begin(), PriceAnItem.end());
//
//	Result += (N / 6) * PricePackage[0];
//
//	Result += min((N % 6) * PriceAnItem[0], PricePackage[0]);
//
//	if (N * PriceAnItem[0] > Result)
//		cout << Result;
//	else
//		cout << N * PriceAnItem[0];
//
//
//	return 0;
//}