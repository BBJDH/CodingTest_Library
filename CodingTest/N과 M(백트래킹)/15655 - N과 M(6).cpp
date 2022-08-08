#include<iostream>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>

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
bitset<9> Combine;
vector<string> SeriesArr{};
vector<int> NumArr{};
int MaxNum = 0;
int SeriesSize = 0;
void ExtractNum(int const ExtractCount = 1, string const& SeriesStr = "", int const MinNum = 0)
{

	for (int i = 0; i < MaxNum; i++)
	{
		string NewSeriesStr = SeriesStr;
		if (Combine[i] == false and NumArr[i] > MinNum)
		{
			Combine[i] = true;
			NewSeriesStr = SeriesStr + to_string(NumArr[i]) + " ";
			if (ExtractCount == SeriesSize)
				SeriesArr.push_back(NewSeriesStr);
			else if (ExtractCount < SeriesSize)
				ExtractNum(ExtractCount + 1, NewSeriesStr, NumArr[i]);
			Combine[i] = false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Combine.reset();

	cin >> MaxNum >> SeriesSize;
	for (int i = 0; i < MaxNum; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		NumArr.push_back(InputNum);
	}
	sort(NumArr.begin(), NumArr.end());
	ExtractNum();

	for (string const& elem : SeriesArr)
		cout << elem << "\n";

	return 0;
}
