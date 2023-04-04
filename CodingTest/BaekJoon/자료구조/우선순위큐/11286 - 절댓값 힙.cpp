/*
 *11286 - ���� ��
 *
 *
 *�䱸���׿� �°� �켱���� ť�� ������ ���α׷��� �ۼ��ߴ�.
 *
 *ũ�⸦ ���밪�� �켱���� ���ϰ� ������ ���밪�̶�� ������ ũ�⸦ ���� �� �ְ�
 *
 *���� �ΰ��� ������ �ڷ����� ����ü�� �ۼ��Ѵ�.
 *�̸� ���� ������ �����ε��� ������ �䱸���װ� �����ϰ� �ۼ��ߴ�.
 *
 *���� ������������ �켱���� ť�� �ֵ��� �����
 *
 *�䱸���״�� Push�� Print �� Pop������ ���ָ� ���α׷��� �ϼ��ȴ�.
 *
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace	std;

struct _int2
{
	int Num;
	int AbsNum;
};

bool operator>(_int2 const& Left, _int2 const& Right)
{
	if (Left.AbsNum == Right.AbsNum)
	{
		return Left.Num > Right.Num;
	}

	return Left.AbsNum > Right.AbsNum;
}
bool operator<(_int2 const& Left, _int2 const& Right)
{
	if (Left.AbsNum == Right.AbsNum)
	{
		return Left.Num < Right.Num;
	}

	return Left.AbsNum < Right.AbsNum;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	priority_queue<_int2, vector<_int2>, greater<>> HeapOfMinAbs{};

	int CountOfInput = 0;
	cin >> CountOfInput;
	while (CountOfInput--)
	{
		int InputNum = 0;
		cin >> InputNum;
		if (InputNum == 0)
		{
			if (HeapOfMinAbs.empty())
			{
				cout << 0 << "\n";
				continue;
			}
			cout << HeapOfMinAbs.top().Num << "\n";
			HeapOfMinAbs.pop();
			continue;
		}

		HeapOfMinAbs.push({ InputNum ,abs(InputNum) });
	}

	return 0;
}