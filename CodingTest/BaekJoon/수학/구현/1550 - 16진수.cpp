/*
 *
 *1550 - 16����
 *
 * FFF �� �������� ��ȯ�ϸ�,
 *
 * F(16^2)*15 + F(16^1)*15 + F(16^0)*15 �� ���ȴ�
 *
 * ���������� A901 �� ��ȯ�Ѵٸ�,
 *
 * A(16^3)*10 + (16^2)*9 + (16^1)*0 + (16^0)*1 �� ���ȴ�
 *
 * �� �� �ڸ��� ���� 16�� ������ �ش� �ڸ����� 10������ ��ȯ�� ���� ���̹Ƿ�
 * ���� �� �ڸ��� ���� 10������ ��ȯ�� �Լ��� �����.
 *
 * ���� �Է� ���� ���ڿ��� ���Ͽ� �ݺ������� ��ȸ�ϸ� �Լ��� ȣ���Ѵ�
 *
 * �Լ����� ��ȯ�Ǵ°��� �����Ͽ� ���� ����� 16 ������ ��ȯ�� ���� �ش��Ѵ�.
 *
 *
 *
 */



#include <iostream>
#include <string>
#include <cmath>

using namespace std;



long long HexToDec(char const Hex, long long const Exponent)
{
	long long Result = 0;
	if (Hex <= '9')
	{
		Result = Hex - '0';
	}
	else
	{
		Result = Hex - 'A' + 10;
	}

	Result = Result * static_cast<long long>(pow(16, Exponent));

	return Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	cin >> InputStr;
	long long Result = 0;

	for (int i = 0; i < InputStr.size(); i++)
	{
		Result += HexToDec(InputStr[InputStr.size() - i - 1], i);
	}
	cout << Result;
	return 0;
}