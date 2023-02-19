/*
 *2164 - 카드2
 *
 *맨 위의 카드를 순서대로 제거해 나가며
 *다시 뒤로 넣어가는 큐를 이용한 문제이다.
 *
 *맨 위의 카드를 버리고
 *그 다음 카드를 옮기는 작업을 한번의 작업으로 처리한다.
 *
 *큐의 사이즈가 1에 도달한다면 종료.
 *마지막 카드를 보여준다.
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
