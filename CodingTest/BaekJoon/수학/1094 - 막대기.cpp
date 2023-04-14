/*
 *1094 - �����
 *
 *[11047 - ���� 0] �� ������ ������
 *
 *���� ū ������� 64���� ������ ũ�� �񱳸� ����
 *���� ���� ���� ���밡 �� �۴ٸ� �ϳ��� ���س�����.
 *
 *���� ���� ���밡 �� Ŀ���� ���� TargetLength�� �����ִٸ�
 *���� ���� ���븦 ������ ������ �ٽ� TargetLength�� 0�� �ɶ� ���� �����Ѵ�
 *
 *���� ���� ���� ����� ���̰� 1�� �ǹǷ� �ݵ�� ���ؿ� �����ϰ� �ȴ�.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TargetLength = 0;
	cin >> TargetLength;
	int Result = 0;
	int CurrentStickLength = 64;
	while (TargetLength != 0)
	{
		if (TargetLength >= CurrentStickLength)
		{
			TargetLength = TargetLength - CurrentStickLength;
			Result++;
			continue;
		}
		CurrentStickLength /= 2;
	}
	cout << Result;
	return 0;
}