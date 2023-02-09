/*
 * 1946 - ���� ���
 *
 *������ ���� ����� �ΰ��� ���̶� ���� Ǯ�� �����ߴ�.
 *
 *���� ù��° Score�� �������� ������ ��,
 *
 *���� ����� ���ؼ� ���� ����� �����Ѵ�
 *
 *������ �������� ����� �����ϸ�
 * ���� ����
 *  1    4  - ������� ���� �������� 4  (�� ģ���� �̹� ��������� ���ϳ����Ƿ� ä��)
 *  2    3  - 4��� ���� 3������ ���� ��������� 3���� �ٲٰ� ä��
 *  3    2  - ���������� ���� ���� ����� 2������ ������Ʈ
 *  4    1  - ���� ���������� ������ ä��
 *  5    5  - ���� ���������� �и��� �ٸ� �ο��� ��������� �и��Ƿ� ��ä��
 *
 *���� ���� ����ȴ�.
 *
 *�� ������ �������� �������� �����ϸ� ó�� ������� �������������
 *
 *��������� �ְ� ��������� ������Ʈ�Ͽ� ��������� �� ���� ����� �������� üũ�ϱ⸸ �ϸ� �ȴ�.
 *
 *�ο��� 10���̹Ƿ� ���� �ʱ�ȭ�ؾ��� ���� ����� 10��1���� ��������
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