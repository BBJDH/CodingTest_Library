/*
 *1037 - 약수
 *
 *입력 받은수의 가장 큰수와 가장 작은수의 곱을 통해 배수를 출력한다.
 *
 *수를 모두 입력받아 정렬을 틍해 접근할 수도 있지만,
 *
 *정렬을 사용하지않고 입력받으면서 min, max 비교를 통해
 *수를 저장하여 결과를 출력토록 했다.
 *
 *예외로 수를 한개만 입력받은 경우 가장 낮은 배수인 2를 곱해주는 작업을 시행하였으나.
 *
 *이 처리가 없어도 무방하다 그냥 int범위를 초과하지 않는 배수조건만 성립하면 되는 문제였다.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0, LargestNumber = 0, SmallestNumber = 1000001;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		LargestNumber = max(LargestNumber, InputNum);
		SmallestNumber = min(SmallestNumber, InputNum);
	}
	if (SmallestNumber == 1000001)
		SmallestNumber = 2;
	cout << LargestNumber * SmallestNumber;
	return 0;
}