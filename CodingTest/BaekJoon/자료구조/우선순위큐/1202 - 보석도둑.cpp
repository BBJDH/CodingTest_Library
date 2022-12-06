/*
 *1202 - ��������
 *
 *������ ���� ũ������� ����(���� ũ�Ⱑ ������ �� �ִ°Ϳ� ����)
 *
 *������ ũ������� �����Ѵ�. �̰��� ����ũ�� ���Ϸ� �̾Ƴ� ������ �����.
 *�ش� ���տ��� ũ��� �����ϰ� (������ �Ѱ��� ���� �� �����Ƿ� ) ��ġ�� ���� ������ �ϳ��� �̾Ƽ� ���濡 �ִ´�.
 *
 *�켱����ť �ΰ��� ����Ͽ����� �ϳ��� ����ϰ� Ǯ�̰� �����ϴ�
 *������ ���Լ����� �����ϰ� �ش� ���Ա��� �ݺ������� Values �켱���� ť�� �־��ָ� �ȴ�
 *���� Gems�� Vector�� ����Ǹ� ���� �Է��� �ް� Weight�������� ������ �ѹ� �����ϸ� �ȴ�
 *(��� �� ���ĵ� nlogn �̰� �켱����ť�� �������� logn�� n�� �̾ƾ� �Ѵ�,
 *���� ���ʹ� ���Խ� 1�� ����� ��°Ͱ� �޸� �켱���� ť�� ���Խ� logn�� ����� �Ҹ�ǹǷ� ���ͷ� �õ��غ��°��� �� ������)
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

//������ �ش� ������ �����ϸ鼭 ���� ���� ��ġ�� ���� ������ �ʿ�
priority_queue<_int2, vector<_int2>, greater<>> Gems{};
//������ ���� ���� ������� �ʿ�
priority_queue<long long> Values{};
vector<int> Begs{};

int SumValue = 0;
void Solution()
{
	//������ ���� ������ ���� ���� value�� �̾Ƴ�
	//�켱���� ť�� ���湫�� ���ϸ� �����ϰ� ��ġ value�� �̾Ƽ� ����

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
