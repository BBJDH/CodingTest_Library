/*
 *2869 - �����̴� �ö󰡰� �ʹ�
 *
 *���� �����ϸ� ���̻� �̲������������Ƿ�, �Ųٷλ����غ���
 *����-�ö󰡴� ���� �� �ö󰡴³���-�������� ���� ��ŭ �Ϸ翡 �ö󰣴ٰ� �����ϸ� �ȴ�
 *�����⿬�����ϸ� �������� �������Ƿ� ��������
 *�������� ���̵� �Ϸ縦 �Ἥ �ö�����Ѵ�(mod �������� ó��)
 *
 *
 */


#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int climbHeght = 0, fallheght = 0, goalHeight = 0;


	cin >> climbHeght >> fallheght >> goalHeight;

	goalHeight = goalHeight - climbHeght;

	int dayCount = goalHeight / (climbHeght - fallheght);
	if (goalHeight % (climbHeght - fallheght))
		dayCount++;
	dayCount++;


	cout << dayCount;
	return 0;
}