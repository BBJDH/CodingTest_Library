/*
 *1037 - ���
 *
 *�Է� �������� ���� ū���� ���� �������� ���� ���� ����� ����Ѵ�.
 *
 *���� ��� �Է¹޾� ������ �v�� ������ ���� ������,
 *
 *������ ��������ʰ� �Է¹����鼭 min, max �񱳸� ����
 *���� �����Ͽ� ����� ������ �ߴ�.
 *
 *���ܷ� ���� �Ѱ��� �Է¹��� ��� ���� ���� ����� 2�� �����ִ� �۾��� �����Ͽ�����.
 *
 *�� ó���� ��� �����ϴ� �׳� int������ �ʰ����� �ʴ� ������Ǹ� �����ϸ� �Ǵ� ��������.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0, LargestNumber = 0, SmallestNumber = 1000001;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		LargestNumber = max(LargestNumber, InputNum);
		SmallestNumber = min(SmallestNumber, InputNum);
	}
	if (SmallestNumber == 1000001)
		SmallestNumber = 2;
	cout << LargestNumber * SmallestNumber;
	return 0;
}