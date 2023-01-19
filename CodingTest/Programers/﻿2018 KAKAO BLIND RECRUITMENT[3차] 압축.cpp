

/*
 *프로그래머스 - 압축
 *
 *맵을 이용해 검색되지 않는 문자열을 맵에 삽입한다
 *1개짜리 문자는 -'A'연산으로 계산
 *자료구조 맵과 구현으로 풀었다.
 *
 */

 #include <iostream>
 #include <string>
 #include <vector>
 #include <map>
 using namespace std;
 
 vector<int> answer{};
 
 vector<int> solution(string msg)
 {
     map<string, int> Dictionary{};
     int Index = 0;
     int D_Count = 27;
     while (Index < msg.size())
     {
         int Size = 2;
         string ToFindStr = msg.substr(Index, Size);
         while (Dictionary.find(ToFindStr) != Dictionary.end())
         {
             Size++;
             ToFindStr = msg.substr(Index, Size);
             if (Index + Size > msg.size())
             {
                 answer.push_back(Dictionary[ToFindStr]);
                 return answer;
             }
         }
         if (Size == 2)
         {
             answer.push_back(msg[Index] - 'A' + 1);
             Dictionary[ToFindStr] = D_Count;
             D_Count++;
             Index++;
             continue;
         }
         Dictionary[ToFindStr] = D_Count;
         D_Count++;
         ToFindStr = ToFindStr.substr(0, Size - 1);
         answer.push_back(Dictionary[ToFindStr]);
         Index = Index + Size - 1;
     }
 
     return answer;
 }
 int main()
 {
     cin.tie(NULL);
     ios_base::sync_with_stdio(false);
 
 
     solution("TOBEORNOTTOBEORTOBEORNOT");
     for (auto const& elem : answer)
         cout << elem << " ";
     return 0;
 }

