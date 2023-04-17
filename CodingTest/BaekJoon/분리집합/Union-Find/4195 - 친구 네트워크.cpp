/*
 *4195 - ģ�� ��Ʈ��ũ
 *
 *�и������� ���� Ǯ�̰� �����ϴ�
 *
 *������ Ǫ�� ����� �����ߴ�
 *
 *���� �Է� ���� �� ģ���� �ʾȿ� �ִ��� Ȯ���ϰ�,
 *���ٸ� �ڱ� �ڽ��� �θ��� ���·� �ִ´�
 *�׸��� �� ģ���� ������ �������� ������ ����� ������
 *
 *����ؾ��� ���ܰ� �ִ�
 *
 *�Է� ���� �� ģ���� �̹� ���� ģ�� ��Ʈ��ũ�� ���Ѱ��,
 *�̶��� ������ ģ�� ���� ���ϸ� �ȵȴ� �̹� ���� �Ҽ��̱� ����
 *
 *�Է� ���� �� ģ���� ���� �θ� ģ���� �������� ������ ������.
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
			 *���� �� ���ڿ����� union �ȿ� �ִ��� Ȯ���ϰ� ���ٸ� union�� ����,(�ڽ��� �̸�, 1��)
			 *�ִ°��� Ȯ�εǾ��ٸ� child�� parent�� ����, parent�� count�� ���
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