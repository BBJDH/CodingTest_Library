/*
 *10988 - �Ӹ�������� Ȯ���ϱ�
 *
 *
 *������ �䱸���״�� �Է¹��� ���ڿ��� �¿� ��Ī���� Ȯ���Ѵ�.
 *
 *����� �ִ� ���ڴ� Ȯ���� �ʿ䰡 �����Ƿ�
 *
 *�Է¹��� ���ڿ� [0���ε���] == [���ε���-0]
 *�Է¹��� ���ڿ� [1���ε���] == [���ε���-1]
 *
 *�� ���� �ش�.
 *
 *�񱳵��� �ٸ���찡 �߻��Ѵٸ� 0�� ����ϰ� ����
 *�ݺ����� �������� �ݱ��� ��� ���Ҵٸ� 1�� ����ϰ� �����Ѵ�.
 *
 *
 *
 */

#include<iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	cin >> InputStr;

	for (int i = 0; i < InputStr.size() / 2; i++)
	{
		if (InputStr[i] != InputStr[InputStr.size() - i - 1])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	return 0;
}