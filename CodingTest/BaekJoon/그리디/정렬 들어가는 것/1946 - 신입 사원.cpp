/*
 * 1946 - 신입 사원
 *
 *다행이 비교할 등수가 두가지 뿐이라 쉽게 풀이 가능했다.
 *
 *먼저 첫번째 Score를 기준으로 정렬한 후,
 *
 *다음 등수에 대해서 높은 등수를 정렬한다
 *
 *서류를 기준으로 등수로 정렬하면
 * 서류 면접
 *  1    4  - 면접등수 제일 높은것은 4  (이 친구는 이미 서류등수가 제일높으므로 채용)
 *  2    3  - 4등보다 낮은 3등으로 제일 높은등수를 3으로 바꾸고 채용
 *  3    2  - 마찬가지로 제일 높은 등수는 2등으로 업데이트
 *  4    1  - 위와 마찬가지로 수행후 채용
 *  5    5  - 현재 서류에서도 밀리고 다른 인원의 면접등수도 밀리므로 미채용
 *
 *위와 같이 진행된다.
 *
 *즉 서류를 기준으로 오름차순 정렬하면 처음 사람부터 다음사람까지는
 *
 *현재까지의 최고 면접등수를 업데이트하여 다음사람이 더 높은 등수를 가졌는지 체크하기만 하면 된다.
 *
 *인원는 10만이므로 최초 초기화해야할 면접 등수는 10만1임을 유의하자
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct _int2
{
	int FirstScore;
	int SecondScore;
};

bool operator>(_int2 const& Left, _int2 const& Right)
{
	return Left.FirstScore > Right.FirstScore;
}

bool operator<(_int2 const& Left, _int2 const& Right)
{
	return Left.FirstScore < Right.FirstScore;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		int Size = 0;
		cin >> Size;
		int MinSecondScore = 100001;
		int result = 0;
		vector<_int2> ScoreBoard{};
		for (int i = 0; i < Size; i++)
		{
			_int2 inputScore{};
			cin >> inputScore.FirstScore >> inputScore.SecondScore;
			ScoreBoard.push_back(inputScore);
		}

		sort(ScoreBoard.begin(), ScoreBoard.end());

		for (_int2 const& elem : ScoreBoard)
		{
			if (elem.SecondScore < MinSecondScore)
			{
				MinSecondScore = elem.SecondScore;
				result++;
			}
		}
		cout << result << "\n";
	}

	return 0;
}