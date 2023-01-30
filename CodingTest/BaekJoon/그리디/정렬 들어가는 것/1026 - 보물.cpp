/*
 *1026 - ����
 *
 *������ �䱸���׸� �� �ĺ��� ����
 *
 *��Ģ�� B �迭�� �����̸� �ȵȴٰ� ������
 *�ᱹ �䱸�ϴ� ���� �ּҰ� S�̴�.
 *
 *������ A�� B�迭�� ������� ���������� ������ ���ظ� �����ص� �Ǵ� ���̴�.
 *
 * ���� ������ �ٽ� ������ ����,
 * �ᱹ �� ���� �ּҰ��� ������ ���س����� �ȴ�.
 *
 * �ּҰ��� ��� �������°�?
 * ���� �迭�� ���� ū���� ������ �迭�� ���� ���� ���� ���̴�
 * ��, ������ ��������, �ٸ� ������ ������������ �����ϰ�
 * �ݺ��� N���� ���Ͽ� ������ ���� ����ϸ� �ذ�ȴ�.
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