/*
 *2441 - �� ��� - 4
 *
 *�� ������ ���� ������ ����Ѵٶ�� ������
 *0�� *�� ǥ���Ѵٸ�
 *
 * *****
 * 0****
 * 00***
 * 000**
 * 0000*
 *
 * �� ǥ�õȴ� �� ��ü �ݺ��� i�� �帧�� 0~ N-1�϶�
 * 0�� i��ŭ(0~N-1), *�� N-i����ŭ ��� ���� �ѱ�� �ȴ�.
 */

#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int space = 0; space < i; space++)
			cout << " ";
		for (int star = 0; star < N - i; star++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}