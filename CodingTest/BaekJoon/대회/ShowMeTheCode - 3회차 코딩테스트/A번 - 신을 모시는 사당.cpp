/*
 *A번 - 신을 모시는 사당
 *
 *1의 연속과 2의 연속을 양과 음의 정수로 바꾸어 배열에 입력한다
 *
 *입력된 배열에 대하여 최대 부분합과 최소 부분합을 만들어
 *
 *이 둘의 절대값중 최대값을 출력하면된다.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int>Nums{};
int DP_Min[100000]{};
int DP_Max[100000]{};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	int PrevNum = 0;
	int Sum = 0;

	for (int i = 0; i < N; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		if (PrevNum != InputNum)
		{
			if (PrevNum == 0)
			{
				PrevNum = InputNum;
				Sum++;
				continue;
			}
			if (PrevNum == 2)
				Sum *= -1;
			Nums.push_back(Sum);
			PrevNum = InputNum;
			Sum = 0;
		}
		Sum++;
	}
	if (PrevNum == 2)
		Sum *= -1;
	Nums.push_back(Sum);
	//음수 양수로 치환 완료, 최소 최대 부분수열 구하기 시작

	DP_Max[0] = Nums[0];
	DP_Min[0] = Nums[0];
	int MaxNum = DP_Max[0];
	int MinNum = DP_Min[0];
	for (int i = 1; i < Nums.size(); i++)
	{
		DP_Max[i] = max(DP_Max[i - 1] + Nums[i], Nums[i]);
		DP_Min[i] = min(DP_Min[i - 1] + Nums[i], Nums[i]);
		MaxNum = max(MaxNum, DP_Max[i]);
		MinNum = min(MinNum, DP_Min[i]);
	}
	cout << max(abs(MinNum), MaxNum);
	return 0;
}



