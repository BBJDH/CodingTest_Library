/*
 *�ִ񰪰� �ּڰ�

���ڿ� �Ľ̰� �� �񱳹�������.
getline���� ���ڿ��� �޾ƿ� ' '�� ��� ��Ʈ���� �д´�
���� �� �񱳸� �� ��
��ȯ���� ���ڿ� �̹Ƿ� �ٽ� to_string���� �Ľ��Ѵ�.

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