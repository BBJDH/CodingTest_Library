/*
 *
 * 1009 - �л�ó��
 *
 *
 *������ Ư���� ��ǻ�ʹ� 10���̰�
 *������ ���ԵǴ� ��� ���� 10���� ��ǻ�Ͱ� ������ ó���Ѵ�
 *
 *�� ����� % 10�� ���� 0�� 10��, 1�� 1��, 2�� 2��... ���� ó���ȴ�.
 *
 *2�� �������� ����
 *
 *1 2 3 4  5  6   7   8
 *2 4 8 16 32 64 128 256
 *2 4 8 6  2  4   8   6
 *�̷��� ���� �ڸ� ������ �ݺ��Ǿ� ��Ÿ����(������ ���̰� �޶��� �� �ٸ����� ��� �����ϴ�.)
 *�ݺ��Ǵ� ������ ũ�⸦ ã�� %�������� �����ڸ��� ���� �����ϴ�. (9%4 => 1�̹Ƿ� �����ڸ��� 2�̴�)
 *
 *
 *
 *���� �̰��� ��� ã�Ƽ� ����ϴ��İ� �����̴�.
 *� ������ ���͵� ���� �ڸ��� ������ 0~ 10���� �����ϰ� �� ������ �ݺ��ȴ�.
 *���� �ݺ��Ǵ� ������ �ݵ�� 10���� �۴�
 *�׷��Ƿ� �迭 ũ�⸦ 10���� ��� ������ �ε����� �Ͽ� ������ ���� �ڸ��� ����Ѵ�.
 *���� ���� ������ �������� ������ %10�� ���� ��Ÿ���� ���� �迭�� ����Ѵ�.
 *(1���� �ߺ��� ��Ÿ���� ���� �����Ѵ�. �ε����� �ش� ������ �ȴ�)
 *
 *�� 2�� ����
 *1 2 3 4  5  6   7   8
 *2 4 8 16 32 64 128 256
 *2 4 8 6  2  4   8   6
 *
 *�� �����Ѵٸ�
 *DP[1] = 2;
 *DP[2] = 4;
 *DP[3] = 8;
 *DP[4] = 6;
 *
 *�� ��ϵǰ� ���� �� 5���� 2�� �ٽ� �����ϹǷ� ���⼭ �����ȴ�.
 *�� ũ��� 4�� �˰Եǰ� ������ �����ϴ� ���� %4�� ���� �� �� �ְ� �ȴ�.
 *������ ���⼭ 4�� ���� 4%4 �� 0���� DP[4]�� ������ �� �����Ƿ�
 *����%�ݺ� ũ�Ⱑ 0�ΰ�� DP[�ִ�ݺ�ũ��]�� ������� ó���Ѵ�.
 *
 *�̶� ���������� 10�� 2���� �����غ���
 *
 *DP[1] = 10 ���� ��ϵǾ�� �Ѵ�
 *������ 10 % 10�� 0�̱� ������ 0�� ��µȴ�.
 *0�� 10�� ��ǻ�͸� �ǹ��ϱ� ������ %10�� 0�̵Ȱ�츦 10���� ������ش�.
 *
 *
 *�����ϴ� ���� üũ�ϴ°��� ����Ž���� ���� ã���� ���� ������
 *�ݺ����� ���� O(N)���� �־��� ��츦 �����ص�(10�� ����ϰ� ã�� �Ǵ� ���) 10*10 = 100�� ����� ��ԵǹǷ�
 *�ݺ������� ���� �־���.
 *(���� Ž���� ����ϰ� �ʹٸ� lower_bound�� �ش���� ã�������� Ȯ�����ָ� �ȴ�.)
 *
 *
 *Ȥ�ó��ؼ� �׳� �������� Ǯ�̰� �������� Ȯ���غô� �ӵ��� 0���� 800ms�� �þ ���� Ȯ���ߴ�.
 *
 *
 */


#include <iostream>

using namespace std;


bool IsValidNum(int const* const ExponentToComputer, int const TargetNum, int const Size = 10)
{
	for (int i = 1; i < Size; i++)
	{
		if (ExponentToComputer[i] == TargetNum)
		{
			return true;
		}
	}
	return false;
}

void JustImplementation(int const InputNum, int const Exponent)
{
	int NumOfComputer = 0;
	NumOfComputer = InputNum % 10;
	for (int i = 2; i <= Exponent; i++)
	{
		NumOfComputer = (NumOfComputer * InputNum) % 10;
	}
	if (NumOfComputer == 0)
	{
		//0�� 10�� ��ǻ�͸� �ǹ�
		NumOfComputer = 10;
	}
	cout << NumOfComputer << "\n";
}

void UseDPArray(int const InputNum, int const Exponent)
{
	int ExponentToComputer[10]{};
	int NumOfComputer = 1;
	int CurrentExp = 1;

	while (true)
	{
		//��ǻ�� ��ȣ ���ϱ�
		NumOfComputer = (NumOfComputer * InputNum) % 10;
		if (NumOfComputer == 0)
		{
			NumOfComputer = 10;
		}

		//�ߺ� üũ
		if (IsValidNum(ExponentToComputer, NumOfComputer) == true)
		{
			break;
		}

		//�迭�� ���
		ExponentToComputer[CurrentExp] = NumOfComputer;
		CurrentExp++;
	}

	int const LoopNum = CurrentExp - 1;

	int IndexOfResult = Exponent % LoopNum;

	//0�̸� DP[�ݺ�����]�� �����ϵ��� ó��
	if (IndexOfResult == 0)
	{
		IndexOfResult = LoopNum;
	}

	cout << ExponentToComputer[IndexOfResult] << "\n";
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{

		int Num = 0, Exponent = 0;
		cin >> Num >> Exponent;
		//JustImplementation(Num, Exponent);
		UseDPArray(Num, Exponent);
	}

	return 0;
}