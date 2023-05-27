/*
 *2902 - KMP�� �� KMP�ϱ�?
 *
 *���ڿ� �Ľ��� ����� ����
 *
 *stringstream�� �̿��� Ǭ�ٸ� �������� ���� ���ڷ� �����Ͽ�
 *�ܾ������ ��� �о� �� �� �ִ�.
 *
 *������ �䱸���״�� ����� �ܾ��� ù ���ڸ� ���!
 *
 *
 */


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	getline(cin, InputStr);	//�ٴ����� �о����. ���⵵ ���� �о�� �� �ִ�. 

	stringstream SS(InputStr);		//���ڿ��� ��Ʈ���� ��´� �Ʒ��� getline �Լ��� ����ϱ� ����
	string Token{};

	//stream SS�� ��� ���ڿ����� - ������ �ܾ �߶� Token�� �����Ѵ�.
	//�� ���� �� ���ٸ� while Ż��
	while (getline(SS, Token, '-'))
	{
		//�䱸���״�� ù���ڸ� ���
		cout << Token[0];
	}


	return 0;
}