/*
 *
 *2953 - ���� �丮���
 *
 *������ ���� Ǯ����.
 *
 *�丮���� ��ȣ�� ���� ������ ��� ���Ϳ� ���� ��
 *
 *������ ���� ���ĵǵ��� �����ڸ� �����ε� �ߴ�
 *���� �����Ͽ� 0�� �ε����� �丮�� ��ȣ�� ������ ���!
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