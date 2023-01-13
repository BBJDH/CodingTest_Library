/*
 *11401 - ���� ��� 3
 *
 *���� ��� (N K) �� N! / K!(N-K)! �� �̿��� ���� ��� (N K)�� Mod 1,000,000,007�� ���Ѵ�.
 *
 *������ �䱸�ϴ� ���ش� 1,000,000,007(���� Limit��� �Ѵ�.)�� �������� �䱸�Ѵٴ� ���� �̿���
 *������ ������ ������ �̿��Ѵ�
 *
 *(a*b)%Limit =  (a%Limit*b%Limit)%Limit ���� �̿��ؾ��Ѵ�
 *
 *������  (a/b)%Limit =  (a%Limit/b%Limit)%Limit �� �������� �ʴ´�.
 *(�������� �ȵȴ�!, �� N! / K!(N-K)!�� /�� �������� �ʴ´�!)
 *
 *������ �и��� K!(N-K)!�� �� ((K!(N-K)!)^-1)%Limit�� ���ؾ� �Ѵ�
 *
 *���⼭ �丣���� �������� �ʿ������� �丣���� ��������
 *
 *a�� ���� p�� �Ҽ��϶�,
 *
 *pow(a,p)%p = a%P �� �����Ѵ�. �纯�� a�� ������
 *pow(a,p-1)%p = 1%p �� �ٽ� �纯���� ������
 *pow(a,p-2)%p = (a^-1)%p�� �ȴ�.
 *���⿡�� a^-1�� ġȯ�Ǿ� (K!(N-K)!)^-1)��� �����ϸ� �ȴ�!
 *(�����ӰԵ� Limit = 1,000,000,007�� �Ҽ��̴�. )�� �츮�� ���ϴ� ���ش�
 *
 *[N!* pow(K!(N-K)!,Limit-2)]%Limit �̴� (��������� ���� �����÷ο� ��������.)
 *���⼭ pow()�� Ÿ���� �Ǵ� ������ 1,000,000,005 ������ ���ؾ� �ϴµ�...
 *�翬�� �����÷ο찡 ����ȴ�. �� ������ %Limit�� ó��������
 *
 *�׳� N�� ������� ������ �����ϸ� ������. ������ ������ �̿��Ѵ�.
 *
 *a�� 8������ a�� 4���� * a�� 4������ ����
 *
 *�� 1,000,000,005�� ������ 1 Ȥ�� 2�� �ɶ� ���� �����Ͽ� �Լ��� ȣ����
 *������������ ������ ������ ó���ϸ� �ȴ�.
 *
 *
 */

#include <iostream>
#define Limit 1000000007

using namespace std;

int CalcFactorialWithLimit(long long TargetNum)
{
	long long Result = 1;

	while (TargetNum)
	{
		Result *= TargetNum;
		Result = Result % Limit;
		TargetNum--;
	}
	return static_cast<int>(Result);
}


long long PowWithLimit(long long TargetNum, int Exponent)
{
	if (Exponent == 1)
		return TargetNum;
	if (Exponent == 2)
		return (TargetNum * TargetNum) % Limit;
	if (Exponent % 2 == 1)
	{
		return (PowWithLimit(TargetNum, Exponent / 2) * PowWithLimit(TargetNum, ((Exponent / 2) + 1))) % Limit;
	}
	return PowWithLimit(TargetNum, Exponent / 2) * PowWithLimit(TargetNum, (Exponent / 2)) % Limit;
}

void Solution(int N, int K)
{
	long long N_FactorialWithLimit = 1;
	long long K_FactorialWithLimit = 1;
	long long N_Minus_K_FactorialWithLimit = 1;
	long long Denominator = 1;
	int Result = 0;


	N_FactorialWithLimit = CalcFactorialWithLimit(N);
	K_FactorialWithLimit = CalcFactorialWithLimit(K);
	N_Minus_K_FactorialWithLimit = CalcFactorialWithLimit(N - K);
	Denominator = PowWithLimit(((K_FactorialWithLimit * N_Minus_K_FactorialWithLimit) % Limit), Limit - 2);
	Result = (N_FactorialWithLimit * Denominator) % Limit;
	cout << Result;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, K = 0;
	cin >> N >> K;

	Solution(N, K);

	return 0;
}