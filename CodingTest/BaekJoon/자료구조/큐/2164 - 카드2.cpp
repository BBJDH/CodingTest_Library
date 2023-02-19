/*
 *2164 - ī��2
 *
 *�� ���� ī�带 ������� ������ ������
 *�ٽ� �ڷ� �־�� ť�� �̿��� �����̴�.
 *
 *�� ���� ī�带 ������
 *�� ���� ī�带 �ű�� �۾��� �ѹ��� �۾����� ó���Ѵ�.
 *
 *ť�� ����� 1�� �����Ѵٸ� ����.
 *������ ī�带 �����ش�.
 */

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	queue<int> Card{};
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		Card.push(i);
	}
	while (Card.size() != 1)
	{
		Card.pop();
		int pushNum = Card.front();
		Card.pop();
		Card.push(pushNum);
	}

	cout << Card.front();
	return 0;
}
