/*
 * 10825 - ������
 *
 * ������ �䱸���״�� �ڷ����� ����� �����Ѵ�.
 *
 * sort�� ����� �� ������ �Լ��� �����ε��Ͽ� �����ߴ�.
 *
 * ���� �䱸������ �ݿ��Ǵ� ���Ĺ����� ��� �� Ǯ �� �ִ��� ����� ����
 *
 * ù ����(���� ū �ڷ����� ������)���� �����ϴ� ������ �ɷ������Ƿ�
 * ��������(greater<>)���� ������ ������ ���ǰ� ��ġ�ϵ��� �����ߴ�.
 * (Operator�� >�� ù �б� ������ <�� �ݴ밡 �ȴٸ� ����ڰ� �򰥸��� ����.)
 * (������ Operator�� >�� ù �б� ������ >�� ��ġ��Ű��,
 * ������ ������ �����ϴ� ������ �������� ����� ���� �����ϵ��� �����Ѵ�.)
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;



struct Data
{
	string Name;
	int ScoreOfKorean;
	int ScoreOfEnglish;
	int ScoreOfMath;
};

bool operator>(Data const& Left, Data const& Right)
{
	if (Left.ScoreOfKorean == Right.ScoreOfKorean)
	{
		if (Left.ScoreOfEnglish == Right.ScoreOfEnglish)
		{
			if (Left.ScoreOfMath == Right.ScoreOfMath)
			{
				return Left.Name < Right.Name;
			}

			return Left.ScoreOfMath > Right.ScoreOfMath;
		}

		return Left.ScoreOfEnglish < Right.ScoreOfEnglish;
	}

	return Left.ScoreOfKorean > Right.ScoreOfKorean;
}

bool operator<(Data const& Left, Data const& Right)
{
	if (Left.ScoreOfKorean == Right.ScoreOfKorean)
	{
		if (Left.ScoreOfEnglish == Right.ScoreOfEnglish)
		{
			if (Left.ScoreOfMath == Right.ScoreOfMath)
			{
				return Left.Name > Right.Name;
			}

			return Left.ScoreOfMath < Right.ScoreOfMath;
		}

		return Left.ScoreOfEnglish > Right.ScoreOfEnglish;
	}

	return Left.ScoreOfKorean < Right.ScoreOfKorean;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<Data> InputDatas{  };
	int InputCount = 0;
	cin >> InputCount;

	while (InputCount--)
	{
		Data Input{};
		cin >> Input.Name >> Input.ScoreOfKorean >> Input.ScoreOfEnglish >> Input.ScoreOfMath;

		InputDatas.push_back(Input);
	}
	sort(InputDatas.begin(), InputDatas.end(), greater<>());


	for (Data const& Elem : InputDatas)
	{
		cout << Elem.Name << "\n";
	}
	return 0;
}