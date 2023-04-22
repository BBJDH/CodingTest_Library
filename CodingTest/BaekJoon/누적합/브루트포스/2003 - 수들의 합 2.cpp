/*
 *
 *2003 - ������ �� 2
 *
 *�������� �̿��� Ǯ����.
 *
 *�Է¹޴� ���ÿ� �������� �迭�� �����Ѵ�.
 *
 *���� �� �迭�� ��� ������ ���Ͽ� TargetNum�� �Ǵ� �� ������ ���Ʈ������ Ž���Ѵ�.
 *
 *��ġ�� ResultCount�� ����ϰ� �����Ѵ�.
 *
 *
 */


#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<int> Sequence{};

	int SizeOfSequence = 0, TargetNum = 0;
	int Sum = 0, ResultCount = 0;
	cin >> SizeOfSequence >> TargetNum;
	Sequence.push_back(0);
	for (int i = 0; i < SizeOfSequence; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		Sum += InputNum;
		Sequence.push_back(Sum);
	}

	for (int i = 0; i < Sequence.size(); i++)
	{
		for (int j = i + 1; j < Sequence.size(); j++)
		{
			if ((Sequence[j] - Sequence[i]) == TargetNum)
			{
				ResultCount++;
			}
		}
	}

	cout << ResultCount;

	return 0;
}