/*
 *8983 - 사냥꾼
 *
 *사로 기준으로 사격 가능한 동물을 찾는것이 아니라
 *반대로 동물 입장에서 내가 피격 가능한가를 판정한다
 *내가 있는 y의 좌표만큼을 빼고나면 남은 길이 만큼을 좌 우로 사로를 이분 탐색하여
 *사로가 존재한다면 해당 동물은 피격가능하다.
 *
 *예를들어
 *해당 좌표가 10,3 이고 각 사로의 사정거리를 4 라고 한다면,
 *
 * 4에서 3을 빼면 좌우로 1만큼 탐색 가능해진다 10지점에서 플러스 마이너스 1만큼 사로를 탐색한다
 * 9~ 11 사이에 사로가 없다면 해당 동물은 살아남는다!
 *
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct _int2
{
	int X;
	int Y;
};
int M = 0, AnimalNum = 0, Length = 0;
vector<int> Shooters{};
vector<_int2> Animals{};


bool IsInRange(_int2 const& Pos)
{
	int const searchLength = Length - Pos.Y;

	//0까지는 찾을 수 있다 
	if (searchLength < 0)
		return false;

	auto iter_start = lower_bound(Shooters.begin(), Shooters.end(), Pos.X - searchLength);

	if (iter_start == Shooters.end())
		return false;

	if (*iter_start > Pos.X + searchLength)
		return false;

	return true;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> AnimalNum >> Length;

	for (int i = 0; i < M; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		Shooters.emplace_back(inputNum);
	}
	sort(Shooters.begin(), Shooters.end());
	int count = 0;

	for (int i = 0; i < AnimalNum; i++)
	{
		_int2 inputPos{};

		cin >> inputPos.X >> inputPos.Y;
		if (IsInRange(inputPos))
			count++;
	}

	cout << count;

	return 0;
}