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
vector<vector< int>> SeriesArr{};
vector<int> NumArr{};
int MaxNum = 0;
int SeriesSize = 0;
bool IsEqualSeries(vector<int> const& Src, vector<int> const& Dest)
{
	for (int i = 0; i < Src.size(); i++)
	{
		if (Src[i] != Dest[i])
			return false;
	}
	return true;

}

bool IsExistSeries(vector<int> const& Series)
{
	for (auto iter = SeriesArr.begin(); iter != SeriesArr.end(); iter++)
	{
		if (IsEqualSeries(*iter, Series))
			return true;
	}
	return false;
}

void ExtractNum(int const ExtractCount = 1, vector<int> const& Series = {}, int const MinNum = 0)
{

	for (int i = 0; i < MaxNum; i++)
	{
		vector<int> NewSeries = Series;
		if (Combine[i] == false)
		{
			Combine[i] = true;
			NewSeries.push_back(NumArr[i]);
			if (ExtractCount == SeriesSize and IsExistSeries(NewSeries) == false)
				SeriesArr.push_back(NewSeries);
			else if (ExtractCount < SeriesSize)
				ExtractNum(ExtractCount + 1, NewSeries, NumArr[i]);
			Combine[i] = false;
		}
	}
}
void PrintSeries(vector<int> const& Series)
{
	for (int const& elem : Series)
		cout << elem << " ";
	cout << "\n";
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

	for (auto iter = SeriesArr.begin(); iter != SeriesArr.end(); ++iter)
		PrintSeries(*iter);

	return 0;
}
