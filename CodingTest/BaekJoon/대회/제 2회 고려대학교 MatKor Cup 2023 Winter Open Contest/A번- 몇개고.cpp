/*
 * �� 2ȸ ������б� MatKor Cup : 2023 Winter Open Contest
 *
 * A�� - ���?
 *
 * ������ �䱸���״�� �����Ѵ�.
 *
 * ������ ��������, ���ǹ� ������ ����ȭ�ϴ� ����� �غ���
 */
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Time = 0, WithAlcole = 0;

	cin >> Time >> WithAlcole;

	if (WithAlcole == 1)
	{
		cout << 280;
		return 0;
	}
	if (Time >= 12 and Time <= 16)
	{
		cout << 320;
		return 0;
	}
	cout << 280;

	return 0;
}