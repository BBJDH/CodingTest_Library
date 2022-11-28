/*
 *11054 - 가장 긴 바이토닉 부분 수열
 *
 *입력 받은 배열의 각 자리에서 최대수일때ㅑ 가능한 바이토닉 부분 수열의 크기를 구해보자
 *
 *10
 *index 0 1 2 3 4 5 6 7 8 9
 *		1 5 2 1 4 3 4 5 2 1
 *
 *index 0 -> [1]
 *index 1 -> [1 5] [4 3 2 1]
 *index 2 -> [1 2] [1]
 *index 3 -> [1]
 *index 4 -> [1 2 4][3 2 1]
 *index 5 -> [1 2 3][2 1]
 *index 6 -> [1 2 3 4] [2 1]
 *index 7 -> [1 2 3 4 5][2 1]
 *index 8 -> [1 2][1]
 *index 9 -> [1]
 *
 *위의 규칙을 본다면 각 지정 인덱스에서 자신의 숫자를 최대 수로 하고 자신보다 낮은 수만이 양 옆으로 필요함을 알 수 있다.
 *즉 해당 인덱스 기준으로
 *[오름차순 수열] + [내림차순 수열] - 해당 인덱스 수 1개(가운데에서 중복되기 때문) 으로 계산 가능하다
 *위를 예를 들면 [1 2 3 4 5][5 2 1] -1(5가 겹침) 로 계산할 수 있다
 *
 *따라서 수열에 대해서 해당 인덱스에 대해 오름차순 수열의 크기와 우측으로 내림차순 수열의 크기를 각각 기록한다.
 *
 *예를들어
 *오름차순 최대 크기를 기록한다면
 *1 2 3 2 1 의 경우
 *1 2 3 3 3 으로 생각할수 있지만 이 문제는 바이토닉 수열을 구해야 하므로 제일 큰수를 오른쪽으로 끌고 갈 수 없다.
 *즉 바이토닉 수열 합산용으로 최대 크기를 기록한다면
 *1 2 3 2 1 의 크기로 기록해야 한다.
 *
 *한개의 for문안에서 오름차순과 내림차순을 기록하고 싶었지만
 *단순 숫자를 카운팅하는것이 아닌 순서대로 커지거나 작아져야 하므로
 *DP를 이용해 각 사이드에서 하나씩 크기를 업데이트 해와야 한다
 *즉 이중 포문을 오름차순용 내림차순용 각각 기록하고
 *이 둘의 합중에 최대 -1를 출력하면 된다.
 *
 */



#include <iostream>
#include <vector>

using  namespace  std;

int Size = 0;
vector<int> Sequence{};

int DPBigger[1001]{};
int DPSmaller[1001]{};

void MakeDP()
{
	for (int right = 0; right < Size; right++)
	{
		DPBigger[right] = 1;
		for (int left = 0; left < right; left++)
		{
			if (Sequence[right] > Sequence[left])
				DPBigger[right] = max(DPBigger[right], DPBigger[left] + 1);
		}
	}

	for (int left = Size - 1; left >= 0; left--)
	{
		DPSmaller[left] = 1;
		for (int right = Size - 1; right > left; right--)
		{
			if (Sequence[left] > Sequence[right] and DPSmaller[left] < DPSmaller[right] + 1)
				DPSmaller[left] = max(DPSmaller[left], DPSmaller[right] + 1);
		}
	}

	int maxCount = 0;
	for (int i = 0; i < Size; i++)
	{
		maxCount = max(maxCount, DPSmaller[i] + DPBigger[i]);
	}

	cout << maxCount - 1;
}



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	for (int i = 0; i < Size; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		Sequence.emplace_back(inputNum);
	}

	MakeDP();

	return 0;
}