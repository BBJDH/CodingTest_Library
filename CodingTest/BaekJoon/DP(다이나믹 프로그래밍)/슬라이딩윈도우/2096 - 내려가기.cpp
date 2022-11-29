/*
 *2096 - ��������
 *
 *�޸� ������ 4MB�� �뷮������ ���� �Է��ϸ鼭 ó�����ִ°� ��Ʈ
 *
 *N�� 10������ ���Ʈ������ ��Ʈ��ŷ���δ� �ð��ʰ��� �߻��Ѵ�
 *�ݺ��� 10������ ���m���� 3���� �Է¹޾� DP�迭�� ������ ��� ������Ʈ �غ���
 *
 * 4
 * 1 1 0
 * 2 0 1
 * 0 2 1
 * 1 0 1
 *
 *���� �ּұ������� �غ���
 *1 1 0  -DPMin �״�� �Է� 1 1 0
 *
 *2 0 1  - DPMin -> 3 0 1 (�� ���� DP�� �����ü� �ִ� ���� ���ҵ��� �ּڰ�+ ���� �Է¹��� ��)
 *
 *[3 0 1]
 *0 2 1 - DPMin -> 0 2 1
 *
 *[0 2 1]
 *1 0 1 -> 1 0 2
 *�� ���� ���� ���� ���� 0���� �ּ� ������ 0�̴�
 *
 *�ݴ�� �ִ븦 ����ϸ�
 *
 *[1 1 0]
 *2 0 1 -> DP 3 1 2
 *
 *[3 1 2]
 *0 2 1 -> DP 3 5 3
 *
 *[3 5 3]
 *1 0 1 ->DP 6 5 6
 *
 *���� �ִ� ������ 6�̴�
 *
 *=> 6 0
 */

#include <iostream>
#include <cstring>

using namespace std;

int DPMin[3]{};
int DPMax[3]{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputCount = 0;

	cin >> inputCount;

	int inputNum[3]{};
	for (int i = 0; i < 3; i++)
	{
		cin >> inputNum[i];
	}
	memcpy(DPMin, inputNum, sizeof(inputNum));
	memcpy(DPMax, inputNum, sizeof(inputNum));
	for (int count = 1; count < inputCount; count++)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> inputNum[i];
		}
		int PrevMin[3]{};
		int PrevMax[3]{};
		memcpy(PrevMin, DPMin, sizeof(inputNum));
		memcpy(PrevMax, DPMax, sizeof(inputNum));

		DPMin[0] = min(PrevMin[0], PrevMin[1]) + inputNum[0];
		DPMax[0] = max(PrevMax[0], PrevMax[1]) + inputNum[0];

		DPMin[1] = min(min(PrevMin[0], PrevMin[1]), PrevMin[2]) + inputNum[1];
		DPMax[1] = max(max(PrevMax[0], PrevMax[1]), PrevMax[2]) + inputNum[1];

		DPMin[2] = min(PrevMin[1], PrevMin[2]) + inputNum[2];
		DPMax[2] = max(PrevMax[1], PrevMax[2]) + inputNum[2];
	}

	int resultMin = min(min(DPMin[0], DPMin[1]), DPMin[2]);
	int resultMax = max(max(DPMax[0], DPMax[1]), DPMax[2]);

	cout << resultMax << " " << resultMin;
	return 0;
}
