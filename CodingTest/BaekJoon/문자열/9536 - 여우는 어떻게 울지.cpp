/*

9536 - ����� ��� ����?

������ ������ �����Ұ��� ���� ����
���� �� �����鸶���� �����Ҹ��� �ʿ� ����
������ what does the fox say?�� �Ұ�
cin���� �Է¹����� \n�� ���������Ƿ� 	cin.ignore()�� ���� �ѹ���('\n')�� ������
getline(�Է½�Ʈ��, ������ ���ڿ�)�� �ٴ����� �о�´�

<sstream>����� stringstream ss(��Ʈ���� ����� ��� ���ڿ�)�� ����
getline(��Ʈ��,�Ľ̵ȹ��ڿ��� �����Ұ�, ���ع���)�� �Ľ�

���� ���ο� ������ �޴´ٸ� �ٽ� ��Ʈ���� �ʱ�ȭ
			ss.clear();
			ss.str(InputSound);	//���Ӱ� getline���� �޾ƿ� ��Ʈ���� �ٽ� ���

���� ���� �׽�Ʈ���̽� ��� �Էµ� �ڷ�� �ʱ�ȭ�� ���� ����

*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<sstream>
using namespace std;

vector <string> InputSounds{};	//���� �Ҹ� �ִ°�(�����Ȱ�)
set<string> AnimalSounds{};

void Solution()
{
	for (auto const& Elem : InputSounds)
	{
		if (AnimalSounds.end() == AnimalSounds.find(Elem))
			cout << Elem << " ";
	}
	cout << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;

	cin >> TestCase;
	cin.ignore();				//�տ��� �Է¹��� ���ۿ� \n�� ���������Ƿ� �����ش�
	string InputSound{ "" };

	while (TestCase--)
	{
		getline(cin, InputSound);
		stringstream ss(InputSound);
		while (getline(ss, InputSound, ' '))
		{
			InputSounds.push_back(InputSound);	//�Ҹ� ����
		}

		while (true)
		{
			getline(cin, InputSound);
			if (InputSound == "what does the fox say?")
			{
				Solution();
				AnimalSounds.clear();
				InputSounds.clear();
				break;
			}
			ss.clear();
			ss.str(InputSound);
			vector<string> Sounds{};
			while (getline(ss, InputSound, ' '))
			{
				Sounds.push_back(InputSound);
			}
			AnimalSounds.insert(Sounds[2]);
		}
	}
	return 0;
}
