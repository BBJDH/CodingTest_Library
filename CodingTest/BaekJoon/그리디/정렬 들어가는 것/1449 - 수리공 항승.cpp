/*
 *1449 - 수리공 항승
 *
 *문제에서 좌우 0.5센치만큼의 여장을 줘야한다는 뜻은
 *누수되는곳마다 1미터씩 테이프를 사용한다는 의미이다.
 *즉 테이프의 길이가 2이고 망가진 곳 위치가 1, 2라면
 *
 *1과 2를 2미터짜리 테이프 한장으로 둘다 막을 수 있다.
 *(0.5~2.5로 모두 커버!)
 *
 *따라서 먼저, 각 개소를 오름차순으로 정렬하여 순차적으로 테이프를 이어갈 수 있게 만든다.
 *
 *이후 첫 개소를 기준으로 Left와 Right를 지정한다.
 *이때 테이프의 왼쪽은 Left, 오른쪽끝은 Right라고 해보자
 *Right를 점점 오른쪽으로 늘여가며 테이프의 최대길이 까지 연장해본다.
 *이후 테이프의 오른쪽 즉 Right가 닿지 않는 곳이 나타난다면 여기가 다시 Left로 재지정된다.
 *
 *이후 다시Right를 Left에서 오른쪽으로 늘여나가며 수리를 시작한다.
 *Right가 입력받은 모든 개소를 순회했다면 모두 수리를 마쳤으므로 반복문을 종료한다.
 *
 *반복문 종료시점에 마지막 테이프가 봉해지지 않았으므로 카운팅된 Right+1을 출력한다.
 *
 */

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<int> PlaceToSolve{};
	int CountOfPlace = 0, LengthOfTape = 0;
	int Result = 0;

	cin >> CountOfPlace >> LengthOfTape;

	while (CountOfPlace--)
	{
		int PlaceNum = 0;
		cin >> PlaceNum;
		PlaceToSolve.push_back(PlaceNum);
	}

	sort(PlaceToSolve.begin(), PlaceToSolve.end());

	int Left = 0;
	int Right = 0;
	while (Right < PlaceToSolve.size())
	{
		int const Length = PlaceToSolve[Right] - PlaceToSolve[Left];
		if (Length >= LengthOfTape)
		{
			Left = Right;
			Result++;
		}
		Right++;
	}
	cout << Result + 1;
	return 0;
}