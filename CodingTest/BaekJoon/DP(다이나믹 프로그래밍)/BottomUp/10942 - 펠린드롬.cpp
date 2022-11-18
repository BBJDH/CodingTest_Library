/*
 * 10942 - �縰���?
 *
 * ���Ʈ������ 1~2000 * 1~2000 �� �����鼭 �縰����� �˻��� ����� �����Ѵٸ� �ð��ʰ��� �߻��Ѵ�
 *
 *�縰��� ��Ģ�� �̿��� DP�� ������
 *
 *�������  1, 2, 1, 3, 1, 2, 1 ����
 *
 *������ 0 ��, �ڱ��ڽ� ���� 1, 2, 3, ... �� �縰��� ���̴�
 *������ 1 �̹����� 1, 2 �ǰ��� �� ���� ���ƾ� �縰����� �����Ѵ�
 *������ 2 ���ʹ� ��Ģ�� �����ȴ� start+1 end-1�� �縰����̸鼭 start�� end�� ���ٸ� �縰����̴�
 *���� �ϳ��� �����̶� �������� ���Ѵٸ� �縰����� �ƴϴ�
 *
 *�޸������̼��� �� �� �ְ� �� ������ ������ �����ͺ��� ������ ��� DP�� �����Ѵ�
 *(ū�ͺ��� �Ѵٸ� ����DP�� ������ �� ����)
 *
 *���� ������ ������ ���� ��¸����ָ� �ȴ�.
 *
 *
 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> Sequence{};
int DP[2001][2001]{};

void MakeDP()
{
	for (int gap = 0; gap < Sequence.size(); gap++)
	{
		for (int start = 0; start + gap < Sequence.size(); start++)
		{
			int end = start + gap;
			if (gap == 0)
				DP[start][end] = 1;
			else if (gap == 1 and Sequence[start] == Sequence[end])
				DP[start][end] = 1;
			else
			{
				if (DP[start + 1][end - 1] == 1 and Sequence[start] == Sequence[end])
					DP[start][end] = 1;
				else
					DP[start][end] = 0;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputCount = 0;

	cin >> inputCount;

	while (inputCount--)
	{
		int inputNum = 0;
		cin >> inputNum;
		Sequence.emplace_back(inputNum);

	}
	MakeDP();

	cin >> inputCount;
	while (inputCount--)
	{
		int start = 0;
		int end = 0;
		cin >> start >> end;

		cout << DP[start - 1][end - 1] << "\n";
	}



	return 0;
}