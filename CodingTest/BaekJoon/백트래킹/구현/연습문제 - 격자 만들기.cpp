/*
 *
 *======================================
 *
 *�������� - ���� �����
 *
 *��Ʈ��ŷ �� ������ ���� Ǯ����.
 *
 *�� ��Ʈ��ŷ���� 0 ~3���� X������ ���
 *������ �ϳ��� ����߷� ���ο� ��Ʈ��ŷ�Ѵ�.
 *
 *����߸� ��ġ y���� (x�� ������ �����Ƿ�)�� ��ȯ�ϴ� �Լ��� �ۼ���
 *
 *�� x�� ���Ͽ� ���� ��ġ�� ���� ���ϰ�
 *
 *�ش� ��ġ�� ������ ����� �������� Ÿ�� vector<string> �� ��ġ�Ѵٸ�
 *
 *���� ��Ʈ��ŷ�� ���൵���Ѵ�.
 *
 *������ true�� ��ȯ�ϵ��� �Ͽ� �Լ��� �����Ű��
 *
 *��� �����ϰ� �Լ��� ����ȴٸ� false ��ȯ�ϵ��� �Ͽ� 1�� 0���� �����Ͽ�
 *
 *����Ѵ�.
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int GetY(vector<string> const& Current, int X)
{
	int Result = -1;
	for (int y = 3; y >= 0; y--)
	{
		if (Current[y][X] == '-')
		{
			Result = y;
			break;
		}
	}
	return Result;
}

bool BackTracking(vector<string> const& Target, vector<string> &Current, char Block = 'o')
{
	int Result = 0;
	for (int i = 0; i < 4; i++)
	{
		if (Target[i] == Current[i])
		{
			Result++;
		}
	}

	if (Result == 4)
	{
		return true;
	}


	//0~3 ������ ���� �õ�
	bool IsSucceed = false;
	for (int X = 0; X < 4; X++)
	{
		//����
		int const Y = GetY(Current, X);

		if (Y == -1)
		{
			continue;
		}

		if (Target[Y][X] == Block)
		{
			Current[Y][X] = Block;
			if (Block == 'o')
			{
				IsSucceed |= BackTracking(Target, Current, 'x');
			}
			else
			{
				IsSucceed |= BackTracking(Target, Current, 'o');
			}
			Current[Y][X] = '-';
		}

	}


	return IsSucceed;
}

vector<int> solution(vector<vector<string>> boards)
{
	vector<int> answer{};
	vector<string> Start = { "----","----" , "----" , "----" };
	for (vector<string> const Board : boards)
	{

		if (BackTracking(Board, Start) == true)
		{
			answer.push_back(1);
		}
		else
		{
			answer.push_back(0);
		}
	}
	for (int const elem : answer)
		cout << elem << " ";
	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	//solution({ { "----","----" , "----" , "----" } });
	solution({ { "----", "----", "-o--", "-xo-"},{"---o", "---x", "---x", "---o" } });
	//solution({{ "----","----" , "--x-" , "--o-" },
	//	{ "----","----" , "----" , "--oo" }
	//	, { "----","----" , "----" , "x-o-" } });

	//Solution({{ "ooxx","xxxx" , "xxoo" , "oooo" },
	//{ "o---","----" , "----" , "----" }
	//, { "----","----" , "xxxx" , "xoox" } });

	return 0;
}
