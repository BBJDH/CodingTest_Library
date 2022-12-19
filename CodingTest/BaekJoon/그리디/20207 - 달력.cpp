/*
 *20207 - 달력
 *
 *입력받은 쌍을 시작 일정, 길이 순으로 정렬,
 *
 *이후 하나씩 2중 배열에 쌓아나감
 *
 *배열을 통해 붙일 깊이를 탐색해나간다
 *
 *붙이는동안 너비를 위한 시작과 끝지점,
 *깊이량을 업데이트 해 나간다.
 *
 *fill_n으로 코팅지를 붙일때 해당 높이를 maxDepth와 비교 업데이트
 *
 *처음 시작 날짜를 기록해두고, 끝 지점과 업데이트된 maxEnd를 비교 업데이트 한다.
 *
 *만약 다음 들어온 첫 날짜가 현재 maxEnd보다 2이상 크다면 이전의 maxEnd-start 와 maxDepth의 곱(넓이)을 결과에 합산
 *
 *다음 아스테이지가 시작된다 (새로운 Start를 기록, 업데이트 시작)
 *
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Calendar[1001][366]{};

struct _int2
{
	int Start;
	int End;
};

bool operator>(_int2 const& Left, _int2 const& Right)
{
	if (Left.Start == Right.Start)
		return (Left.End - Left.Start) < (Right.End - Right.Start);
	return Left.Start > Right.Start;
}

bool operator<(_int2 const& Left, _int2 const& Right)
{
	if (Left.Start == Right.Start)
		return (Left.End - Left.Start) > (Right.End - Right.Start);
	return Left.Start < Right.Start;
}

vector<_int2>Schedules{};

int Fill_Calendar(_int2 const& Current)
{
	int Depth = 1;
	while (Calendar[Depth][Current.Start] == true)	Depth++;
	fill_n(&Calendar[Depth][Current.Start], Current.End - Current.Start + 1, true);

	return Depth;
}

int Solution()
{
	int result = 0;
	_int2 Width{ -1, -1 };
	int maxDepth{};
	for (auto const& elem : Schedules)
	{
		if (elem.Start > Width.End + 1)
		{
			//처음 시작은 -1*-1*0이므로 아무것도 합산되지 않음
			result += (Width.End - Width.Start + 1) * maxDepth;

			//너비 초기화
			Width.Start = elem.Start;
			Width.End = elem.End;

			//이전 코팅지의 깊이를 초기화
			maxDepth = 1;
		}
		Width.End = max(Width.End, elem.End);
		maxDepth = max(maxDepth, Fill_Calendar(elem));
	}

	result += (Width.End - Width.Start + 1) * maxDepth;
	return result;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		_int2 inputSchedule{};
		cin >> inputSchedule.Start >> inputSchedule.End;
		Schedules.emplace_back(inputSchedule);
	}
	sort(Schedules.begin(), Schedules.end());

	cout << Solution();

	return 0;
}