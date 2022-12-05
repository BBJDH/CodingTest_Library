/*
 *1655 - ����� ���ؿ�
 *
 *���� �Է¹����鼭 �����Ͽ� ������� ����ϴ� ����� �ð��ʰ��� �߻��Ѵ�
 *
 *���ش� �켱���� ť �ΰ��� ����ؼ� ���� ���� ���հ� ū���� ������ ������ ť�� �Ҵ��ϰ�
 *������ ������ ���߸� �� �Է°��� �־��ָ� �ȴ�.
 *
 *���� ���� �켱 ����ϵ��� ������ �䱸�ϹǷ� �����׷��� top�� ������ �����ߴ�.
 *
 */

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<>> Upper{};
priority_queue<int, vector<int>> Lower{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputCount = 0;

	cin >> inputCount;

	for (int i = 0; i < inputCount; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		if (Upper.size() == 0)
		{
			Upper.push(inputNum);
			cout << Upper.top();
		}
		else
		{
			if (inputNum <= Upper.top())
				Lower.push(inputNum);
			else
				Upper.push(inputNum);

			if (abs(static_cast<int>(Lower.size() - Upper.size())) == 2 or Upper.size() > Lower.size())
			{
				if (Lower.size() > Upper.size())
				{
					Upper.push(Lower.top());
					Lower.pop();
				}
				else
				{
					Lower.push(Upper.top());
					Upper.pop();
				}
			}
			cout << Lower.top();
		}
		cout << "\n";
	}


	return 0;
}