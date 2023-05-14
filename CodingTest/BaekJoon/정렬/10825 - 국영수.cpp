/*
 * 10825 - 국영수
 *
 * 문제의 요구사항대로 자료형을 만들고 정렬한다.
 *
 * sort가 사용할 비교 연산자 함수를 오버로딩하여 구현했다.
 *
 * 여러 요구사항이 반영되는 정렬문제를 어떻게 잘 풀 수 있는지 물어보는 문제
 *
 * 첫 조건(가장 큰 자료형이 갈리는)에서 감소하는 조건이 걸려있으므로
 * 오름차순(greater<>)으로 지정시 문제의 조건과 일치하도록 구성했다.
 * (Operator의 >와 첫 분기 조건이 <로 반대가 된다면 사용자가 헷갈리기 쉽다.)
 * (때문에 Operator의 >와 첫 분기 조건을 >로 일치시키고,
 * 문제의 조건인 감소하는 정렬은 오름차순 명령을 통해 동작하도록 구성한다.)
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