/*
 *
 *2953 - 나는 요리사다
 *
 *정렬을 통해 풀었다.
 *
 *요리사의 번호와 총합 점수를 묶어서 벡터에 저장 후
 *
 *점수에 따라 정렬되도록 연산자를 오버로딩 했다
 *이후 정렬하여 0번 인덱스의 요리사 번호와 점수를 출력!
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct _int2
{
	int CookNum;
	int Score;
};

bool operator >(_int2 const& Left, _int2 const& Right)
{
	return Left.Score > Right.Score;
}

bool operator <(_int2 const& Left, _int2 const& Right)
{
	return Left.Score < Right.Score;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<_int2> Score{};

	for (int cook = 0; cook < 5; cook++)
	{
		int TotalScore = 0;
		for (int i = 0; i < 4; i++)
		{
			int Input = 0;
			cin >> Input;
			TotalScore += Input;
		}
		Score.push_back({ cook + 1,TotalScore });
	}

	sort(Score.begin(), Score.end(), greater<>());

	cout << Score[0].CookNum << "\n" << Score[0].Score;

	return 0;
}