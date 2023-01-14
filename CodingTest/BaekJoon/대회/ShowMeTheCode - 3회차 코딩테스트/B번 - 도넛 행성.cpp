
/*
 *B번 - 도넛 행성
 *
 *단순 그래프로 탐색을 진행하되,
 *문제의 요구사항에 따라 맵을 넘어가는 경우 0으로 돌아오고
 *음수가 되는 경우 Size-1이 되는 경우를 처리해준다.
 *
 *빈 공간을 입력받을때 해당 좌료를 저장해 두었다가
 *BFS 탐색을 진행하며 해당 구역이 새로운 구역이라면 카운트하여 출력한다.
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



