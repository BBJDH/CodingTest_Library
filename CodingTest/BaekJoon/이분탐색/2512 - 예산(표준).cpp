/*
 *2512 - 예산
 *
 *직접 이분탐색을 구현하여 해결했다.
 *
 *이진탐색 반복문을 가지는 BinarySearch 함수와
 *안에서 IsCorrect함수에 따라 성립한다면 Left를 좁혀오고(Mid 증가)
 *안에서 IsCorrent함수가 성립하지 못했다면 RIght를 좁혀온다(Mid 감소)
 *
 *최종 반복문에서 Left와 Right의 차이가 1일 때까지 탐색하여
 *찾아진 Left가 최적해
 *
 *
 */


#include <iostream>
#include <vector>

using namespace std;

bool IsCorrect(int const Mid, vector<int> const Target, int TotalInCome)
{
	//원하는 조건이 성립 하는지 검사

	for (int const Elem : Target)
	{


		if (Elem > Mid)
		{
			TotalInCome -= Mid;
		}
		else
		{
			TotalInCome -= Elem;
		}
	}
	if (TotalInCome < 0)
	{
		return false;
	}
	return true;
}


void BinarySearch(int const Start, int const End, vector<int> const Target, int const TotalInCome)
{
	//Left 와 Right 는 탐색 범위 밖으로 지정한다
	int Left = Start - 1;
	int Right = End + 1;
	int Mid = 0;			//Mid는 반복문 안에서 재설정

	while (Left + 1 < Right)
	{
		Mid = (Left + Right) / 2;
		if (IsCorrect(Mid, Target, TotalInCome))
		{
			Left = Mid;
		}
		else
		{
			Right = Mid;
		}
	}
	cout << Left;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	vector<int> City{};
	int NumOfCity = 0;
	int TotalInCome = 0;
	int End = 0;
	cin >> NumOfCity;
	while (NumOfCity--)
	{
		int InputNum = 0;
		cin >> InputNum;
		City.push_back(InputNum);
		End = max(End, InputNum);
	}
	cin >> TotalInCome;

	BinarySearch(1, End, City, TotalInCome);
	return 0;
}