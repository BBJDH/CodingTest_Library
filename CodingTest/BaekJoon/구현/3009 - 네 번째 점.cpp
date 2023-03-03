/*
 *3009 - �� ��° ��
 *
 *X��ǥ�� �ѹ��� �Է¹��� ������
 *
 *Y��ǥ�� �ѹ��� �Է¹��� ������ ������ָ� �ȴ�
 *
 *���簢���̱� ������ 4���� X�� Y ��ǥ�� 2�� �̻� �����ؾ� ���� ��Ģ�̴�
 *
 *������ 1000�����̱� ������ �迭�� 1001�� �����
 *�Է¹��� ���� ���Ͽ� ++ó���� �ѵ� �� ���� �ٽ� Ȯ���Ͽ� 1���� ���� ���� ����ϴ� ����� �ִ�
 *
 *������ ���� ���� ����ū ���� 1000�� ������ 1�̶�� 1000���� ��� Ȯ���غ��� �ϴ� ����� ���
 *
 *������ �Է¹޴� ���� 3���� �����ǹǷ� map���� �Է¹޴� ������ ī���� �ߴ�.
 *
 *
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	map<int, int> CoodX{};
	map<int, int> CoodY{};

	for (int i = 0; i < 3; i++)
	{
		int X = 0, Y = 0;
		cin >> X >> Y;
		CoodX[X]++;
		CoodY[Y]++;
	}
	for (pair<int, int> const& elem : CoodX)
	{
		if (elem.second == 1)
		{
			cout << elem.first;
			break;
		}
	}
	cout << " ";
	for (pair<int, int> const& elem : CoodY)
	{
		if (elem.second == 1)
		{
			cout << elem.first;
			break;
		}
	}


	return 0;
}