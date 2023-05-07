/*
 * 1715 - 카드 정렬하기
 *
 *입력받는 숫자의 크기가 10만이므로 모든 조합을 시도한다고하면
 *10만!의 비용 가까이 들게 된다.
 *
 *따라서 규칙을 찾아보면 그리디로 풀이 가능함을 알 수 있다.
 *
 *가장 작은 수들부터 두 카드를 합해 묶어나가면 최적해에 도달하게 된다.
 *
 *두 카드를 합쳤을때 해당 카드 묶음이 가장 작은 묶음이 아닐 수 있으므로
 *매 pop마다 최소크기의 카드 묶음이 빠져나올 수 있게 우선순위큐를 사용한다.
 *
 *처음 입력받은 카드 묶음을 우선순위 큐에 삽입하고
 *
 *둘씩 작은것들을 꺼내어 합한후 다시 큐에 삽입한다.
 *
 *위의 과정을 우선순위 큐의 크기가 1이 될 때까지 진행,
 *위 과정동안 합쳤던 카드 비용을 누적하여 출력한다.
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