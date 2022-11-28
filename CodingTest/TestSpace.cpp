/*
 *9935 - 문자열 폭발
 *
 *find와 erase를 사용한다면 해당 문자열 한개만 찾아서 제거하는데다가
 *O(mn)의 시간복잡도를 가지므로 (m은 전체 문자열길이, n는 찾는 문자열 길이)
 *시간초과가 발생한다.
 *
 *문자열을 스택처럼 써보자
 *
 *처음부터 새로운 문자열에 하나씩 넣으면서
 *Bomb문자열과 일치한다면 뽑아내는 식으로 구현해본다
 *하지만 한번 삭제가 일어난 후 합쳐진 문자열이 다시 폭탄이 되는 경우를 어떻게 처리할까
 *
 *CCCCCC444444 또는 12ab112ab2ab의 경우를 보자
 *
 *곰곰히 생각해보면 각 C4의 4와 12ab의 b가 검사신호가 된다
 *즉, 앞에서부터 기록하다가 4를 만나면 4를 포함한 두문자가 C4인지 확인한다
 *12ab 경우 b를 만나면 이것이 검사신호가 되어 b로부터 앞 네글자를 12ab인지 판별하고 삭제한다
 *이렇게 되면 C4가 삭제된 후 다시 4를 만나 합쳐진 문자열의 앞글자를 다시 추적 가능해진다
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
	string bombStr{};
	string result{};
	cin >> inputStr>>bombStr;

	for(int i=0; i<inputStr.size(); i++)
	{
		char const lastChar = inputStr[i];
		result += lastChar;
		if(lastChar == bombStr[bombStr.size()-1] and result.size()>=bombStr.size())
		{
			int count = 0;
			int startIndex = static_cast<int>(result.size() - bombStr.size());
			for(int i=0; i< bombStr.size(); i++)
			{
				if (result[startIndex + i] == bombStr[i])
					count++;
			}
			if(count == bombStr.size())
			{
				result.erase(result.begin() + startIndex, result.end());
			}

		}
	}
	if (result.empty())
		cout << "FRULA";
	else
		cout << result;


	return 0;
}