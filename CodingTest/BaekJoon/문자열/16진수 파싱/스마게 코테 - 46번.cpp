
/*
 *������ ���� - 46��
 *
 *
 *���ڿ��� ����� �Է¹��� 16������ ���Ͽ�
 *
 *�ٽ� 16������ ����Ѵ�.
 *
 */

#include<iostream>
#include <string>


using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string N{}, M{};
	cin >> N >> M;
	int Num = stoul(N, nullptr, 16) + stoul(M, nullptr, 16);
	printf("%x", Num);
	return 0;
}
