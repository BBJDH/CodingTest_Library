/*
 *14003 - 가장 긴 증가하는 부분 수열 4
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
 * 하지만 문제에서 요구하는것은 최장 길이 수열길이 뿐만아니라 해당 수열의 출력이다.
 * 위의 풀이방식으로는 0 2 4는 정해가 될 수 없다 (정해는 1 2 4 또는 1 3 4 이다)
 *
 * 때문에 다음과 같은 알고리즘을 추가한다.
 *
 *입력되는 inputNum에 대해 LIS_Sequence에 교체되거나 추가되는 인덱스를 기록해둔다
 *즉 예비 배열을 만들어 최장길이를 구하는과정에서 LIS_Sequence에 진입했던 인덱스를 기록해두었다가
 *최장길이를 구한 후 기록된 인덱스에 따라 최장길이 수열의 대상 숫자를 찾아내는 것이다.
 *
 *위의 수열로 예시를 들어본다면
 *
 * 1을 먼저 넣고,
 * 1									-> [1(0) 3 2 4 0] ()안은 표시되는 인덱스이다
 * 1 3 ->3은 1보다 크므로 뒤에 추가한다   -> [1(0) 3(1) 2 4 0]
 * 1 2 ->다음수가 2이므로 2보다 큰 첫 수를 lower_bound로 검색하여 교체한다.	-> [1(0) 3(1) 2(1) 4 0]
 * 1 2 4 ->4는 2보다 크므로 뒤에 추가	-> [1(0) 3(1) 2(1) 4(2) 0]
 * 0 2 4 -> 0보다 큰 첫 수인1과 교체	-> [1(0) 3(1) 2(1) 4(2) 0(0)]
 *
 * 이렇게 완료된 [1(0) 3(1) 2(1) 4(2) 0(0)] 에 대해 N의 비용을 들여 수열을 찾아낸다.
 * 수열의 크기는 위에서 3으로 정해졌으므로 수열은 크기가 3인 배열임을 미리 알 수 있다
 *
 * 따라서 [1(0) 3(1) 2(1) 4(2) 0(0)] 에서 뒤에서부터 탐색하여 2부터 차례대로 0까지 찾아나간다
 * -> 4 2 1 순으로 찾아진다(비용은 N)
 *
 * 이것을 거꾸로 출력하기 위해 stack을 사용했다.
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct _int2
{
	int Num;
	int Index;
};

vector<_int2> Nums{};
vector<int> LIS_Sequence{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		_int2 inputNum{};

		cin >> inputNum.Num;

		if (i == 0)
		{
			LIS_Sequence.push_back(inputNum.Num);
			inputNum.Index = static_cast<int>(LIS_Sequence.size()) - 1;
			Nums.push_back(inputNum);
			continue;
		}

		auto iter = lower_bound(LIS_Sequence.begin(), LIS_Sequence.end(), inputNum.Num);

		if (iter != LIS_Sequence.end())
		{
			*iter = inputNum.Num;
			inputNum.Index = static_cast<int>(iter - LIS_Sequence.begin());
		}
		else
		{
			LIS_Sequence.push_back(inputNum.Num);
			inputNum.Index = static_cast<int>(LIS_Sequence.size()) - 1;
		}
		Nums.push_back(inputNum);
	}
	//역으로 집어넣은것을 출력하기 위해 stack 사용
	int index = static_cast<int>(LIS_Sequence.size()) - 1;
	stack<int> result{};

	for (int i = static_cast<int>(Nums.size()) - 1; i >= 0; i--)
	{
		if (Nums[i].Index == index)
		{
			result.push(Nums[i].Num);
			index--;
		}
	}
	cout << result.size() << "\n";
	while (!result.empty())
	{
		cout << result.top() << " ";
		result.pop();
	}
	return 0;
}