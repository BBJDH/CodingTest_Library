/*
 *1475 - 방 번호
 *
 *입력받은 숫자를 카운팅하여 최대 세트수를 계산한다.
 *
 *6과 9를 제외한 숫자들은 입력받은 최대 수 만큼 카드세트를 구매해야 한다
 *
 *하지만 6과 9는 같은 수로 취급되므로 한 세트에 두장이 들어있는 셈이다
 *
 *6과 9를 제외한 최대 카운트를 기록해두고 6과 9를 구매해야 하는 최대 가드세트수와
 *
 *비교하여 최대값을 산출한다.
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