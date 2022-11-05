/*
12852 - 1로 만들기 2

1부터 10^6까지 n만큼 실행하여 +1 *2 *3 해보며 갱신되는 최소비용을 업데이트를 기록
추후 거꾸로 출력을 위해 최소비용 업테이트 시 소스넘버를 같이 기록한다.

입력받은 번호를 인덱스로하여 Count를 출력하고 Src로 역추적하여 출력

 */


#include <iostream>
#include <algorithm>

using namespace std;

struct _int2
{
	int Count;
	int Src;
};

_int2 Nums[1000001]{};

_int2 MIN(_int2 const& NewVal, _int2 const& Dest)
{
	_int2 Result{};

	if (NewVal.Count < Dest.Count or Dest.Count == 0)
		return NewVal;
	else
		return Dest;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 1; i < 1000000; i++)
	{
		_int2 const NewVal = { Nums[i].Count + 1,i };
		Nums[i + 1] = MIN(NewVal, Nums[i + 1]);
		if (i * 2 <= 1000000)
			Nums[i * 2] = MIN(NewVal, Nums[i * 2]);
		if (i * 3 <= 1000000)
			Nums[i * 3] = MIN(NewVal, Nums[i * 3]);
	}


	int TargetNum = 0;
	cin >> TargetNum;
	cout << Nums[TargetNum].Count << "\n";


	int Num = TargetNum;
	while (true)
	{
		cout << TargetNum << " ";

		if (TargetNum == 1)
			return 0;

		TargetNum = Nums[TargetNum].Src;

	}

	return 0;
}