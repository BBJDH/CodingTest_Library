/*
 * 1715 - ī�� �����ϱ�
 *
 *�Է¹޴� ������ ũ�Ⱑ 10���̹Ƿ� ��� ������ �õ��Ѵٰ��ϸ�
 *10��!�� ��� ������ ��� �ȴ�.
 *
 *���� ��Ģ�� ã�ƺ��� �׸���� Ǯ�� �������� �� �� �ִ�.
 *
 *���� ���� ������� �� ī�带 ���� ������� �����ؿ� �����ϰ� �ȴ�.
 *
 *�� ī�带 �������� �ش� ī�� ������ ���� ���� ������ �ƴ� �� �����Ƿ�
 *�� pop���� �ּ�ũ���� ī�� ������ �������� �� �ְ� �켱����ť�� ����Ѵ�.
 *
 *ó�� �Է¹��� ī�� ������ �켱���� ť�� �����ϰ�
 *
 *�Ѿ� �����͵��� ������ ������ �ٽ� ť�� �����Ѵ�.
 *
 *���� ������ �켱���� ť�� ũ�Ⱑ 1�� �� ������ ����,
 *�� �������� ���ƴ� ī�� ����� �����Ͽ� ����Ѵ�.
 *
 */

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<>> Cards{};

	int N = 0;
	cin >> N;
	while (N--)
	{
		int InputCard = 0;
		cin >> InputCard;
		Cards.push(InputCard);
	}

	int Result = 0;
	while (Cards.size() != 1)
	{
		int const FirstCard = Cards.top();
		Cards.pop();
		int const SecondCard = Cards.top();
		Cards.pop();

		int Sum = FirstCard + SecondCard;
		Result = Result + Sum;
		Cards.push(Sum);
	}
	cout << Result;
	return 0;
}