/*
 *14888 - 연산자 끼워넣기
 *
 * 연산자 우선순위를 무시하고 입력받은 숫자 순서대로 계산한다는 것이 특징이다.
 *
 *입력받은 연산자의 갯수를 하나씩 줄여나가면 백트래킹으로 접근했다.
 *
 *되돌아오는 시점에 연산자의 갯수도 돌려줘야 함을 잊지 말자
 *
 *백트래킹의 종료시점에는 Min과 Max변수를 만들어 각각 비교해준다.
 *
 *전체 연산지 종료된 후 위의 두 변수를 출력한다.
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;


enum class NumberOfOperator
{
	Plus = 0, Minus, Multiply, Divide,
};
vector<int>NumberOfInputs{};
int OperatorCount[4]{};	//+,-,x,/
int N = 0;
int ResultOfMax = -1000000000, ResultOfMin = 1000000000;


int Push(int const InputOp, int const CurrentResult, int const NextNum)
{
	OperatorCount[InputOp]--;
	switch (static_cast<NumberOfOperator>(InputOp))
	{
	case NumberOfOperator::Plus:
	{
		return CurrentResult + NextNum;
	}
	case NumberOfOperator::Minus:
	{
		return CurrentResult - NextNum;
	}
	case NumberOfOperator::Multiply:
	{
		return CurrentResult * NextNum;
	}
	case NumberOfOperator::Divide:
	{
		return CurrentResult / NextNum;
	}

	}
	return 0;
}

void Pop(int const InputOp)
{
	OperatorCount[InputOp]++;
}

//다음 계산될 번호의 Index, 이전까지의 계산 결과(처음 호출시는 첫 수)
void BackTracking(int Index, int CurrentResult)
{
	if (Index == N)
	{
		ResultOfMax = max(ResultOfMax, CurrentResult);
		ResultOfMin = min(ResultOfMin, CurrentResult);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (OperatorCount[i] > 0)
		{
			//push and release
			int const NextResult = Push(i, CurrentResult, NumberOfInputs[Index]);
			BackTracking(Index + 1, NextResult);
			Pop(i);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int Input = 0;
		cin >> Input;
		NumberOfInputs.push_back(Input);
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> OperatorCount[i];
	}

	BackTracking(1, NumberOfInputs[0]);

	cout << ResultOfMax << "\n";
	cout << ResultOfMin << "\n";
	return 0;
}