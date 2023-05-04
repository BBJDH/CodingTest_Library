/*
 *10819 - ���̸� �ִ��
 *
 *���� ������ 8���� �̹Ƿ� 8!��ŭ ��� ����� ���� �õ��غ� �� �ִ�.
 *
 *������ �ߺ��Ǵ� ���� ������ �����Ƿ� �湮ó���� ����� bool �迭�� ����Ѵ�.
 *
 *��� ���� ���ؼ� �迭�� ���� �õ��� �ϰ� �湮ó���� ���� ������ ���Ե� ���� ���� �ʴ´�.
 *
 *��� �����Ͽ� �迭ũ�Ⱑ ���� ũ�⸸ŭ �����Ѵٸ� |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| ����Ѵ�.
 *
 *���� ���Ȱ��� ������ �ִ밪�̶� ���Ͽ� ������Ʈ �� �Լ��� ����ȴ�.
 *
 *���� ������ ��Ʈ��ŷ���� ����, ��� ����� ���� �õ��Ѵ�.
 *
 */


#include <iostream>
#include <vector>

using namespace std;

int Size = 0;
int MaxDiff = 0;
bool visit[8]{};


void BackTracking(vector<int> const& InputNums, int Start, vector<int>& CurrentSequence)
{
	if (CurrentSequence.size() == Size)
	{
		int CurrentResult = 0;
		for (int i = 1; i < CurrentSequence.size(); i++)
		{
			CurrentResult += abs(CurrentSequence[i] - CurrentSequence[i - 1]);
		}
		MaxDiff = max(MaxDiff, CurrentResult);

		return;
	}

	for (int i = 0; i < Size; i++)
	{
		if (visit[i] == false)
		{
			CurrentSequence.push_back(InputNums[i]);
			visit[i] = true;
			BackTracking(InputNums, Start, CurrentSequence);
			CurrentSequence.pop_back();
			visit[i] = false;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	vector<int>InputNums{};

	cin >> Size;

	for (int i = 0; i < Size; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		InputNums.push_back(InputNum);
	}
	vector<int>Temp{};
	BackTracking(InputNums, 0, Temp);

	cout << MaxDiff;
	return 0;
}