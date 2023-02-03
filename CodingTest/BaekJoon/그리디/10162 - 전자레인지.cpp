/*
 *10162 - ���ڷ�����
 *
 *�Ž��������� Ǯ�� ����� �����ϴ�.
 *
 *�Է¹��� �ð��� �ʴ��� �̹Ƿ�
 *
 *�� A��ư B��ư C��ư�� 300,60,10 �ʷ� �����Ͽ� �����Ѵ�.
 *
 *�׸��� �־��� ���� 300, 60, 10 ������ ���������
 *
 *���� 10���� ���� ���� �ʼ��� 0�� �ƴ϶�� -1
 *
 *0�̶�� ������ ������ �� ��ư ī��Ʈ ������ ���
 *
 *
 *
 *������ ���
 *
 *�����غ��� ��ư ������ �۾��� while������ �ѹ��� ���ʿ䰡 ������.
 *
 *�׳� ���ǹ����� ��ư�� �ش��ϴ� �ʺ��� ũ�ٸ�
 *���� ���ϰ� �׸�ŭ ������ָ� �ȴ�.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int Button[3] = { 300,60,10 };
	int Count[3] = {};


	int inputTime = 0;
	cin >> inputTime;
	for (int i = 0; i < 3; i++)
	{
		if (inputTime >= Button[i])
		{
			int mul = inputTime / Button[i];
			inputTime -= mul * Button[i];
			Count[i] = mul;
		}
	}

	if (inputTime != 0)
	{
		cout << -1;
		return 0;
	}


	cout << Count[0] << " " << Count[1] << " " << Count[2];


	return 0;
}