/*
 * 15700 - Ÿ�� ä��� 4
 *
 *������ ��Ģ���� ����������
 *
 *int �����÷ο츦 ����� �����̱⵵ �ϴ�.
 *
 *���� ������ �ذ�����
 *N�� M�� ���ϸ� ������ ĭ ���� ������
 *�̰��� 2�� ������(Ÿ���� ũ�Ⱑ 2�̹Ƿ�) �ش��� ã�� �� �ִ�.
 *
 *������ N�� M�� 10���� �ʰ����� �����ؾ��Ѵ�.
 *
 *���⼭ NxM�� ���� ������ longlong���� �����ؼ��� �ȵȴ�
 *
 *NxM�� ����� ���ϱ� ������ N�� ȣ���Ͽ� N�� ��������Ƿ�
 *
 *M�� int���� ������ ������� ��� �޴� N�� long long�̾�� �Ѵ�.
 */


#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int M = 0;
	long long N = 0;
	long long NumberOfCells = 0;

	cin >> N >> M;

	NumberOfCells = N * M;
	cout << NumberOfCells / 2;

	return 0;
}