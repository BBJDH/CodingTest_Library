 /*
2581 - 소수

에라토스테네스의 체를 이용,
숫자 범위는 모두 10000보다 작은 자연수이므로 배열크기는 10001로 선정
먼저 에라토스테네스의 체를 시행

시작수, 끝수를 입력 받음

*/

#include<iostream>
#include<bitset>

using namespace std;

bitset<10001> EratosthenesNum{};
int StartNum = 0, EndNum = 0;

void Check_NonPrimeNum()
{
	EratosthenesNum.set();
	EratosthenesNum[0] = EratosthenesNum[1] = false;
	//1은소수가 아니다
	for (int i = 2; i * i < 10001; i++)
	{
		if (EratosthenesNum[i])
		{
			for (int mul = 2; i * mul < 10001; mul++)
				EratosthenesNum[i * mul] = false;
		}
	}
}

void Solution()
{
	int Sum = 0;
	int MinPrimnum = 0;
	for (int i = StartNum; i <= EndNum; i++)
	{
		if (EratosthenesNum[i])
		{
			if (MinPrimnum == 0)
				MinPrimnum = i;
			Sum += i;
		}
	}
	if (Sum == 0)
	{
		cout << -1;
		return;
	}
	cout << Sum << "\n" << MinPrimnum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Check_NonPrimeNum();
	cin >> StartNum >> EndNum;
	Solution();
	return 0;
}
