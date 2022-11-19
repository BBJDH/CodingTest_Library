/*
 *1316 - �׷� �ܾ� üĿ
 *
 *�ܾ� �ϳ��� ���Ͽ� �����غ���
 *�ߺ��� üũ���� 26���� �ҹ��� �迭�� �����
 *���ο� �ܾ��� �迭�� üũ�ϰ� �������ڸ� ��� �ǳʶڴ�
 *���ķ� �ٽ� ���ڰ� �����ϸ� false�� ����
 *
 *
 */



#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Str{};
int StringCount = 0;



bool IsGroupStr(string const& Str)
{
	bool checkChar[26]{};

	for (int i = 0; i < Str.size(); i++)
	{
		int newVisit = Str[i] - 'a';

		if (checkChar[newVisit])
			return false;
		else
		{
			checkChar[newVisit] = true;
			char overlapChar = Str[i];
			//��ġ�� ���� �ǳʶٱ�
			while (overlapChar == Str[i])i++;

			//�������ڷ� �Ѿ�����Ƿ� �ѹ� �ǵ���, ���� for������ i++�� ���۵ǹǷ�
			i--;
		}
	}
	return true;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> StringCount;
	int Count = 0;
	for (int i = 0; i < StringCount; i++)
	{
		string inputStr{};
		cin >> inputStr;
		if (IsGroupStr(inputStr))
			Count++;
	}
	cout << Count;

	return 0;
}