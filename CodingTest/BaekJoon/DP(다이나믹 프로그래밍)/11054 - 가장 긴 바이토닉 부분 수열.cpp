/*
 *11054 - ���� �� ������� �κ� ����
 *
 *�Է� ���� �迭�� �� �ڸ����� �ִ���϶��� ������ ������� �κ� ������ ũ�⸦ ���غ���
 *
 *10
 *index 0 1 2 3 4 5 6 7 8 9
 *		1 5 2 1 4 3 4 5 2 1
 *
 *index 0 -> [1]
 *index 1 -> [1 5] [4 3 2 1]
 *index 2 -> [1 2] [1]
 *index 3 -> [1]
 *index 4 -> [1 2 4][3 2 1]
 *index 5 -> [1 2 3][2 1]
 *index 6 -> [1 2 3 4] [2 1]
 *index 7 -> [1 2 3 4 5][2 1]
 *index 8 -> [1 2][1]
 *index 9 -> [1]
 *
 *���� ��Ģ�� ���ٸ� �� ���� �ε������� �ڽ��� ���ڸ� �ִ� ���� �ϰ� �ڽź��� ���� ������ �� ������ �ʿ����� �� �� �ִ�.
 *�� �ش� �ε��� ��������
 *[�������� ����] + [�������� ����] - �ش� �ε��� �� 1��(������� �ߺ��Ǳ� ����) ���� ��� �����ϴ�
 *���� ���� ��� [1 2 3 4 5][5 2 1] -1(5�� ��ħ) �� ����� �� �ִ�
 *
 *���� ������ ���ؼ� �ش� �ε����� ���� �������� ������ ũ��� �������� �������� ������ ũ�⸦ ���� ����Ѵ�.
 *
 *�������
 *�������� �ִ� ũ�⸦ ����Ѵٸ�
 *1 2 3 2 1 �� ���
 *1 2 3 3 3 ���� �����Ҽ� ������ �� ������ ������� ������ ���ؾ� �ϹǷ� ���� ū���� ���������� ���� �� �� ����.
 *�� ������� ���� �ջ������ �ִ� ũ�⸦ ����Ѵٸ�
 *1 2 3 2 1 �� ũ��� ����ؾ� �Ѵ�.
 *
 *�Ѱ��� for���ȿ��� ���������� ���������� ����ϰ� �;�����
 *�ܼ� ���ڸ� ī�����ϴ°��� �ƴ� ������� Ŀ���ų� �۾����� �ϹǷ�
 *DP�� �̿��� �� ���̵忡�� �ϳ��� ũ�⸦ ������Ʈ �ؿ;� �Ѵ�
 *�� ���� ������ ���������� ���������� ���� ����ϰ�
 *�� ���� ���߿� �ִ� -1�� ����ϸ� �ȴ�.
 *
 */



#include <iostream>
#include <vector>

using  namespace  std;

int Size = 0;
vector<int> Sequence{};

int DPBigger[1001]{};
int DPSmaller[1001]{};

void MakeDP()
{
	for (int right = 0; right < Size; right++)
	{
		DPBigger[right] = 1;
		for (int left = 0; left < right; left++)
		{
			if (Sequence[right] > Sequence[left])
				DPBigger[right] = max(DPBigger[right], DPBigger[left] + 1);
		}
	}

	for (int left = Size - 1; left >= 0; left--)
	{
		DPSmaller[left] = 1;
		for (int right = Size - 1; right > left; right--)
		{
			if (Sequence[left] > Sequence[right] and DPSmaller[left] < DPSmaller[right] + 1)
				DPSmaller[left] = max(DPSmaller[left], DPSmaller[right] + 1);
		}
	}

	int maxCount = 0;
	for (int i = 0; i < Size; i++)
	{
		maxCount = max(maxCount, DPSmaller[i] + DPBigger[i]);
	}

	cout << maxCount - 1;
}



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	for (int i = 0; i < Size; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		Sequence.emplace_back(inputNum);
	}

	MakeDP();

	return 0;
}