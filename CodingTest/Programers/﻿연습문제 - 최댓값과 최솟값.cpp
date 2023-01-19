/*
 *최댓값과 최솟값

문자열 파싱과 값 비교문제였다.
getline으로 문자열을 받아와 ' '로 끊어서 스트림을 읽는다
이후 값 비교를 한 후
반환값이 문자열 이므로 다시 to_string으로 파싱한다.

 */

 
 #include <iostream>
 #include <string>
 #include <vector>
 #include <sstream>
 
 using namespace std;
 
 string solution(string s) {
 
 
     stringstream ss(s);
     string token{};
     long long minNum = 1234567890 ;
     long long maxNum = -1234567890;
     while (getline(ss, token, ' '))
     {
         long long Num = stoi(token);
         minNum = min(minNum, Num);
         maxNum = max(maxNum, Num);
     }
     std::to_string(minNum)
     string answer = "";
     return answer;
 }
 
 int main()
 {
 	cin.tie(NULL);
 	ios_base::sync_with_stdio(false);
 
 	string number = "134234";
     string str = "9";
 
     //solution("CBD",{ "BACDE", "CBADF", "AECB", "BDA","CD"});
     solution("1 2 3 4");
 	return 0;
 }