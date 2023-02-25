/*
 *14888 - ������ �����ֱ�
 *
 * ������ �켱������ �����ϰ� �Է¹��� ���� ������� ����Ѵٴ� ���� Ư¡�̴�.
 *
 *�Է¹��� �������� ������ �ϳ��� �ٿ������� ��Ʈ��ŷ���� �����ߴ�.
 *
 *�ǵ��ƿ��� ������ �������� ������ ������� ���� ���� ����
 *
 *��Ʈ��ŷ�� ����������� Min�� Max������ ����� ���� �����ش�.
 *
 *��ü ������ ����� �� ���� �� ������ ����Ѵ�.
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

//���� ���� ��ȣ�� Index, ���������� ��� ���(ó�� ȣ��ô� ù ��)
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