
/*
 2212 센서
 각 센서사이 거리를 구해주고 여기서 가장 큰 거리를 집중국 수-1 만큼 끊어주면
 집중국 수만큼의 센서집단이 형성된다
 이제 남아있는 센서사이거리를 모두 더해주면 된다

*/

#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int SensorNum = 0;
int LinkerNum = 0;

vector<int> SenSorCood{};
vector<int> Distance{};

void Solution()
{
	int Answer = 0;

	for (int i = 0; i < SenSorCood.size() - 1; i++)
	{
		int CurrentDistance = SenSorCood[i + 1] - SenSorCood[i];
		Distance.push_back(CurrentDistance);
	}
	sort(Distance.begin(), Distance.end());
	for (int i = 0; i < Distance.size() - LinkerNum + 1; i++)
	{
		Answer += Distance[i];
	}
	cout << Answer;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SensorNum >> LinkerNum;
	if (LinkerNum > SensorNum)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < SensorNum; i++)
	{
		int InputCood = 0;
		cin >> InputCood;
		SenSorCood.push_back(InputCood);
	}
	sort(SenSorCood.begin(), SenSorCood.end());

	Solution();
	return 0;
}
