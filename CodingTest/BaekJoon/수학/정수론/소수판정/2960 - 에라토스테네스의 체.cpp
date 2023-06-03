/*
 *2960 - 에라토스테네스의 체
 *
 *입력받는 MaxNum의 크기는 1000까지 이므로
 *
 *1000 까지 제거유무를 기록할 IsNumErased 고정배열을 미리 만들어 둔다.
 *
 *
 *이후 에라토스테네스의 채를 진행, 출력할 K(TargetCount)번째 지워지는 수를 찾기 위해
 *수를 지울 때 마다 K(TargetCount)를 감소시킨다.
 *
 *감소시킨 TargetCount가 0에 도달한다면 이때 해당 수를 출력 후 종료
 *
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	bool IsNumErased[1001]{};
	fill_n(IsNumErased, 1001, true);

	int MaxNum = 0, TargetCount = 0;
	cin >> MaxNum >> TargetCount;

	for (int Num = 2; Num < 1001; Num++)
	{
		if (IsNumErased[Num] == true)
		{
			for (int mul = 1; Num * mul <= MaxNum; mul++)
			{
				if (IsNumErased[Num * mul] == true)
				{
					TargetCount--;
					IsNumErased[Num * mul] = false;
				}
				if (TargetCount == 0)
				{
					cout << Num * mul;
					return 0;
				}
			}

		}
	}

	return 0;
}