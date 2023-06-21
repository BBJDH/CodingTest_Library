/*
 *1449 - ������ �׽�
 *
 *�������� �¿� 0.5��ġ��ŭ�� ������ ����Ѵٴ� ����
 *�����Ǵ°����� 1���;� �������� ����Ѵٴ� �ǹ��̴�.
 *�� �������� ���̰� 2�̰� ������ �� ��ġ�� 1, 2���
 *
 *1�� 2�� 2����¥�� ������ �������� �Ѵ� ���� �� �ִ�.
 *(0.5~2.5�� ��� Ŀ��!)
 *
 *���� ����, �� ���Ҹ� ������������ �����Ͽ� ���������� �������� �̾ �� �ְ� �����.
 *
 *���� ù ���Ҹ� �������� Left�� Right�� �����Ѵ�.
 *�̶� �������� ������ Left, �����ʳ��� Right��� �غ���
 *Right�� ���� ���������� �ÿ����� �������� �ִ���� ���� �����غ���.
 *���� �������� ������ �� Right�� ���� �ʴ� ���� ��Ÿ���ٸ� ���Ⱑ �ٽ� Left�� �������ȴ�.
 *
 *���� �ٽ�Right�� Left���� ���������� �ÿ������� ������ �����Ѵ�.
 *Right�� �Է¹��� ��� ���Ҹ� ��ȸ�ߴٸ� ��� ������ �������Ƿ� �ݺ����� �����Ѵ�.
 *
 *�ݺ��� ��������� ������ �������� �������� �ʾ����Ƿ� ī���õ� Right+1�� ����Ѵ�.
 *
 */

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<int> PlaceToSolve{};
	int CountOfPlace = 0, LengthOfTape = 0;
	int Result = 0;

	cin >> CountOfPlace >> LengthOfTape;

	while (CountOfPlace--)
	{
		int PlaceNum = 0;
		cin >> PlaceNum;
		PlaceToSolve.push_back(PlaceNum);
	}

	sort(PlaceToSolve.begin(), PlaceToSolve.end());

	int Left = 0;
	int Right = 0;
	while (Right < PlaceToSolve.size())
	{
		int const Length = PlaceToSolve[Right] - PlaceToSolve[Left];
		if (Length >= LengthOfTape)
		{
			Left = Right;
			Result++;
		}
		Right++;
	}
	cout << Result + 1;
	return 0;
}