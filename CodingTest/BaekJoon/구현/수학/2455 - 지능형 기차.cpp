/*
 *2455 - ������ ����
 *
 *�䱸���״�� �����Ѵ�.
 *
 *�Է� �޴� 4���� �������� ����, ��������� ���� �ο��� ����Ѵ�.
 *
 *���� �̸� �غ�� Result�� ���Ͽ� �ִ���� Result�� ������Ʈ �Ѵ�
 *
 *��� 4���� ���� ����� �� ������ ����� ������ �ִ� �ο��� 10000�� ���Ͽ�
 *���� ���� ����Ѵ�.
 *
 *
 */


#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Result = 0;
	int NumOfPeple = 0;
	for (int i = 0; i < 4; i++)
	{
		int NumOfGetOff = 0;
		int NumOfGetOn = 0;

		cin >> NumOfGetOff >> NumOfGetOn;

		NumOfPeple -= NumOfGetOff;
		NumOfPeple += NumOfGetOn;
		Result = max(Result, NumOfPeple);
	}

	cout << min(Result, 10000);
	return 0;
}