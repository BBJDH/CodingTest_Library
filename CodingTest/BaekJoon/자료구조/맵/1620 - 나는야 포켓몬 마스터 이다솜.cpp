/*
 *
 *1620 - 나는야 포켓몬 마스터 이다솜
 *
 *N개의 입력받은 문자열을 키로, 번호를 value로 하는 맵에 삽입
 *그리고 반대로도 value(int)를 index로, 문자열을 배열의 값으로 하는 배열에도 같이 삽입 한 후
 *
 *M개의 질문 문자열에 대하여
 *
 *첫문자가 '9'보다 크다면 해당문자열을 몬스터 이름인것으로 확정,
 *
 *몬스터는 맵에서
 *
 *번호는 배열에서 꺼내어 출력해 준다.
 *
 */

#include <iostream>
#include <map>
#include <string>


using namespace std;

string NumByMonster[100001]{};
map<string, int>MonsterByNum{};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string inputStr{};

		cin >> inputStr;

		MonsterByNum[inputStr] = i;
		NumByMonster[i] = inputStr;
	}

	for (int i = 0; i < M; i++)
	{
		string inputStr{};

		cin >> inputStr;
		if (inputStr[0] > '9')
		{
			//문자 처리
			cout << MonsterByNum[inputStr] << "\n";
		}
		else
		{
			cout << NumByMonster[stoi(inputStr)] << "\n";
		}
	}
	return 0;

}