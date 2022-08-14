#include<iostream>
#include<set>
#include<queue>

using namespace std;


/*
1700 멀티탭 스케줄링
콘센트 2구멍 기구 100개라면

1 2  3  1  3  4  2  4  5  4 5  6   7 5 6 7 5  4  3  4  5  2
 12  13 13    43 42    45      65  75  76  56 54 53 54    24
뽑아야하는것은 구멍에 꽂혀있는것중에 가장 나중에 다시사용되는것
가장 나중에 다시 사용되는것을 어떻게 찾을까?
각 기구마다 자신의 사용 기록을 큐로 저장, 사용될때마다 pop
set으로 멀티탭 구성하고 logn 으로 다음 번호가 멀티탭에 존재하는지 검색
존재하지 않는다면 UnPlug 절차 시작
모든 기구들은 자기자신이 다음번에 사용될 번호를 큐의front에 저장중임
때문에 front중에 가장 큰것을 뽑아주면됨(가장 나중에 사용되는것)
또는 큐가 비어있다면 앞으로 사용될 일이 없으므로 바로 뽑고 반복문 탈출

사용목록 큐가 모두 비게 된다면 종료
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