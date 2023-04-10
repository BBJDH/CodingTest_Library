/*
 *
 * 1009 - 분산처리
 *
 *
 *문제의 특성상 컴퓨터는 10대이고
 *지수로 기입되는 결과 수를 10대의 컴퓨터가 번갈아 처리한다
 *
 *즉 결과수 % 10을 통해 0은 10번, 1은 1번, 2는 2번... 으로 처리된다.
 *
 *2의 제곱수로 보면
 *
 *1 2 3 4  5  6   7   8
 *2 4 8 16 32 64 128 256
 *2 4 8 6  2  4   8   6
 *이렇게 일의 자리 구간이 반복되어 나타난다(구간의 길이가 달라질 뿐 다른수도 모두 동일하다.)
 *반복되는 구간의 크기를 찾아 %연산으로 일의자리를 유추 가능하다. (9%4 => 1이므로 일의자리는 2이다)
 *
 *
 *
 *이제 이것을 어떻게 찾아서 기록하느냐가 관건이다.
 *어떤 지수가 들어와도 일의 자리의 갯수는 0~ 10으로 동일하고 이 구간은 반복된다.
 *따라서 반복되는 구간은 반드시 10보다 작다
 *그러므로 배열 크기를 10개로 잡고 지수를 인덱스로 하여 구해진 일의 자리를 기록한다.
 *위와 같이 지수를 증가시켜 나가며 %10을 통해 나타나는 수를 배열에 기록한다.
 *(1부터 중복이 나타날때 까지 지속한다. 인덱스는 해당 지수가 된다)
 *
 *즉 2의 지수
 *1 2 3 4  5  6   7   8
 *2 4 8 16 32 64 128 256
 *2 4 8 6  2  4   8   6
 *
 *를 진행한다면
 *DP[1] = 2;
 *DP[2] = 4;
 *DP[3] = 8;
 *DP[4] = 6;
 *
 *이 기록되고 다음 수 5에서 2가 다시 등장하므로 여기서 정지된다.
 *즉 크기는 4로 알게되고 앞으로 등장하는 수는 %4를 통해 알 수 있게 된다.
 *하지만 여기서 4의 경우는 4%4 는 0으로 DP[4]를 접근할 수 없으므로
 *지수%반복 크기가 0인경우 DP[최대반복크기]에 접근토록 처리한다.
 *
 *이때 주의할점은 10의 2승을 생각해보자
 *
 *DP[1] = 10 으로 기록되어야 한다
 *하지만 10 % 10은 0이기 때문에 0이 출력된다.
 *0은 10번 컴퓨터를 의미하기 때문에 %10이 0이된경우를 10으로 만들어준다.
 *
 *
 *등장하는 수를 체크하는것은 이진탐색을 통해 찾아줄 수도 있지만
 *반복문을 통해 O(N)으로 최악의 경우를 생각해도(10번 기록하고 찾게 되는 경우) 10*10 = 100의 비용이 들게되므로
 *반복문으로 비교해 주었다.
 *(이진 탐색을 사용하고 싶다면 lower_bound로 해당수가 찾아졌는지 확인해주면 된다.)
 *
 *
 *혹시나해서 그냥 구현으로 풀이가 가능한지 확인해봤다 속도는 0에서 800ms로 늘어난 것을 확인했다.
 *
 *
 */


#include <iostream>

using namespace std;


bool IsValidNum(int const* const ExponentToComputer, int const TargetNum, int const Size = 10)
{
	for (int i = 1; i < Size; i++)
	{
		if (ExponentToComputer[i] == TargetNum)
		{
			return true;
		}
	}
	return false;
}

void JustImplementation(int const InputNum, int const Exponent)
{
	int NumOfComputer = 0;
	NumOfComputer = InputNum % 10;
	for (int i = 2; i <= Exponent; i++)
	{
		NumOfComputer = (NumOfComputer * InputNum) % 10;
	}
	if (NumOfComputer == 0)
	{
		//0은 10번 컴퓨터를 의미
		NumOfComputer = 10;
	}
	cout << NumOfComputer << "\n";
}

void UseDPArray(int const InputNum, int const Exponent)
{
	int ExponentToComputer[10]{};
	int NumOfComputer = 1;
	int CurrentExp = 1;

	while (true)
	{
		//컴퓨터 번호 정하기
		NumOfComputer = (NumOfComputer * InputNum) % 10;
		if (NumOfComputer == 0)
		{
			NumOfComputer = 10;
		}

		//중복 체크
		if (IsValidNum(ExponentToComputer, NumOfComputer) == true)
		{
			break;
		}

		//배열에 기록
		ExponentToComputer[CurrentExp] = NumOfComputer;
		CurrentExp++;
	}

	int const LoopNum = CurrentExp - 1;

	int IndexOfResult = Exponent % LoopNum;

	//0이면 DP[반복구간]에 접근하도록 처리
	if (IndexOfResult == 0)
	{
		IndexOfResult = LoopNum;
	}

	cout << ExponentToComputer[IndexOfResult] << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{

		int Num = 0, Exponent = 0;
		cin >> Num >> Exponent;
		//JustImplementation(Num, Exponent);
		UseDPArray(Num, Exponent);
	}

	return 0;
}