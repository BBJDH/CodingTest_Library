/*
 * 11004 - K��° ��(����Ʈ ����)
 *
 * ����Ʈ�� �̿��� �����ߴ�.
 *
 * �ǹ��� �������� �����ǵ��� �����ߴ�.

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
	//�ڷ��� T�� ���� A B C �� ��� ���� ��ȯ
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
	//������ �� ����, �ǹ����� �����Ѵ�.
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

	QuickSort<T>(Target, right + 1);	//���� ����
	QuickSort<T>(&Target[left], Size - left);	//������ ����
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