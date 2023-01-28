/*
 *10815 - ���� ī��
 *
 *���� ������ ũ�Ƿ� �迭�� �����Ͽ� üũ�Ҽ��� ����.
 *
 *������ ��������Ʈ���� �����ϴ� set�� �̿��Ͽ� ���� �˻��ϰ� �Ѵ�.
 *
 */

#include<iostream>
#include <set>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	set<int> CheckNums{};
	int N = 0, M = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int CheckNum = 0;
		cin >> CheckNum;
		CheckNums.insert(CheckNum);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		if (CheckNums.find(InputNum) != CheckNums.end())
		{
			cout << "1 ";
			continue;
		}
		cout << "0 ";
	}

	return 0;
}