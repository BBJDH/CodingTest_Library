/*
1461 - ������

���밪���� ���� ��� ��ȹ�� ������ ���� ū������ �����Ͽ� �ִ� ��ݼ���ŭ �߶� ����� ����Ѵ�
�������� ��� ������ ���� �հ��� å������ �Ÿ��� ���ְ��� ���

*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


priority_queue<int> RightNums{};
priority_queue<int> LeftNums{};


int BookCount = 0;
int MaxCarry = 0;
int Sum = 0;
int MaxNum = 0;

void PickTheBook(priority_queue<int>& BookList)
{
	int Path = 0;
	while (!BookList.empty())
	{
		int Count = MaxCarry;
		int const BookPos = BookList.top();
		while (!BookList.empty() and Count--) BookList.pop();
		Path += BookPos;
	}
	Sum += Path * 2;
}

void Solution()
{
	PickTheBook(RightNums);
	PickTheBook(LeftNums);
	Sum -= MaxNum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> BookCount >> MaxCarry;
	for (int i = 0; i < BookCount; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		if (InputNum > 0)
			RightNums.push(InputNum);
		else
		{
			InputNum = abs(InputNum);
			LeftNums.push(InputNum);
		}
		if (MaxNum < InputNum)
			MaxNum = InputNum;
	}

	Solution();
	cout << Sum;
	return 0;
}
