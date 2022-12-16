/*
 *20923 - 숫자 할리갈리 게임
 *
 *게임 규칙을 잘읽으면 되는 문제다
 *
 *유의할점 1
 *각 상대가 한장을 뽑고 그 상황에서 종을 울릴지 판단하는 것을 1회 진행으로 한다
 *즉 도도가 내고 수연이 냈다면 이미 게임 진행은 2회가 되었다.
 *
 *유의할점 2
 *입력받은 카드를 스택처럼 맨 나중입력부터 카드를 제출한다
 *즉 맨 마지막 입력 받은 수가 제일 위에서 오픈된다
 *
 *진행
 *
 *덱을 이용한다. 카드의 제출은 스택으로 top을 뽑아서 내고,
 *그라운드의 카드를 회수할때는 그라운드의 카드를 front에 push해야한다
 *
 * Ground도 push와 pop은 큐로 사용될 수 있지만, 매 회 back을 비교하기 위해 덱을 사용했다.
 *
 *
 */


#include <iostream>
#include <queue>

using namespace std;

deque<int> Do{};
deque<int> Su{};

deque<int> DoGround{};
deque<int> SuGround{};
int N = 0, M = 0;

void Solution()
{
	for (int i = 0; i < M; i++)
	{
		if (i % 2)
		{
			//수연 차례
			SuGround.push_back(Su.back());
			Su.pop_back();
			if (Su.empty())
				break;
		}
		else
		{
			//도도 차례
			DoGround.push_back(Do.back());
			Do.pop_back();
			if (Do.empty())
				break;
		}

		if (not (DoGround.empty() or SuGround.empty()) and DoGround.back() + SuGround.back() == 5)
		{
			while (not DoGround.empty())
			{
				Su.push_front(DoGround.front());
				DoGround.pop_front();
			}

			while (not SuGround.empty())
			{
				Su.push_front(SuGround.front());
				SuGround.pop_front();
			}
		}

		if (not DoGround.empty() and DoGround.back() == 5 or not SuGround.empty() and SuGround.back() == 5)
		{
			while (not SuGround.empty())
			{
				Do.push_front(SuGround.front());
				SuGround.pop_front();
			}
			while (not DoGround.empty())
			{
				Do.push_front(DoGround.front());
				DoGround.pop_front();
			}
		}
	}
	if (Do.size() == Su.size())
		cout << "dosu";
	else if (Do.size() > Su.size())
		cout << "do";
	else
		cout << "su";

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);



	cin >> N >> M;

	while (N--)
	{
		int doCard = 0, suCard = 0;
		cin >> doCard >> suCard;
		Do.push_back(doCard);
		Su.push_back(suCard);
	}
	Solution();
	return 0;
}