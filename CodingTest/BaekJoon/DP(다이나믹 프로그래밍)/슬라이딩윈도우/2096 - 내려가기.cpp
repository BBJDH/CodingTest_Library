/*
 *2096 - 내려가기
 *
 *메모리 제한이 4MB로 용량제한이 적다 입력하면서 처리해주는게 힌트
 *
 *N에 10만으로 브루트포스나 백트래킹으로는 시간초과가 발생한다
 *반복문 10만번을 돌몀ㄴ서 3번씩 입력받아 DP배열을 최적의 길로 업데이트 해보자
 *
 * 4
 * 1 1 0
 * 2 0 1
 * 0 2 1
 * 1 0 1
 *
 *먼저 최소기준으로 해본다
 *1 1 0  -DPMin 그대로 입력 1 1 0
 *
 *2 0 1  - DPMin -> 3 0 1 (즉 기존 DP의 내려올수 있는 위의 원소들중 최솟값+ 현재 입력받은 수)
 *
 *[3 0 1]
 *0 2 1 - DPMin -> 0 2 1
 *
 *[0 2 1]
 *1 0 1 -> 1 0 2
 *이 셋중 가장 작은 길은 0으로 최소 점수는 0이다
 *
 *반대로 최대를 기록하면
 *
 *[1 1 0]
 *2 0 1 -> DP 3 1 2
 *
 *[3 1 2]
 *0 2 1 -> DP 3 5 3
 *
 *[3 5 3]
 *1 0 1 ->DP 6 5 6
 *
 *으로 최대 점수는 6이다
 *
 *=> 6 0
 */

#include <iostream>
#include <cstring>

using namespace std;

int DPMin[3]{};
int DPMax[3]{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputCount = 0;

	cin >> inputCount;

	int inputNum[3]{};
	for (int i = 0; i < 3; i++)
	{
		cin >> inputNum[i];
	}
	memcpy(DPMin, inputNum, sizeof(inputNum));
	memcpy(DPMax, inputNum, sizeof(inputNum));
	for (int count = 1; count < inputCount; count++)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> inputNum[i];
		}
		int PrevMin[3]{};
		int PrevMax[3]{};
		memcpy(PrevMin, DPMin, sizeof(inputNum));
		memcpy(PrevMax, DPMax, sizeof(inputNum));

		DPMin[0] = min(PrevMin[0], PrevMin[1]) + inputNum[0];
		DPMax[0] = max(PrevMax[0], PrevMax[1]) + inputNum[0];

		DPMin[1] = min(min(PrevMin[0], PrevMin[1]), PrevMin[2]) + inputNum[1];
		DPMax[1] = max(max(PrevMax[0], PrevMax[1]), PrevMax[2]) + inputNum[1];

		DPMin[2] = min(PrevMin[1], PrevMin[2]) + inputNum[2];
		DPMax[2] = max(PrevMax[1], PrevMax[2]) + inputNum[2];
	}

	int resultMin = min(min(DPMin[0], DPMin[1]), DPMin[2]);
	int resultMax = max(max(DPMax[0], DPMax[1]), DPMax[2]);

	cout << resultMax << " " << resultMin;
	return 0;
}
