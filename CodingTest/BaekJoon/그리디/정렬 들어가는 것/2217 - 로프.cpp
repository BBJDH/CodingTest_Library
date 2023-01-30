/*
 *2217 - ����
 *
 *��Ģ�� ã�ƺ���,
 *15, 10, 9, 8, 3 �� �������� �־����� ��,
 *���� �� ���������� ������ ���߾� �ִ� �߷��� Ȯ���Ѵ�. ��
 *15�� ��� �ִ� ���Դ� 15
 *15, 10���� �� �� �ִ� ���Դ� 20
 *15, 10, 9�� �� �� �ִ� ���Դ� 27
 *15, 10, 9, 8�� �� �� �ִ� ���Դ� 32
 *15, 10, 9, 8, 3�� �� �� �ִ� ���Դ� 15
 *
 *�� ������ ���� ���� ���� 32��,
 *4���� ������ �� �� �ִ� 32�̴�
 *
 *�� �����ϸ�,
 *�־��� �������� ������������ �����ϰ�
 *���� �� ������ �ش� ������ ������ max ����� �ϸ� �ȴ�.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> Rope{};
	int N = 0, MaxResult = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputRope = 0;
		cin >> inputRope;
		Rope.push_back(inputRope);
	}
	sort(Rope.begin(), Rope.end(), greater<>());

	for (int i = 0; i < N; i++)
	{
		MaxResult = max(MaxResult, Rope[i] * (i + 1));
	}
	cout << MaxResult;

	return 0;
}