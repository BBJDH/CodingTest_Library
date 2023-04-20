/*
 *
 *17478 - ����Լ��� ������?
 *
 *�־��� �䱸���״�� ����Լ��� �����Ѵ�.
 *
 *-�� �ƴ϶� _�� ����ؾ��Ѵ�.
 *���� ��ͱ��̿� �°� _�� �Լ��� ���� �ۼ��Ͽ� �����ߴ�.
 *
 *���� ���� ��ǥ ���̸� �� �������شٸ� ������ ������ ���� �� �ִ�.
 *
 *���� Ư���� ��Ÿ�� ��������...
 *
 */


#include <iostream>

using namespace std;

void PrintHyphen(int const Count)
{
	int PrintCount = Count * 4;
	while (PrintCount--)
	{
		cout << "_";
	}
}

void Recursive(int const CurrentCount, int const& MaxCount)
{
	PrintHyphen(CurrentCount);
	cout << "\"����Լ��� ������?\"\n";

	if (CurrentCount == MaxCount)
	{
		PrintHyphen(CurrentCount);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		PrintHyphen(CurrentCount);
		cout << "��� �亯�Ͽ���.\n";
		return;
	}

	PrintHyphen(CurrentCount);
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";

	PrintHyphen(CurrentCount);
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";

	PrintHyphen(CurrentCount);
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

	Recursive(CurrentCount + 1, MaxCount);

	PrintHyphen(CurrentCount);
	cout << "��� �亯�Ͽ���.\n";
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfRecusive = 0;
	cin >> CountOfRecusive;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	Recursive(0, CountOfRecusive);

	return 0;
}