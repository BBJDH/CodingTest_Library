/*
 *14889 - 스타트와 링크
 *
 *입력 받은 배열
 *
 *팀원 A와 B가 만드는 능력치는 배열을 통해 한번에 조회 가능하다.
 *처음엔 문제에 의무 참석이 아니라는 언급때문에 인원설정이 자유로워 풀이가 어렵게 느꼈지만
 *
 *인원은 N/2로 고정이다.
 *
 *따라서 백트래킹으로 N/2만큼의 조합을 구성한다.
 *기억하자.. 조합문제가 나오면 백트래킹....
 *
 *N개를 대상으로 N/2의 조합을 찾는다
 *20C10 = 20! / 10! (20-10)! = 184,756 으로 연산량은 충분하다.
 *
 *
 *구해진 조합의 팀 점수비교는 브루트포스로 구하는 함수를 따로 작성한다.
 *
 *두명의 점수는 한번에 조회 가능하고 이것을 10C2만큼 모두 구하여 합해야 하므로
 *팀 1의 점수를 구하는데는 45의 비용이 소모된다
 *비교를 위해 팀2의 점수도 알아야 하므로 총 90의 비용이 소모되며
 *이것을 위에서 구해진 184,756과 곱하면
 *
 *16,628,040 의 비용이 소모된다.
 *
 *여기에 위에 백트래킹으로 만들어진 팀을 배열로 만드는 작업이 필요하다.
 *20명 기준 10개를 넣는 작업이 필요하므로,(팀A는 이미 구해져 있다.)
 *166,280,400의 비용이 소모된다. (N이 최대값인 경우)
 *
 *
 */



#include <iostream>
#include <vector>

using namespace std;

int BoardOfStatus[21][21]{};
int Size = 0;
bool Visit[21]{};
int MinResult = 1234567890;

int CalcScore(int const IndexOfA, int const IndexOfB)
{
	return BoardOfStatus[IndexOfA - 1][IndexOfB - 1] + BoardOfStatus[IndexOfB - 1][IndexOfA - 1];
}

int TeamScore(vector<int> const& Team)
{
	int Result = 0;
	for (int first = 0; first < Team.size(); first++)
	{
		for (int second = first + 1; second < Team.size(); second++)
		{
			Result += CalcScore(Team[first], Team[second]);
		}
	}
	return Result;
}



void Push(vector<int>& SelectedTeam, int const NumOfTarget)
{
	Visit[NumOfTarget] = true;
	SelectedTeam.push_back(NumOfTarget);
}

void Pop(vector<int>& SelectedTeam, int const NumOfTarget)
{
	Visit[NumOfTarget] = false;
	SelectedTeam.pop_back();
}

void BackTracking(vector<int>& SelectedTeam, int const StartNum)
{
	if (SelectedTeam.size() == Size / 2)
	{
		vector<int>TeamNotSelected{};
		for (int i = 1; i <= Size; i++)
		{
			if (Visit[i] == false)
			{
				TeamNotSelected.push_back(i);
			}
		}
		MinResult = min(MinResult, abs(TeamScore(SelectedTeam) - TeamScore(TeamNotSelected)));
		return;
	}

	for (int i = StartNum; i <= Size; i++)
	{
		Push(SelectedTeam, i);
		BackTracking(SelectedTeam, i + 1);
		Pop(SelectedTeam, i);
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			cin >> BoardOfStatus[y][x];
		}
	}
	vector<int> Temp{};
	BackTracking(Temp, 1);
	cout << MinResult;

	return 0;
}