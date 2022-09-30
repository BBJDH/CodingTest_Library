#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
1463 - 1로 만들기
수를 1,000,000 까지 입력받으므로
번호를 인덱스로 하는 배열백만개+1를 설정
인덱스는 해당번호, 배열의 값은 계산된 값으로 표기한다
N부터 시작, 2까지 계산
각 인덱스에대해서 기존 계산값이 0이라면 이전에 나온 숫자가 아니므로 넘어감
배열참조값이 1이상으로 유효하다면
123연산을 시행
연산 된 번호의 참조값이 0이라면 업데이트, 값이 존재한다면 두값을 비교해 더 적은값을 유지
*/
vector<int> NumsCalcCount{};

void Calc(int const DestIndex, int const CurrentCalcCount)
{
	if (NumsCalcCount[DestIndex] == 0)
		NumsCalcCount[DestIndex] = CurrentCalcCount + 1;
	else
		NumsCalcCount[DestIndex] = min(CurrentCalcCount + 1, NumsCalcCount[DestIndex]);
}


void SelectNum(int const Num_Index)
{
	if (Num_Index % 3 == 0)
		Calc(Num_Index / 3, NumsCalcCount[Num_Index]);
	if (Num_Index % 2 == 0)
		Calc(Num_Index / 2, NumsCalcCount[Num_Index]);
	Calc(Num_Index - 1, NumsCalcCount[Num_Index]);

}

int main()
{
	int StartNum = 0;

	scanf("%d", &StartNum);
	NumsCalcCount.resize(StartNum + 1);	 //편의상 번호와 1대1 매핑을 위해 1개 추가
	SelectNum(StartNum);
	for (int i = StartNum; i > 1; i--)
	{
		//계산된번호가 아닌경우에는 지나감
		if (NumsCalcCount[i])
			SelectNum(i);
	}
	printf("%d", NumsCalcCount[1]);
	return 0;
}
