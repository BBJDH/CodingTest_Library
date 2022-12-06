/*
 *1202 - 보석도둑
 *
 *가방을 작은 크기순으로 뺀다(같은 크기가 존재할 수 있는것에 유의)
 *
 *보석을 크기순으로 정렬한다. 이것을 가방크기 이하로 뽑아낸 집합을 만든다.
 *해당 집합에서 크기는 무시하고 (가방은 한개만 담을 수 있으므로 ) 가치가 가장 높은것 하나만 뽑아서 가방에 넣는다.
 *
 *우선순위큐 두개를 사용하였지만 하나만 사용하고도 풀이가 가능하다
 *보석을 무게순으로 정렬하고 해당 무게까지 반복문으로 Values 우선순위 큐로 넣어주면 된다
 *따라서 Gems는 Vector로 변경되며 최초 입력을 받고 Weight기준으로 정렬을 한번 시행하면 된다
 *(사실 이 정렬도 nlogn 이고 우선순위큐로 뽑을때도 logn을 n번 뽑아야 한다,
 *물론 벡터는 삽입시 1의 비용이 드는것과 달리 우선순위 큐는 삽입시 logn의 비용이 소모되므로 벡터로 시도해보는것이 더 빠르다)
 *
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct _int2
{
	int Weight;
	long long Value;
};

bool operator>(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight > Right.Weight;
}
bool operator<(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight < Right.Weight;
}

//보석은 해당 무개를 충족하면서 가장 높은 가치를 가진 보석이 필요
priority_queue<_int2, vector<_int2>, greater<>> Gems{};
//가방은 가장 작은 가방부터 필요
priority_queue<long long> Values{};
vector<int> Begs{};

int SumValue = 0;
void Solution()
{
	//가방의 무기 이하중 가장 높은 value를 뽑아냄
	//우선순위 큐에 가방무게 이하를 삽입하고 고가치 value로 뽑아서 넣음

	sort(Begs.begin(), Begs.end());
	long long maxValue = 0;
	for (int i = 0; i < Begs.size(); i++)
	{
		while (not Gems.empty() and Begs[i] >= Gems.top().Weight)
		{
			Values.push(Gems.top().Value);
			Gems.pop();
		}
		if (not Values.empty())
		{
			maxValue += Values.top();
			Values.pop();
		}
	}
	cout << maxValue;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int HowManyGams{};
	int HowManyBags{};

	cin >> HowManyGams >> HowManyBags;

	for (int i = 0; i < HowManyGams; i++)
	{
		_int2 inputGem{};

		cin >> inputGem.Weight >> inputGem.Value;
		Gems.push(inputGem);
	}
	for (int i = 0; i < HowManyBags; i++)
	{
		int inputBeg{ };
		cin >> inputBeg;
		Begs.emplace_back(inputBeg);
	}
	Solution();
	return 0;
}
