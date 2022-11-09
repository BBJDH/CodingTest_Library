/*
12015 - 가장 긴 증가하는 부분 수열 2

가상의 최대 수열을 생성하고 이를 이분탐색으로 교체하는 방식으로 풀어나간다
가상의 최대수열은 존재할 수 있는 가장 큰 수인 1,000,000을 하나 추가하여 시작한다

가상의 가장 큰수열을 가정하였으므로 수열의 맨 뒤에원소(처음은 1,000,000)와 입력된 수열의 첫 원소를 비교한다
입력된 수열의 원소가 작다면, 최대수열에서 lower_bound(begin,end,수열의 원소)로 해당 최대수열의 원소를 교체해준다

예시를 보면

최초 설정)
입력 받은 수열 : 10 20 1 2 3 30 40 5 6
가상의 최대 수열 : 1000000

10이 더 작으므로 lowerbound, 1000000 을 10으로 교체
=>
입력 받은 수열 : [10] 20 1 2 3 30 40 5 6
가상의 최대 수열 : 10

20이 더 크므로 수열 증가
=>
입력 받은 수열 : 10 [20] 1 2 3 30 40 5 6
가상의 최대 수열 : 10 20

1이 20보다 작으므로 lower_bound, 1보다 큰 첫 원소인 10과 교체
=>
입력 받은 수열 : 10 20 [1] 2 3 30 40 5 6
가상의 최대 수열 : 1 20

2이 20보다 작으므로 lower_bound, 2보다 큰 첫 원소인 20과 교체
=>
입력 받은 수열 : 10 20 1 [2] 3 30 40 5 6
가상의 최대 수열 : 1 [2]

3이 2보다 크므로 수열 증가
=>
입력 받은 수열 : 10 20 1 2 [3] 30 40 5 6
가상의 최대 수열 : 1 2 [3]

30이 3보다 크므로 수열 증가
=>
입력 받은 수열 : 10 20 1 2 3 [30] 40 5 6
가상의 최대 수열 : 1 2 3 [30]

40이 30보다 크므로 수열 증가
=>
입력 받은 수열 : 10 20 1 2 3 30 [40] 5 6
가상의 최대 수열 : 1 2 3 30 [40]

5가 40보다 작으므로 교체
=>
입력 받은 수열 : 10 20 1 2 3 30 40 [5] 6
가상의 최대 수열 : 1 2 3 [5] 40

6가 40보다 작으므로 교체
=>
입력 받은 수열 : 10 20 1 2 3 30 40 5 [6]
가상의 최대 수열 : 1 2 3 5 [6]

입력 받은 수열의 끝에 도달하면 가상의 최대수열의 사이즈를 반환 : 5



예시를 확인해보면,
입력 받은 수열 : 10 20 1 2 3 30 40 [5] 6
가상의 최대 수열 : 1 2 3 [5] 40

가상의 최대 수열은 사이즈 갯수만 일치할 뿐, 실제 최대수열(1 2 3 30 40)과 일치하지 않는다는것을 알 수 있다
단순히 갯수만의 카운팅을 목적으로 만들어져있다.
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Sequence{};
vector<int> MaxSequence{};
int InputSize = 0;

void MakeMaxSequence()
{
	MaxSequence.push_back(1000000);

	for (auto const& Elem : Sequence)
		if (Elem > MaxSequence[MaxSequence.size() - 1])
			MaxSequence.emplace_back(Elem);
		else
		{
			int Index = static_cast<int>(lower_bound(MaxSequence.begin(), MaxSequence.end(), Elem) - MaxSequence.begin());
			MaxSequence[Index] = Elem;
		}
	cout << MaxSequence.size();
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> InputSize;

	while (InputSize--)
	{
		int InputNum = 0;

		cin >> InputNum;
		Sequence.emplace_back(InputNum);
	}
	MakeMaxSequence();
	return 0;
}