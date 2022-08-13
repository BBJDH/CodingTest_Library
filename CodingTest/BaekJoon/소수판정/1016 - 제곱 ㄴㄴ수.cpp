#include<iostream>
#include<math.h>
#include<bitset>

using namespace std;

/*
max =10, min 1
최대 제곱수는 3
2~ max까지 최소 제곱수부터 최대 제곱수 까지 마킹 시작
1 2 3 5 6 7 10
*/

bitset<1000001> IsExist{};
//min + 1,000,000 이므로 +1이 필요하다 0~1,000,000 총 1,000,001의 비트가 필요한셈
long long Min = 0, Max = 0;
long long End = 0;// max에 대한 제곱근 최대 정수

/*
i는 2부터 시작, End까지 접근
제곱수로 나누어질 수 있는 최소의 수부터 찾아야 함
min을 i의 제곱으로 나눈 수 ShareNum 선정(만약 min이 작아서 몫이 0이라면 1로 지정)
반복문 진입 (해당 ShareNum에 대하여 +1증가하며 Max보다 작을때까지 해당 수를 마크)
{
}
*/
void MarkExist()
{
	for (long long i = 2; i <= End; i++)
	{
		long long ShareNum = (Min / (i * i));
		if (ShareNum * (i * i) < Min) ShareNum++;	//시작수가 Min보다 작다면 ShareNum 증가시키고 시작

		while (ShareNum * i * i <= Max)
		{
			//마킹은 ShareNum *i*i -  min으로 기록
			IsExist.set(ShareNum * i * i - Min);
			ShareNum++;
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Min >> Max;
	End = static_cast<int>(sqrt(Max));

	MarkExist();

	cout << static_cast<int>(Max - Min + 1 - IsExist.count());

	return 0;
}
