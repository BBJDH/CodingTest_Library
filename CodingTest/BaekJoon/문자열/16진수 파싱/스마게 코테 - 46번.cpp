
/*
 *스마게 코테 - 46번
 *
 *
 *문자열로 띄워서 입력받은 16진수를 합하여
 *
 *다시 16진수로 출력한다.
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
