/*
 * 10799 - �踷���
 *
 *�䱸���ױ״�� ���ڿ��� �Ľ��Ͽ� ������ ���� Ǯ����
 *"()"�� ���ܺθ� �ǹ��ϹǷ� �� �������� �׾��ִ� ������ ����
 *�̹� �߷��� ������ ���� ī�����ϰ� "()"���� ���� ������ ���� �����ϴ� ����̴�.
 *
 *�Է¹��� ���ڿ��� �� ���ʺ��� �����Ѵ�
 *
 *���� ��ġ�� CurrentPos�� �ϰ� ���� ��ġ�� NextPos�� �Ѵ�
 *(�� ��ġ�� �������� �߸��� ��ġ�� �ǹ��Ѵ�)
 *()�κ��� ã�� NextPos�� �����ϰ� NextPos����
 *'('�� �����ٸ� �߸� �������� ������ �����ϰ�
 *')'�� �����ٸ� �������� ������ �ǹ��ϹǷ� Result�� ������Ų��
 *�Ŀ� NextPos���� ������ �Ϸ��Ͽ��ٸ� ���� �߸� �������� ���� ���� Result�� �߰��Ѵ�.
 *
 *�̰��� �ݺ��Ͽ� find()�� Npos�� ��ȯ�Ѵٸ� NextPos�� ���ڿ��� ������� �����Ͽ�
 *���ڿ� ������ ������ ó����� �ϰ� Result�� ����� �����Ѵ�.
 *
 *�ٸ� Ǯ�̹������ �����ʺ��� ������� ������ ���ؼ��� Ǯ�̰� �����ϴ�.
 *
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int NumOfoverlappingPipe = 0;
	int CurrentPos = 0, Result = 0;

	string StrOfInput{};
	cin >> StrOfInput;

	while (CurrentPos < StrOfInput.size())
	{
		size_t NextPos = StrOfInput.find("()", CurrentPos);

		if (StrOfInput.find("()", CurrentPos) == string::npos)
		{
			NextPos = StrOfInput.size();
		}
		while (CurrentPos < NextPos)
		{
			if (StrOfInput[CurrentPos] == '(')
			{
				NumOfoverlappingPipe++;
			}
			else
			{
				NumOfoverlappingPipe--;
				Result++;
			}
			CurrentPos++;
		}
		Result += NumOfoverlappingPipe;
		CurrentPos = static_cast<int>(NextPos) + 2;
	}

	cout << Result;
	return 0;
}