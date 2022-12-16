/*
 *20923 - ���� �Ҹ����� ����
 *
 *���� ��Ģ�� �������� �Ǵ� ������
 *
 *�������� 1
 *�� ��밡 ������ �̰� �� ��Ȳ���� ���� �︱�� �Ǵ��ϴ� ���� 1ȸ �������� �Ѵ�
 *�� ������ ���� ������ �´ٸ� �̹� ���� ������ 2ȸ�� �Ǿ���.
 *
 *�������� 2
 *�Է¹��� ī�带 ����ó�� �� �����Էº��� ī�带 �����Ѵ�
 *�� �� ������ �Է� ���� ���� ���� ������ ���µȴ�
 *
 *����
 *
 *���� �̿��Ѵ�. ī���� ������ �������� top�� �̾Ƽ� ����,
 *�׶����� ī�带 ȸ���Ҷ��� �׶����� ī�带 front�� push�ؾ��Ѵ�
 *
 * Ground�� push�� pop�� ť�� ���� �� ������, �� ȸ back�� ���ϱ� ���� ���� ����ߴ�.
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
			//���� ����
			SuGround.push_back(Su.back());
			Su.pop_back();
			if (Su.empty())
				break;
		}
		else
		{
			//���� ����
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