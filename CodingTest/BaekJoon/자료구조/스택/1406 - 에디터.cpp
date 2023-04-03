/*
 *1406 - 에디터
 *
 *
 *std::string 을 이용해 insert와 erase로는 해결되지않는다
 *(시간초과 발생, 입력받는 명령어 갯수는 50만개이며 길이는 10만개로)
 *입력받는 Command마다 n의 연산을 해준다면 100억의 비용이 소모되므로 시간초과가 발생한다.
 *
 *따라서 스택을 이용해 현재 커서의 위치를 중심으로 명령을 처리해나간다.
 *
 *커서를 포함해 왼쪽 문자열을 저장할 스택과
 *나머지 오른쪽을 저장할 스택으로 나눈다
 *
 *커서가 왼쪽으로 이동한다면 왼쪽 스택을 뽑아 오른쪽으로 이동 (비용은 1 소모된다)
 *커서의 오른쪽이동도 마찬가지로 처리하며,
 *제거시에도 왼쪽 스택에서 Pop 연산만 해주면 된다(비용 1)
 *추가시에도 마찬가지로 Left의 Top에 Push한번으로 처리 가능해진다(비용 1)
 *
 *따라서 50만개의 명령을 받아도 50만번의 연산으로 처리 가능하다
 *
 *물론 출력을 위해 뒤집어주어야 하므로 왼쪽 스택을 오른쪽으로 모두 넣은 후
 *
 *출력하는 비용정도는 필요하다 (최대 10만)
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

//insert와 erase를 이용해 처리 - 실패(시간초과)
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