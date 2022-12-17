/*
 *2022 서울사이버대학교 프로그래밍 경진대회
 *
 *A번 - 빅데이터? 정보보호!
 *
 *security와 bigdata의 문자열의 갯수를 서로 비교해주면 된다
 *
 *라고 하면 시간복잡도가 복잡해지지 않을까?
 *
 *문제 보자마자 조건에 두개의 단어만 주어진다는것을 확인했고,
 *
 *s b 문자는 두 단어만이 가진 문자임을 확인하여
 *
 *O(N)으로 s와 b 만 카운트 해서 출력했다
 *
 *처음 입력받는 학생수는 이풀이 에서는 무의미하다
 *
 *
 */

#include <iostream>
#include <string>


using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string inputStr{};
	int N = 0;
	cin >> N;
	cin.ignore();
	getline(cin, inputStr);

	int b = 0;
	int s = 0;


	for (int i = 0; i < inputStr.size(); i++)
	{
		switch (inputStr[i])
		{
		case 's': s++; break;
		case 'b': b++; break;
		}
	}

	if (s == b)
		cout << "bigdata? security!";
	else if (s > b)
		cout << "security!";
	else
		cout << "bigdata?";





	return 0;
}