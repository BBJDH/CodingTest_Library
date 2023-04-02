/*
 *13458 - ���� ����
 *
 *�� �����帶�� �Ѱ����� �ݵ�� �ʿ��ϹǷ� ������ ����ŭ �ְ����� �ʿ��ϴ�
 *
 *�� ������ �Ѱ����� �ش� �������� ��� ���� �� �� ���� ��� ����� ������.
 *
 *�Է��� �� ������ �ο��� ���� �־����� ������ ���ð����� �ο��� �־����Ƿ�
 *
 *������ �ο��� �迭�� ������ ���������� �Ѱ����� ���ð����ο��� �� ��
 *
 *�ΰ����� �ʿ� �ο����� ����� ������.
 *
 *�̸� ��� Result�� �����Ͽ� ����Ѵ�.
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

void Solution(vector<int> NumsOfPeople, int const MainCharge, int const SubCharge)
{
	long long  Result = 0;

	for (int const elem : NumsOfPeople)
	{
		int CurrentPeople = elem;
		Result++;
		CurrentPeople -= MainCharge;

		if (CurrentPeople > 0)
		{
			int DividedTimeOfSubCharge = CurrentPeople / SubCharge;
			Result += DividedTimeOfSubCharge;
			CurrentPeople -= DividedTimeOfSubCharge * SubCharge;
			if (CurrentPeople > 0)
			{
				Result++;
			}
		}
	}
	cout << Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<int> NumsOfPeople{};
	int NumOfRoom = 0;
	int MainCharge = 0;
	int SubCharge = 0;

	cin >> NumOfRoom;
	for (int i = 0; i < NumOfRoom; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		NumsOfPeople.push_back(InputNum);
	}

	cin >> MainCharge >> SubCharge;

	Solution(NumsOfPeople, MainCharge, SubCharge);

	return 0;
}