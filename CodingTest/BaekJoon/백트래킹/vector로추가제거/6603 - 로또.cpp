/*
 *6603 - �ζ�
 *
 *�Ѵ޸��� ��Ʈ��ŷ������ Ǯ�Եƴ�.
 *
 *��Ҷ�� Limit�� ���������� Visit ó���� ���� 1���� �������
 *
 *true�� ����ص� ������,
 *
 *�̹����� ��Ʈ��ŷ �Լ��� ���� �迭�� �����Ͽ� �߰� ���Ÿ� ���� ����ϰ� �;���.
 *
 *�̷��� �ϸ� �̾��� �����迭 ���� 6���� ���� ����Ʈ�� �ؾ� �ϹǷ� nlogn �� �� 18������ ����� ���
 *
 *Visit�� ���ٸ� ������ �ʿ������ 50ũ�⸦ n���� ���� Ž���ϴ� ����� ���.
 *
 *�ٸ� �����迭�� �߰�/���Ÿ� �ݺ��ϸ� �Һ�Ǵ� ����� ��Ƿ� ���� ��Ȳ�� ���� ���Ѱ��� ���Ե� �� ����.
 *
 */



#include<iostream>
#include <vector>
#include <algorithm>
#define Limit 6

bool Visit[50]{};

using namespace std;

void BackTracking(vector<int> const& Lotto, vector<int> Print, int Index = 0)
{
	for (int i = Index; i < Lotto.size(); i++)
	{
		int newElem = Lotto[i];
		if (Visit[newElem] == false)
		{
			Visit[newElem] = true;
			Print.push_back(newElem);
			if (Print.size() == Limit)
			{
				sort(Print.begin(), Print.end());
				for (int const printElem : Print)
					cout << printElem << " ";
				cout << "\n";

			}
			BackTracking(Lotto, Print, i + 1);
			Visit[newElem] = false;
			Print.erase(Print.end() - 1);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true)
	{
		int size = 0;
		cin >> size;
		if (size == 0)
			return 0;
		vector<int> inputNums{};
		for (int i = 0; i < size; i++)
		{
			int inputNum = 0;
			cin >> inputNum;
			inputNums.push_back(inputNum);
		}
		vector<int> Print{};
		BackTracking(inputNums, Print);
		cout << "\n";

	}

	return 0;
}