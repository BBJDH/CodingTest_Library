/*
 *15829 - Hashing
 *
 *������ �䱸���״�� �����Ѵ�.
 *
 *�ٸ� ������ ���̰� 50�� �ƴ϶� �� ��������� �ִٴ� ��������
 *���� ����� ������������ Ǯ����(�� ������ ������������ �������ʰ� N���� ��� ���ص� Ǯ�� �����ϴ�.)
 *
 *
 *1234567891 * 1234567891 �� �����÷ο찡 �߻��ϹǷ� ��갪�� long long���� �޾Ƽ� ó���Ѵ�.
 *
 *�ؽ��Լ��� �ȿ��� �������� ������������ ����� GetPowerNumWithModNum �Լ��� �ۼ��ߴ�.
 *
 *�Է¹��� ���ڿ��� �� ���ڿ� ���߾� �ؽ̰��� ���ϰ� ModNum���� ������ �����Ͽ� ����Ѵ�.
 *
 */

#include <iostream>
#include <string>

using namespace std;


//Mod�� �����÷ο츦 �����ϴ� �������� ���� ���, 1234567891*1234567891�� 42���� �Ѿ��.
long long GetPowerNumWithModNum(long long const BaseNum, long long ExponentNum, long long const NumOfMod)
{
	if (ExponentNum == 0)
	{
		return 1;
	}
	if (ExponentNum == 1)
	{
		return BaseNum % NumOfMod;
	}

	//������ ������ �ɰ��� ��� ����
	long long ResultOfHalf = GetPowerNumWithModNum(BaseNum, ExponentNum / 2, NumOfMod);

	//�ɰ��� �ٽ� ��ġ��
	long long Result = (ResultOfHalf * ResultOfHalf) % NumOfMod;

	if (ExponentNum % 2 == 1)
	{
		//Ȧ���� ���� ��꿡�� 1�� ���ư����Ƿ�.. 1��ŭ �� ��� 
		Result = (Result * BaseNum) % NumOfMod;
	}

	return Result;
}

long long HashFunction(string const& InputStr)
{
	long long Result = 0;
	long long const ModNum = 1234567891;
	long long const EigenValue = 31;

	for (int i = 0; i < InputStr.size(); i++)
	{
		long long HashNum = InputStr[i] - 'a' + 1;
		HashNum = HashNum * GetPowerNumWithModNum(EigenValue, i, ModNum);
		HashNum = HashNum % ModNum;
		Result += HashNum;
		Result = Result % ModNum;
	}
	return Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Lenth = 0;
	string InputStr{};
	cin >> Lenth >> InputStr;

	cout << HashFunction(InputStr);

	return 0;
}