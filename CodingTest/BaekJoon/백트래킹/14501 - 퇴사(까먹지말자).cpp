/*
 * 14501 - ���
 *
 *N�� 15 ���� �̹Ƿ� ���Ʈ ������ Ǯ�� �����ϴ�.
 *
 *��Ʈ��ŷ���� ��� ����� ���� Ž���ϵ��� �Ѵ�.
 *
 *�湮 ó���� Visit�� N�� 1~ 15 �̹Ƿ� 16�� ũ��� ����
 *ȸ�翡 �ӹ����� �� N�� �������� �ξ�
 *Visit �湮 ó���� N�� �ʰ��ϴ��� ���� �˻��Ѵ�.
 *
 *��Ʈ��ŷ�� �� ����� ���� �ش��ϴ� ���� ������ �־�� �ϹǷ�
 *���۷����� ��������ʰ� �����Ѵ�. (�� ����)
 *���� for���� ���� ������ Ž���ϹǷ� ������ Ž���� ���� �ʿ�ġ �ʴ�.
 *
 *���� ��� ȣ�� �� ���� ���� �湮�� ���� ��Һ��� Ž���� �����Ѵ�.
 *(�� �������!)
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct _int2
{
	int Time;
	int Pay;
};

bool Visit[16]{};
vector<_int2> Schedule{};
int MaxPay = 0;
int N = 0;


int Push(int Day, _int2 const& NextOrder)
{

	for (int i = Day; i < Day + NextOrder.Time; i++)
	{
		if (Visit[i] == true or i > N)
			return 0;
	}

	for (int i = Day; i < Day + NextOrder.Time; i++)
	{
		Visit[i] = true;
	}
	return NextOrder.Pay;
}
void Release(int Day, _int2 const& NextOrder)
{
	for (int i = Day; i < Day + NextOrder.Time; i++)
	{
		Visit[i] = false;
	}

}

void BackTracking(int Start, int SumPay = 0)
{
	for (int i = Start; i <= N; i++)
	{
		int CurrentPay = 0;
		CurrentPay = Push(i, Schedule[i]);

		if (CurrentPay != 0)	//�̹� �������� Push ������
		{
			SumPay += CurrentPay;
			BackTracking(i + 1, SumPay);

			Release(i, Schedule[i]);	//ȸ��
			SumPay -= CurrentPay;
		}
	}
	MaxPay = max(MaxPay, SumPay);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	Schedule.push_back({});	//���� �ε����� 1�� ���߱����� ���� ����
	for (int i = 0; i < N; i++)
	{
		_int2 inputData{};
		cin >> inputData.Time >> inputData.Pay;
		Schedule.push_back(inputData);
	}
	BackTracking(1);
	cout << MaxPay;
	return 0;
}