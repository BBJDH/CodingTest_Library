/*
 *4195 - 친구 네트워크
 *
 *분리집합을 통해 풀이가 가능하다
 *
 *맵으로 푸는 방법을 선택했다
 *
 *먼저 입력 받은 두 친구를 맵안에 있는지 확인하고,
 *없다면 자기 자신이 부모인 상태로 넣는다
 *그리고 두 친구중 왼쪽을 기준으로 집합을 만들어 나갔다
 *
 *고려해야할 예외가 있다
 *
 *입력 받은 두 친구가 이미 같은 친구 네트워크에 속한경우,
 *이때는 서로의 친구 수를 합하면 안된다 이미 같은 소속이기 때문
 *
 *입력 받은 두 친구의 가장 부모 친구를 기준으로 연산해 나간다.
 *
 */


#include <iostream>
#include <map>

using namespace std;

struct _String_Int
{
	string Parent;
	int NumberOfFriends;
};


map<string, _String_Int> Union{};

string  GetParent(string const& Child)
{
	if (Union[Child].Parent == Child)
		return Child;
	return Union[Child].Parent = GetParent(Union[Child].Parent);
}

void MakeUnion(string const& Right, string const& Left)
{
	string rightParent = GetParent(Right);
	string leftParent = GetParent(Left);

	if (rightParent != leftParent)
	{
		Union[leftParent].Parent = rightParent;
		Union[rightParent].NumberOfFriends += Union[leftParent].NumberOfFriends;
	}
	cout << Union[rightParent].NumberOfFriends << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		Union.clear();

		int howManyInputs = 0;
		cin >> howManyInputs;

		for (int i = 0; i < howManyInputs; i++)
		{
			/*
			 *먼저 각 문자열들이 union 안에 있는지 확인하고 없다면 union에 삽입,(자신의 이름, 1명)
			 *있는것이 확인되었다면 child를 parent에 결합, parent의 count를 출력
			 *
			 */
			string parentFriend{};
			string childFriend{};

			cin >> parentFriend >> childFriend;

			if (Union.find(parentFriend) == Union.end())
			{
				Union[parentFriend] = { parentFriend ,1 };
			}
			if (Union.find(childFriend) == Union.end())
			{
				Union[childFriend] = { childFriend ,1 };
			}
			MakeUnion(parentFriend, childFriend);
		}
	}

	return 0;
}