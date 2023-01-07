/*
 *14003 - 가장 긴 증가하는 부분 수열 3
 *
 *최장 길이를 구하는데 사용할 배열을 하나 생성하여 첫 수부터 집어넣고 이것과 비교를 통해 최장길이를 구해나간다
 *방법은 다음과 같다
 *
 *생성된 배열(이하 LIS_Sequence라 한다)에 첫 수를 입력한다.
 *이후 다음수(이하 Num)와 LIS_Sequence의 맨 뒷 숫자와 비교하여 LIS_Sequence의 끝수보다 크다면 뒤에 다음수를 붙인다
 *(LIS_Sequence.push_back)
 *
 *만약, inputNum이 LIS_Sequence의 끝수보다 크지 않다면 LIS_Sequence의 수들 중에 inputNum보다 큰 첫번째 수와 교체한다.
 *(N으로 탐색하면 전체 로직의 시간복잡도가 커지므로 logn인 이분탐색을 활용한다.
 *lower_bound(...,inputNum)를 사용해 검색에 실패했다면 inputNum이 제일 크고 성공했다면 그 수와 교체한다.)
 *
 *풀어 나가는 예시를 보자
 *
 * 1 3 2 4 0
 * 에서 최장 길이를 구한다면,
 *
 * 1을 먼저 넣고,
 * 1
 * 1 3 ->3은 1보다 크므로 뒤에 추가한다
 * 1 2 ->다음수가 2이므로 2보다 큰 첫 수를 lower_bound로 검색하여 교체한다.
 * 1 2 4 ->4는 2보다 크므로 뒤에 추가
 * 0 2 4 -> 0보다 큰 첫 수인1과 교체
 *
 * 즉 1 3 2 4 0 의 최장길이는 3이다(0 2 4)
 *
 *물론 0 2 4 가 실제 최장길이 수열은 아니다.
 *이 문제는 최장길이만 구하면 되므로 이대로 출력하지만, 정해가 되는 수열을 구하고 싶다면 4번 혹은 5번 풀이를 확인하면 된다.
 *
 */
 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> LIS_Sequence{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputNum{};

		cin >> inputNum;

		if (i == 0)
		{
			LIS_Sequence.push_back(inputNum);
			continue;
		}

		auto iter = lower_bound(LIS_Sequence.begin(), LIS_Sequence.end(), inputNum);

		if (iter != LIS_Sequence.end())
		{
			*iter = inputNum;
		}
		else
		{
			LIS_Sequence.push_back(inputNum);
		}
	}
	cout << LIS_Sequence.size();

	return 0;
}