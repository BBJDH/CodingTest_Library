/*
 *
 *1620 - ���¾� ���ϸ� ������ �̴ټ�
 *
 *N���� �Է¹��� ���ڿ��� Ű��, ��ȣ�� value�� �ϴ� �ʿ� ����
 *�׸��� �ݴ�ε� value(int)�� index��, ���ڿ��� �迭�� ������ �ϴ� �迭���� ���� ���� �� ��
 *
 *M���� ���� ���ڿ��� ���Ͽ�
 *
 *ù���ڰ� '9'���� ũ�ٸ� �ش繮�ڿ��� ���� �̸��ΰ����� Ȯ��,
 *
 *���ʹ� �ʿ���
 *
 *��ȣ�� �迭���� ������ ����� �ش�.
 *
 */

#include <iostream>
#include <map>
#include <string>


using namespace std;

string NumByMonster[100001]{};
map<string, int>MonsterByNum{};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string inputStr{};

		cin >> inputStr;

		MonsterByNum[inputStr] = i;
		NumByMonster[i] = inputStr;
	}

	for (int i = 0; i < M; i++)
	{
		string inputStr{};

		cin >> inputStr;
		if (inputStr[0] > '9')
		{
			//���� ó��
			cout << MonsterByNum[inputStr] << "\n";
		}
		else
		{
			cout << NumByMonster[stoi(inputStr)] << "\n";
		}
	}
	return 0;

}