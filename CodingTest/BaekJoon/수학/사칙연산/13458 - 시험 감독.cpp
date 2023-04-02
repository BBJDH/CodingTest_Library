/*
 *13458 - 시험 감독
 *
 *각 시험장마다 총감독은 반드시 필요하므로 시험장 수만큼 주감독이 필요하다
 *
 *부 감독은 총감독이 해당 시험장을 모두 감시 할 수 없는 경우 계산해 나간다.
 *
 *입력이 각 시험장 인원이 먼저 주어지고 감독의 감시가능한 인원이 주어지므로
 *
 *시험장 인원을 배열로 저장해 순차적으로 총감독의 감시가능인원을 뺀 후
 *
 *부감독의 필요 인원수를 계산해 나간다.
 *
 *이를 모두 Result에 누적하여 출력한다.
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