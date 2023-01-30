/*
 *1026 - 보물
 *
 *문제의 요구사항만 잘 식별해 보자
 *
 *규칙은 B 배열을 움직이면 안된다고 하지만
 *결국 요구하는 것은 최소값 S이다.
 *
 *때문에 A와 B배열을 마음대로 움직여보고 문제의 정해만 도출해도 되는 것이다.
 *
 * 따라서 문제를 다시 접근해 보면,
 * 결국 두 수의 최소값을 만들어내서 합해나가면 된다.
 *
 * 최소값은 어떻게 정해지는가?
 * 한쪽 배열의 가장 큰값과 나머지 배열의 가장 작은 값의 곱이다
 * 즉, 한쪽은 오름차순, 다른 한쪽은 내림차순으로 정렬하고
 * 반복문 N으로 곱하여 누적한 값을 출력하면 해결된다.
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, Result = 0;;
	vector<int> A{};
	vector<int> B{};

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		A.push_back(inputNum);
	}
	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		B.push_back(inputNum);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	for (int i = 0; i < N; i++)
	{
		Result += A[i] * B[i];
	}
	cout << Result;
	return 0;
}