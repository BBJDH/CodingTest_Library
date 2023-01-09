/*
 * 11004 - K번째 수(퀵소트 구현)
 *
 * 퀵소트를 이용해 구현했다.
 *
 * 피벗은 랜덤으로 선정되도록 구현했다.

 */

#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;
int Arr[5000000]{};	//T

template<typename T>
T FindMidValue(T const& A, T const& B, T const& C)
{
	//자료형 T에 대해 A B C 중 가운데 값을 반환
	if (A >= B)
	{
		if (B >= C)
			return B;
		if (A <= C)
			return A;
		return B;
	}

	if (C < A)
		return A;
	if (B > C)
		return C;

	return B;
}

template<typename T>
void QuickSort(T* const Target, int const Size)
{
	if (Size <= 1)
		return;
	//가웃데 값 추정, 피벗으로 선정한다.
	T const pivot = FindMidValue<T>(Target[rand() % Size], Target[rand() % Size], Target[rand() % Size]);
	//T const pivot = Target[Size/2];
	//T const pivot = Target[rand() % Size];
	int left = 0;
	int right = Size - 1;

	while (left <= right)
	{
		while (Target[left] < pivot) left++;
		while (Target[right] > pivot) right--;
		if (left <= right)
		{
			swap(Target[left], Target[right]);
			left++;
			right--;
		}
	}

	QuickSort<T>(Target, right + 1);	//왼쪽 범위
	QuickSort<T>(&Target[left], Size - left);	//오른쪽 범위
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0;
	int printIndex = 0;
	cin >> N >> printIndex;
	printIndex--;
	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	QuickSort<int>(Arr, N);		//T
	//sort(Arr, &Arr[N]);
	cout << Arr[printIndex];
	return 0;
}