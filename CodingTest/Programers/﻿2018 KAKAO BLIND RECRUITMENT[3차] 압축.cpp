

/*
 *���α׷��ӽ� - ����
 *
 *���� �̿��� �˻����� �ʴ� ���ڿ��� �ʿ� �����Ѵ�
 *1��¥�� ���ڴ� -'A'�������� ���
 *�ڷᱸ�� �ʰ� �������� Ǯ����.
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

