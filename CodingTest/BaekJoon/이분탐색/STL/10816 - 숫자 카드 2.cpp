/*
 *10816 - 숫자 카드 2
 *
 *이분탐색을 통해 풀었다.
 *
 *처음 입력받은 N개 배열(InputSequence)을 정렬한다.
 *이후 다음 입력받은 수들을 이분탐색으로 InputSequence에서 탐색한다.
 *lower_bound()를 통해 첫 시작수를 찾는다
 *먼저 찾은 수가 일치하는지 확인하여 수를 찾지 못했다면 0을 출력시킨다
 *수를 찾았다면 upper_bound()를 통해 end 지점을 찾아 lower_bound()지점을 빼서 출력한다.
 *
 *(정렬, nlogn, 이분탐색 logn)
 *
 *
 *
 *
 *해결방법 2(접근 비용 1)
 *
 *배열로의 매핑을 이용해 시간을 단축시킬 수 있다.
 *
 *입력되는 수가 -천만 ~ +천만 이므로 2천만개의 배열을 생성하고 여기에 입력받은 수들을 매핑한다.
 *입력받은 수를 인덱스로 접근하여 ++ 처리한다. 이렇게 입력된 갯수를 배열에 저장하고
 *
 *다음 M개의 숫자들이 입력되면 배열의 값을 읽어서 출력하면 된다
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int>InputSequence{};
	vector<int>SearchNums{};
	int N = 0, M = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		InputSequence.push_back(inputNum);
	}
	sort(InputSequence.begin(), InputSequence.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		vector<int>::iterator Start = lower_bound(InputSequence.begin(), InputSequence.end(), inputNum);
		if (*Start != inputNum)
		{
			cout << 0 << " ";
			continue;
		}
		vector<int>::iterator End = upper_bound(InputSequence.begin(), InputSequence.end(), inputNum);
		cout << End - Start << " ";

	}

	return 0;
}