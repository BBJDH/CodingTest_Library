/*
 *2108 - 통계학
 *
 *산술평균 - 입력받은 수를 누적시키고 이것을 N으로 나누어 출력한다. 다만 나눌때 float으로 계산하면 오차가 발생하여
 *			정답처리가 되지 않으므로 double로 출력한다.
 *중앙값 - N은 홀수이므로 입력숫자배열을 정렬 후 N/2의 인덱스로 접근하여 출력한다.
 *최빈값 - 입력받는 수의 범위가 -4000 ~ 4000 이므로 0~ 8000를인덱스를 가지는 숫자 배열로 매핑한다.
 *		이후 해당 번호가 들어오면 +4000으로 카운트를 올려주고 최대 카운트도 업데이트해둔다
 *		입력을 마친 후 최대 카운트와 일치하는 배열을 O(n)으로 탐색한다.
 *		만약 이미 찾았는데 또 나온다면 그 수를 출력(-4000에 해당하는 0번부터 탐색하므로 두번째로 작은 수다.)
 *		반복문을 무사히 탈출했다면 최빈값은 하나이므로 그대로 출력해준다.
 *범위 - 정렬된 배열의 맨 앞과 맨 뒤의 차에대한 절대값을 출력했다.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int NumCount[8001]{};
int MaxCount = 0;
int GetMaxCountNum()
{
	bool IsFound = false;
	int Result = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (NumCount[i] == MaxCount)
		{
			if (IsFound == true)
				return i - 4000;
			IsFound = true;
			Result = i - 4000;
		}
	}
	return Result;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> Nums{};
	int N = 0;
	cin >> N;
	double Sum = 0;

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		NumCount[inputNum + 4000]++;
		MaxCount = max(MaxCount, NumCount[inputNum + 4000]);
		Sum += static_cast<double>(inputNum);
		Nums.push_back(inputNum);
	}

	sort(Nums.begin(), Nums.end());

	printf("%d\n", static_cast<int>(round(Sum / N)));	//산술평균
	printf("%d\n", Nums[N / 2]);						//중앙값
	printf("%d\n", GetMaxCountNum());					//***최빈값***
	printf("%d\n", abs(Nums[N - 1] - Nums[0]));			//범위

	return 0;

}