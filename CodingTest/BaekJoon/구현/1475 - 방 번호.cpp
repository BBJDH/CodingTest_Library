/*
 *1475 - �� ��ȣ
 *
 *�Է¹��� ���ڸ� ī�����Ͽ� �ִ� ��Ʈ���� ����Ѵ�.
 *
 *6�� 9�� ������ ���ڵ��� �Է¹��� �ִ� �� ��ŭ ī�弼Ʈ�� �����ؾ� �Ѵ�
 *
 *������ 6�� 9�� ���� ���� ��޵ǹǷ� �� ��Ʈ�� ������ ����ִ� ���̴�
 *
 *6�� 9�� ������ �ִ� ī��Ʈ�� ����صΰ� 6�� 9�� �����ؾ� �ϴ� �ִ� ���弼Ʈ����
 *
 *���Ͽ� �ִ밪�� �����Ѵ�.
 *
 */

#include <iostream>
#include <string>

using namespace std;

int NumOfInputCount[10]{};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};
	int Result = 0;
	cin >> InputStr;

	for (int i = 0; i < InputStr.size(); i++)
	{
		int Num = static_cast<int>(InputStr[i] - '0');
		NumOfInputCount[Num]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 6 or i == 9)
		{
			continue;
		}
		Result = max(Result, NumOfInputCount[i]);
	}
	int NineOrSixCount = NumOfInputCount[6] + NumOfInputCount[9];
	int Divide_NOSC = NineOrSixCount / 2;
	if (NineOrSixCount % 2 == 1)
	{
		Divide_NOSC++;
	}
	Result = max(Result, Divide_NOSC);

	cout << Result;

	return 0;
}