/*
 *1629 - ����
 *
 * �Է¹޴� ������ ũ�Ⱑ 21���� ũ�⸸ŭ �����Ƿ�
 *
 * �������� ���� ����س����� �ð��ʰ��� �߻��Ѵ�.
 * �־��� ������ 21���� logn���� Ǯ��� �� �ִ� ���������� ���� Ǯ����.
 *
 * 21���� ȣ���Ѵٸ� ������ ���� 10���� ���� �̰��� �ι� ���ϸ� �ȴ�.
 * ���������� 10���� 5������ �ɰ�����
 *
 * ...
 *
 * ������ 1�� �����Ѵٸ� �ڽ��� �� % �������� ��ȯ ó���Ѵ�
 *
 * Ȧ���� ��츸 ���ܷ� ó���Ͽ� �ѹ��� �� ���Ͽ� ������ ��ȯó���Ѵ�.
 *
 * �� �������� Mod ������ ���־�� �Ѵ� �׷��������� �����÷ο�� Ʋ������ ���ȴ�.
 *
 * ������������ �ڽ��� ���� ���� �����ų� �ڽ��� ��*�ڽ��� ���� ���� �������� ����� ����� ��������
 * ������ ��Ģ�� �ִ�.
 *
 */
#include <iostream>

using namespace std;

long long GetMul(long long const NumOfMul, long long CountOfMul, long long const NumOfMod)
{
	if (CountOfMul == 1)
	{
		return NumOfMul % NumOfMod;
	}

	long long ResultOfHalf = GetMul(NumOfMul, CountOfMul / 2, NumOfMod);

	long long Result = (ResultOfHalf * ResultOfHalf) % NumOfMod;

	if (CountOfMul % 2 == 1)
	{
		//Ȧ���� ���� ��꿡�� 1�� ���ư����Ƿ�.. 1��ŭ �� ��� 
		Result = (Result * NumOfMul) % NumOfMod;
	}

	return Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long NumOfMul = 0, CountOfMul = 0, NumOfMod = 0;
	cin >> NumOfMul >> CountOfMul >> NumOfMod;

	long long Result = GetMul(NumOfMul, CountOfMul, NumOfMod);

	cout << Result;
	return 0;
}