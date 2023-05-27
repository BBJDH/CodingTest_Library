/*
 *2902 - KMP는 왜 KMP일까?
 *
 *문자열 파싱을 물어보는 문제
 *
 *stringstream을 이용해 푼다면 보편적인 단일 문자로 구분하여
 *단어단위로 끊어서 읽어 올 수 있다.
 *
 *문제의 요구사항대로 끊어온 단어의 첫 문자만 출력!
 *
 *
 */


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	getline(cin, InputStr);	//줄단위로 읽어오기. 띄어쓰기도 같이 읽어올 수 있다. 

	stringstream SS(InputStr);		//문자열을 스트림에 담는다 아래의 getline 함수를 사용하기 위함
	string Token{};

	//stream SS에 담긴 문자열에서 - 단위로 단어를 잘라 Token에 저장한다.
	//더 읽을 수 없다면 while 탈출
	while (getline(SS, Token, '-'))
	{
		//요구사항대로 첫문자만 출력
		cout << Token[0];
	}


	return 0;
}