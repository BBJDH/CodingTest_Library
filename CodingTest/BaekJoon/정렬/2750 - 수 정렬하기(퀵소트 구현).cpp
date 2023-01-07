/*
 *
 * 2750 - 수 정렬하기(퀵소트 구현)
 *
 * 퀵소트를 이용해 구현했다.
 *
 * 피벗은 랜덤으로 선정되도록 구현했다.
 *
 */

#include <iostream>
#include <time.h>

using namespace std;

void QuickSort(int* const Target, int const Size)
{
	if (Size <= 1)
		return;

	int pivot = rand() % Size;
	int const targetNum = Target[pivot];
	int left = 0;
	int right = Size - 1;

	while (left <= right)
	{
		while (Target[left] < targetNum) left++;
		while (Target[right] > targetNum) right--;
		if (left <= right)
		{
			swap(Target[left], Target[right]);
			left++;
			right--;
		}
	}
	QuickSort(Target, right + 1);
	QuickSort(&Target[left], Size - left);
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int Arr[1000]{};

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	QuickSort(Arr, N);
	for (int i = 0; i < N; i++)
		cout << Arr[i] << "\n";

	return 0;
}