/*
 *2022 ������̹����б� ���α׷��� ������ȸ
 *
 *A�� - ������? ������ȣ!
 *
 *security�� bigdata�� ���ڿ��� ������ ���� �����ָ� �ȴ�
 *
 *��� �ϸ� �ð����⵵�� ���������� ������?
 *
 *���� ���ڸ��� ���ǿ� �ΰ��� �ܾ �־����ٴ°��� Ȯ���߰�,
 *
 *s b ���ڴ� �� �ܾ�� ���� �������� Ȯ���Ͽ�
 *
 *O(N)���� s�� b �� ī��Ʈ �ؼ� ����ߴ�
 *
 *ó�� �Է¹޴� �л����� ��Ǯ�� ������ ���ǹ��ϴ�
 *
 *
 */

#include <iostream>
#include <string>


using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string inputStr{};
	int N = 0;
	cin >> N;
	cin.ignore();
	getline(cin, inputStr);

	int b = 0;
	int s = 0;


	for (int i = 0; i < inputStr.size(); i++)
	{
		switch (inputStr[i])
		{
		case 's': s++; break;
		case 'b': b++; break;
		}
	}

	if (s == b)
		cout << "bigdata? security!";
	else if (s > b)
		cout << "security!";
	else
		cout << "bigdata?";





	return 0;
}