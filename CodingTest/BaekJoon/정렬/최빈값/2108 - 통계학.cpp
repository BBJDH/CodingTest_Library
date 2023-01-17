/*
 *2108 - �����
 *
 *������ - �Է¹��� ���� ������Ű�� �̰��� N���� ������ ����Ѵ�. �ٸ� ������ float���� ����ϸ� ������ �߻��Ͽ�
 *			����ó���� ���� �����Ƿ� double�� ����Ѵ�.
 *�߾Ӱ� - N�� Ȧ���̹Ƿ� �Է¼��ڹ迭�� ���� �� N/2�� �ε����� �����Ͽ� ����Ѵ�.
 *�ֺ� - �Է¹޴� ���� ������ -4000 ~ 4000 �̹Ƿ� 0~ 8000���ε����� ������ ���� �迭�� �����Ѵ�.
 *		���� �ش� ��ȣ�� ������ +4000���� ī��Ʈ�� �÷��ְ� �ִ� ī��Ʈ�� ������Ʈ�صд�
 *		�Է��� ��ģ �� �ִ� ī��Ʈ�� ��ġ�ϴ� �迭�� O(n)���� Ž���Ѵ�.
 *		���� �̹� ã�Ҵµ� �� ���´ٸ� �� ���� ���(-4000�� �ش��ϴ� 0������ Ž���ϹǷ� �ι�°�� ���� ����.)
 *		�ݺ����� ������ Ż���ߴٸ� �ֺ��� �ϳ��̹Ƿ� �״�� ������ش�.
 *���� - ���ĵ� �迭�� �� �հ� �� ���� �������� ���밪�� ����ߴ�.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int NumCount[8001]{};
int MaxCount = 0;
int GetMaxCountNum()
{
	bool IsFound = false;
	int Result = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (NumCount[i] == MaxCount)
		{
			if (IsFound == true)
				return i - 4000;
			IsFound = true;
			Result = i - 4000;
		}
	}
	return Result;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> Nums{};
	int N = 0;
	cin >> N;
	double Sum = 0;

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		NumCount[inputNum + 4000]++;
		MaxCount = max(MaxCount, NumCount[inputNum + 4000]);
		Sum += static_cast<double>(inputNum);
		Nums.push_back(inputNum);
	}

	sort(Nums.begin(), Nums.end());

	printf("%d\n", static_cast<int>(round(Sum / N)));	//������
	printf("%d\n", Nums[N / 2]);						//�߾Ӱ�
	printf("%d\n", GetMaxCountNum());					//***�ֺ�***
	printf("%d\n", abs(Nums[N - 1] - Nums[0]));			//����

	return 0;

}