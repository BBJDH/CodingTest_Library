/*

9536 - 여우는 어떻게 울지?

녹음된 문장을 저장할곳을 따로 마련
이후 각 동물들마다의 울음소리를 맵에 녹음
마지막 what does the fox say?는 소거
cin으로 입력받을때 \n이 남아있으므로 	cin.ignore()를 통해 한문자('\n')를 지워줌
getline(입력스트림, 보관할 문자열)로 줄단위로 읽어온다

<sstream>헤더의 stringstream ss(스트림에 등록할 대상 문자열)을 통해
getline(스트림,파싱된문자열을 보관할곳, 기준문자)로 파싱

다음 새로운 라인을 받는다면 다시 스트림을 초기화
			ss.clear();
			ss.str(InputSound);	//새롭게 getline으로 받아온 스트림에 다시 등록

이후 다음 테스트케이스 대비 입력된 자료들 초기화를 잊지 말자

*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<sstream>
using namespace std;

vector <string> InputSounds{};	//울음 소리 넣는곳(녹음된거)
set<string> AnimalSounds{};

void Solution()
{
	for (auto const& Elem : InputSounds)
	{
		if (AnimalSounds.end() == AnimalSounds.find(Elem))
			cout << Elem << " ";
	}
	cout << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;

	cin >> TestCase;
	cin.ignore();				//앞에서 입력받은 버퍼에 \n이 남아있으므로 지워준다
	string InputSound{ "" };

	while (TestCase--)
	{
		getline(cin, InputSound);
		stringstream ss(InputSound);
		while (getline(ss, InputSound, ' '))
		{
			InputSounds.push_back(InputSound);	//소리 녹음
		}

		while (true)
		{
			getline(cin, InputSound);
			if (InputSound == "what does the fox say?")
			{
				Solution();
				AnimalSounds.clear();
				InputSounds.clear();
				break;
			}
			ss.clear();
			ss.str(InputSound);
			vector<string> Sounds{};
			while (getline(ss, InputSound, ' '))
			{
				Sounds.push_back(InputSound);
			}
			AnimalSounds.insert(Sounds[2]);
		}
	}
	return 0;
}
