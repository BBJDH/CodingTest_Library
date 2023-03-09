/*
 *14889 - ��ŸƮ�� ��ũ
 *
 *�Է� ���� �迭
 *
 *���� A�� B�� ����� �ɷ�ġ�� �迭�� ���� �ѹ��� ��ȸ �����ϴ�.
 *ó���� ������ �ǹ� ������ �ƴ϶�� ��޶����� �ο������� �����ο� Ǯ�̰� ��ư� ��������
 *
 *�ο��� N/2�� �����̴�.
 *
 *���� ��Ʈ��ŷ���� N/2��ŭ�� ������ �����Ѵ�.
 *�������.. ���չ����� ������ ��Ʈ��ŷ....
 *
 *N���� ������� N/2�� ������ ã�´�
 *20C10 = 20! / 10! (20-10)! = 184,756 ���� ���귮�� ����ϴ�.
 *
 *
 *������ ������ �� �����񱳴� ���Ʈ������ ���ϴ� �Լ��� ���� �ۼ��Ѵ�.
 *
 *�θ��� ������ �ѹ��� ��ȸ �����ϰ� �̰��� 10C2��ŭ ��� ���Ͽ� ���ؾ� �ϹǷ�
 *�� 1�� ������ ���ϴµ��� 45�� ����� �Ҹ�ȴ�
 *�񱳸� ���� ��2�� ������ �˾ƾ� �ϹǷ� �� 90�� ����� �Ҹ�Ǹ�
 *�̰��� ������ ������ 184,756�� ���ϸ�
 *
 *16,628,040 �� ����� �Ҹ�ȴ�.
 *
 *���⿡ ���� ��Ʈ��ŷ���� ������� ���� �迭�� ����� �۾��� �ʿ��ϴ�.
 *20�� ���� 10���� �ִ� �۾��� �ʿ��ϹǷ�,(��A�� �̹� ������ �ִ�.)
 *166,280,400�� ����� �Ҹ�ȴ�. (N�� �ִ밪�� ���)
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