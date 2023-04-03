/*
 *1406 - ������
 *
 *
 *std::string �� �̿��� insert�� erase�δ� �ذ�����ʴ´�
 *(�ð��ʰ� �߻�, �Է¹޴� ��ɾ� ������ 50�����̸� ���̴� 10������)
 *�Է¹޴� Command���� n�� ������ ���شٸ� 100���� ����� �Ҹ�ǹǷ� �ð��ʰ��� �߻��Ѵ�.
 *
 *���� ������ �̿��� ���� Ŀ���� ��ġ�� �߽����� ����� ó���س�����.
 *
 *Ŀ���� ������ ���� ���ڿ��� ������ ���ð�
 *������ �������� ������ �������� ������
 *
 *Ŀ���� �������� �̵��Ѵٸ� ���� ������ �̾� ���������� �̵� (����� 1 �Ҹ�ȴ�)
 *Ŀ���� �������̵��� ���������� ó���ϸ�,
 *���Žÿ��� ���� ���ÿ��� Pop ���길 ���ָ� �ȴ�(��� 1)
 *�߰��ÿ��� ���������� Left�� Top�� Push�ѹ����� ó�� ����������(��� 1)
 *
 *���� 50������ ����� �޾Ƶ� 50������ �������� ó�� �����ϴ�
 *
 *���� ����� ���� �������־�� �ϹǷ� ���� ������ ���������� ��� ���� ��
 *
 *����ϴ� ��������� �ʿ��ϴ� (�ִ� 10��)
 *
 *
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string Inputstr{};
	stack<char>ResultOfLeft{};
	stack<char>ResultOfRight{};
	int CountOfCommand = 0;

	cin >> Inputstr >> CountOfCommand;
	cin.ignore();
	for (char const elem : Inputstr)
	{
		ResultOfLeft.push(elem);
	}

	while (CountOfCommand--)
	{
		string InputCommand{};
		getline(cin, InputCommand);
		if (InputCommand.size() == 1)
		{
			if (InputCommand == "L" and not ResultOfLeft.empty())
			{
				ResultOfRight.push(ResultOfLeft.top());
				ResultOfLeft.pop();
				continue;
			}
			if (InputCommand == "D" and not ResultOfRight.empty())
			{
				ResultOfLeft.push(ResultOfRight.top());
				ResultOfRight.pop();
				continue;
			}
			if (InputCommand == "B" and not ResultOfLeft.empty())
			{
				ResultOfLeft.pop();
				continue;
			}
			continue;
		}
		ResultOfLeft.push(InputCommand[2]);
	}
	while (!ResultOfLeft.empty())
	{
		ResultOfRight.push(ResultOfLeft.top());
		ResultOfLeft.pop();
	}
	while (!ResultOfRight.empty())
	{
		cout << ResultOfRight.top();
		ResultOfRight.pop();
	}
	return 0;
}

//insert�� erase�� �̿��� ó�� - ����(�ð��ʰ�)
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//void EraseOne(string & Target, int & CurrentPos)
//{
//	Target.erase(CurrentPos-1,1);
//
//	CurrentPos--;
//
//}
//
//void AddOne(string & Target, int & CurrentPos, string const & AddToString)
//{
//	Target.insert(CurrentPos, AddToString);
//
//	CurrentPos++;
//}
//
//
//int main()
//{
//	cin.tie(nullptr);
//	ios_base::sync_with_stdio(false);
//
//	string InputStr{};
//
//	int PosOfCurser = 0;
//	int CountOfCommand = 0;
//
//	cin >> InputStr>> CountOfCommand;
//
//	PosOfCurser = static_cast<int>(InputStr.size());
//
//	cin.ignore();
//	while (CountOfCommand--)
//	{
//		string InputCommand{};
//		getline(cin, InputCommand);
//		if(InputCommand.size()==1)
//		{
//			if(InputCommand=="L" and PosOfCurser > 0)
//			{
//				PosOfCurser--;
//				continue;
//			}
//			if (InputCommand == "D" and PosOfCurser < InputStr.size())
//			{
//				PosOfCurser++;
//				continue;
//			}
//			if (InputCommand == "B" and PosOfCurser != 0)
//			{
//				EraseOne(InputStr, PosOfCurser);
//				continue;
//			}
//			continue;
//		}
//		AddOne(InputStr, PosOfCurser, InputCommand.substr(2,1));
//		
//	}
//	cout << InputStr;
//
//	return 0;
//}