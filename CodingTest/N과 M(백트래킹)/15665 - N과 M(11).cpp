#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;


/*
ù°�ٿ� �ڿ��� N�� M�� �־�����
1���� N���� �ߺ����� M���� ���� ������ ���ؾ� �Ѵ�

N�ѹ��� ���� ��Ȳ�� ��Ÿ���� bitset�� �����Ѵ�

��ͷ� �Լ��� ����
���۹�ȣ�� �׻� 1���� �����ؼ� üũ, ��Ʈ���� 1���� Ȯ���ؼ� ���� ���, bitset�� ���
���� �� ī��Ʈ�� ��� ī��Ʈ�� M�� ���ٸ� ���̻� ��͸� ȣ�� ���� ����
�ش� ����� ���������� ���� �ڽ��� �̾Ҵ� ��ȣ bitset�� ȸ��
*/
set<int> NumArr{};
int MaxNum = 0;
int SeriesSize = 0;


void ExtractNum(int const ExtractCount = 1, string const& Series = {})
{

	for (auto iter = NumArr.begin(); iter != NumArr.end(); iter++)
	{
		string NewSeries = Series;
		NewSeries = NewSeries + to_string(*iter) + " ";
		if (ExtractCount == SeriesSize)
			cout << NewSeries << "\n";
		else if (ExtractCount < SeriesSize)
			ExtractNum(ExtractCount + 1, NewSeries);

	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> MaxNum >> SeriesSize;
	for (int i = 0; i < MaxNum; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		NumArr.insert(InputNum);
	}
	ExtractNum();

	return 0;
}
