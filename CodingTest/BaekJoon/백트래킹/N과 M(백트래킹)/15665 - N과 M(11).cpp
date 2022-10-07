#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;


/*
첫째줄에 자연수 N과 M이 주어진다
1부터 N까지 중복없이 M개를 뽑은 수열을 구해야 한다

N넘버의 뽑은 상황을 나타내줄 bitset을 생성한다

재귀로 함수를 수행
시작번호는 항상 1부터 시작해서 체크, 비트셋을 1부터 확인해서 수를 기록, bitset도 기록
뽑은 후 카운트를 기록 카운트가 M과 같다면 더이상 재귀를 호출 하지 않음
해당 블록을 빠져나가기 전에 자신이 뽑았던 번호 bitset을 회수
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
