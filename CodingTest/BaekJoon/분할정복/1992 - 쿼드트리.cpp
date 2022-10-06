/*

1992 - 쿼드트리

4 4
0 0 2 2  start -> end/2
2 0 4 2
0 2 2 4
2 2 4 4
		4 4 8 8
		6 4 8 6
		4 6 6 8
		6 6 8 8

영상을 4등분해서 쪼개나가며,
출력 순서는 왼위 오른위 왼아래 오른아래 순의 출력 순서를 맞춰준다

더이상 쪼갤 수 없는 단위에 도달하면 해당 한개 원소의 값을 문자열로 리턴,
취합된 문자열이 0000 혹은 1111이라면 0, 1로 압축해서 반환한다
만약 압축 불가라면 이후로도 압축이 불가능하므로 ()로 묶어서 반환

*/
#include<iostream>
#include<string>

using namespace std;
struct _int2
{
	int X;
	int Y;
};

int Arry[64][64]{};
int Size = 0;


string Solution(_int2 const& StartPos, _int2 const& EndPos)
{

	string SumStr{};
	if (abs(StartPos.X - EndPos.X) == 1 and abs(StartPos.Y - EndPos.Y) == 1)
		return to_string(Arry[StartPos.Y][StartPos.X]);

	_int2 CenterPos = { StartPos.X + (EndPos.X - StartPos.X) / 2, StartPos.Y + (EndPos.Y - StartPos.Y) / 2 };

	SumStr += Solution(StartPos, CenterPos);
	SumStr += Solution({ CenterPos.X, StartPos.Y }, { EndPos.X, CenterPos.Y });
	SumStr += Solution({ StartPos.X, CenterPos.Y }, { CenterPos.X, EndPos.Y });
	SumStr += Solution(CenterPos, EndPos);

	if (SumStr == "1111")
		return "1";
	else if (SumStr == "0000")
		return "0";
	return "(" + SumStr + ")";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	for (int Y = 0; Y < Size; Y++)
	{
		string InputNums{};
		cin >> InputNums;
		for (int X = 0; X < Size; X++)
		{
			Arry[Y][X] = stoi(InputNums.substr(X, 1), nullptr, 10);
		}
	}
	string Result = Solution({ 0,0, }, { Size ,Size });
	cout << Result;
	return 0;
}
