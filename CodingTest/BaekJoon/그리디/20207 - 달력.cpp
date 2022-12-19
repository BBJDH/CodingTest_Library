/*
 *20207 - �޷�
 *
 *�Է¹��� ���� ���� ����, ���� ������ ����,
 *
 *���� �ϳ��� 2�� �迭�� �׾Ƴ���
 *
 *�迭�� ���� ���� ���̸� Ž���س�����
 *
 *���̴µ��� �ʺ� ���� ���۰� ������,
 *���̷��� ������Ʈ �� ������.
 *
 *fill_n���� �������� ���϶� �ش� ���̸� maxDepth�� �� ������Ʈ
 *
 *ó�� ���� ��¥�� ����صΰ�, �� ������ ������Ʈ�� maxEnd�� �� ������Ʈ �Ѵ�.
 *
 *���� ���� ���� ù ��¥�� ���� maxEnd���� 2�̻� ũ�ٸ� ������ maxEnd-start �� maxDepth�� ��(����)�� ����� �ջ�
 *
 *���� �ƽ��������� ���۵ȴ� (���ο� Start�� ���, ������Ʈ ����)
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
			//ó�� ������ -1*-1*0�̹Ƿ� �ƹ��͵� �ջ���� ����
			result += (Width.End - Width.Start + 1) * maxDepth;

			//�ʺ� �ʱ�ȭ
			Width.Start = elem.Start;
			Width.End = elem.End;

			//���� �������� ���̸� �ʱ�ȭ
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