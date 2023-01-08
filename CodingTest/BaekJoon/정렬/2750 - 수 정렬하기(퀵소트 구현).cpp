/*
 * 2750 - �� �����ϱ�(����Ʈ ����)
 *
 * ����Ʈ�� �̿��� �����ߴ�.
 *
 * �ǹ��� �������� �����ǵ��� �����ߴ�.
 *
 *23. 01. 08 ���ø����� �ۼ�
 *�ǹ��� ���� 3�� ������ �߰����� ��� �ش� ���� �迭�� �߰����� �����Ѵ�.
 * ���ø����� �ۼ�
 */

#include <iostream>
#include <time.h>
#include <string>

using namespace std;

template<typename T>
T FindMidValue(T const & A, T const & B, T const & C)
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
	char Arr[1000]{};	//T

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	QuickSort<char>(Arr, N);		//T
	for (int i = 0; i < N; i++)
		cout << Arr[i] << "\n";

	return 0;
}