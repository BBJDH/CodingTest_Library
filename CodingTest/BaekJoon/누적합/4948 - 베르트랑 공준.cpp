/*
 *4948 - 베르트랑 공준
 *
 *에라토스테네스의 체를 이용해 소수 배열을 기록,
 *누적합 배열(DP)를 만들어 최대 수 까지의 소수 갯수를 저장
 *
 *입력받은 수에 따라 DP[i*2] - DP[i] 를 출력한다
 *
 *다른 방식도 가능하지만 다음 코드는 소수와 누적합을 이용해 풀어냈다.
 *
 */



#include <iostream>

using  namespace  std;

#define MAX 246913
bool PrimeNum[MAX]{};
int DP[MAX]{};

void MarkPrimNum()
{
	PrimeNum[0] = PrimeNum[1] = true;
	for (int i = 2; i * i < MAX; i++)
	{
		if (PrimeNum[i] == false)
		{
			for (int mul = 2; mul * i < MAX; mul++)
			{
				PrimeNum[i * mul] = true;
			}
		}
	}
}
void MakeDP()
{
	//누적합 생성
	int count = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (PrimeNum[i] == false)
			count++;
		DP[i] = count;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	MarkPrimNum();
	MakeDP();

	while (true)
	{
		int inputNum = 0;
		cin >> inputNum;
		if (inputNum == 0)
			break;
		cout << DP[inputNum * 2] - DP[inputNum] << "\n";

	}

	return 0;
}