/*
 *1339 - �ܾ� ����
 * 
 * ������ ������ġ���� ����ġ�� �����ϰ� �� ������ �����Ͽ� �׸���� Ǯ�����.
 *
 *���� �� ���ڿ��� �� ���ڴ� ���� ū ���ڸ� �����Ѵ�.
 *
 *���� ��ġ�� �����ϴ� ���ĺ����� �����Ѵٸ� �ߺ��Ǵ� Ƚ���� ���� ���ĺ��� �켱�ȴ�.
 *
 *�ڸ��� ���� ���ĺ��� ����ġ�� �ο��ϱ����� Count �迭�� �����.
 *
 *ACDEB �� �ܾ �������
 *
 *11111 �� ����ġ�� ������ ������
 *
 *A�� ��� 10000
 *C�� ��� 1000
 *D�� ��� 100
 *E�� ��� 10
 *B�� ��� 1�� �Ǵ� ���̴�.
 *
 *���� �ߺ��� ���ڰ� �ٸ� ��ġ�� ������ �� �����Ƿ� ���Ͱ��� ����ġ�� å���ϰ�
 *AlphabetCount�� �ε����� ���ĺ�-'A'�� �Ͽ� �����صд�
 *
 *���� ����ġ ������ ���ĺ����� �����ϰ� AlphabetToNum �迭�� �� ���� ���ڸ� ������ �ش�.
 *
 *���� �Է¹޾Ҵ� ���ڵ��� ���ڷ� �ٲپ� ��� �����ֱ⸸ �ϸ� �ȴ�.
 *�� ���ڿ��� AlphabetToNum�κ��� �Ҵ�� ���ڵ�� �ٲپ��� ��,
 *stoi�� ���� ��� �ջ��Ͽ� ����� ����Ѵ�.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Node
{
	char Alphabet;
	int Count;
};

bool operator>(Node const& Left, Node const& Right)
{
	return Left.Count > Right.Count;
}
bool operator<(Node const& Left, Node const& Right)
{
	return Left.Count < Right.Count;
}

char AlphabetToNum[26]{};
int AlphabetCount[26]{};



int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<string> Alphabets{};
	vector<Node> AlphabetToSort{};

	int Size = 0;

	cin >> Size;
	for (int i = 0; i < Size; i++)
	{
		string InputStr{};
		cin >> InputStr;

		Alphabets.push_back(InputStr);

		for (int i = 0; i < InputStr.size(); i++)
		{
			int const AlphabetIndex = InputStr[i] - 'A';
			int Count = 1;
			int Pos = static_cast<int>(InputStr.size()) - i - 1;
			while (Pos--)
			{
				Count = Count * 10;
			}

			AlphabetCount[AlphabetIndex] += Count;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (AlphabetCount[i] != 0)
		{
			AlphabetToSort.push_back({ static_cast<char>('A' + i), AlphabetCount[i] });
		}
	}
	sort(AlphabetToSort.begin(), AlphabetToSort.end(), greater<>());

	int CurrentNum = 9;
	for (int i = 0; i < AlphabetToSort.size(); i++)
	{
		int const AlphabetIndex = AlphabetToSort[i].Alphabet - 'A';
		char MappedNumchar = CurrentNum + '0';
		CurrentNum--;

		AlphabetToNum[AlphabetIndex] = MappedNumchar;
	}

	int Result = 0;

	for (string& Elem : Alphabets)
	{
		for (int i = 0; i < Elem.size(); i++)
		{
			int const AlphabetIndex = Elem[i] - 'A';
			Elem[i] = AlphabetToNum[AlphabetIndex];
		}
		Result += stoi(Elem);
	}
	cout << Result;
	return 0;
}