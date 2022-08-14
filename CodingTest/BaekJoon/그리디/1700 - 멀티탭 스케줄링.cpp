#include<iostream>
#include<set>
#include<queue>

using namespace std;


/*
1700 ��Ƽ�� �����ٸ�
�ܼ�Ʈ 2���� �ⱸ 100�����

1 2  3  1  3  4  2  4  5  4 5  6   7 5 6 7 5  4  3  4  5  2
 12  13 13    43 42    45      65  75  76  56 54 53 54    24
�̾ƾ��ϴ°��� ���ۿ� �����ִ°��߿� ���� ���߿� �ٽû��Ǵ°�
���� ���߿� �ٽ� ���Ǵ°��� ��� ã����?
�� �ⱸ���� �ڽ��� ��� ����� ť�� ����, ���ɶ����� pop
set���� ��Ƽ�� �����ϰ� logn ���� ���� ��ȣ�� ��Ƽ�ǿ� �����ϴ��� �˻�
�������� �ʴ´ٸ� UnPlug ���� ����
��� �ⱸ���� �ڱ��ڽ��� �������� ���� ��ȣ�� ť��front�� ��������
������ front�߿� ���� ū���� �̾��ָ��(���� ���߿� ���Ǵ°�)
�Ǵ� ť�� ����ִٸ� ������ ���� ���� �����Ƿ� �ٷ� �̰� �ݺ��� Ż��

����� ť�� ��� ��� �ȴٸ� ����
*/
struct Table
{
	queue<int> UseIndex{};
};

Table UsingTable[101]{};
queue<int> UsingNums{};
set<int> MultiTap{};
int UsingIndex = 0;
int UnPlugCount = 0;

void UnPlug()
{
	int UnPlugNum = 0;
	int UsingMaxIndex = 0;
	for (auto iter = MultiTap.begin(); iter != MultiTap.end(); iter++)
	{
		if (UsingTable[*iter].UseIndex.empty())
		{
			UnPlugNum = *iter;
			break;
		}
		else if (UsingMaxIndex < UsingTable[*iter].UseIndex.front())
		{
			UnPlugNum = *iter;
			UsingMaxIndex = UsingTable[*iter].UseIndex.front();
		}
	}
	MultiTap.erase(UnPlugNum);
	UnPlugCount++;
}


void Solution()
{
	while (!UsingNums.empty())
	{
		int CurrentUse = UsingNums.front();
		UsingNums.pop();
		if (MultiTap.find(CurrentUse) == MultiTap.end())
			UnPlug();
		MultiTap.insert(CurrentUse);
		UsingTable[CurrentUse].UseIndex.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int MultiTapSize = 0;
	int UsingNumsSize = 0;

	cin >> MultiTapSize >> UsingNumsSize;
	for (int i = 0; i < UsingNumsSize; i++)
	{
		int InputNum = 0;
		cin >> InputNum;

		if (MultiTap.size() < MultiTapSize)
			MultiTap.insert(InputNum);
		else
		{
			UsingNums.push(InputNum);
			UsingTable[InputNum].UseIndex.push(i + 1);
		}

	}
	Solution();
	cout << UnPlugCount;

	return 0;
}