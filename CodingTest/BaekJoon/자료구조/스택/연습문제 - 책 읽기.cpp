/*
 *=============================
 *
 *연습문제 - 책 읽기
 *
 *
 *문제의 요구사항처럼 입력 받은 책 배열을 거꾸로 스택에 넣어 처음 책이 쌓인 상태를 만든다
 *
 *이후 원하는 책이 나올때 까지 예비 스택에 Pop&Push 하여 책을 꺼내고 꺼내진 예비 스택크기만큼
 *결과값에 합산한다.
 *
 *이후 예비스택을 pop&push 하여 다시 책을 쌓고 맨위에 꺼냇던 책을 넣는다.
 *
 *다음 책을 꺼낸다
 *
 *위의 과정을 입력받은 꺼낼 책 배열만큼 모두 반복하고
 *
 *누적된 합산 결과를 출력한다.
 */

 #include <iostream>
 #include <vector>
 #include <stack>
 
 using namespace std;
 
 
 int Solution(vector<int> books, vector<int> target)
 {
 	int answer = 0;
 
 	stack<int> Books{};
 
 	for (int i= books.size()-1; i>=0; i--)
 	{
 		Books.push(books[i]);
 	}
 
 	for(int i=0; i<target.size(); i++)
 	{
 		stack<int> PopStack{};
 		while (!Books.empty())
 		{
 			int const CurrentBook = Books.top();
 			Books.pop();
 			if (CurrentBook == target[i])
 			{
 				answer += PopStack.size();
 				while (!PopStack.empty())
 				{
 					Books.push(PopStack.top());
 					PopStack.pop();
 				}
 				Books.push(CurrentBook);
 				break;
 			}
 			PopStack.push(CurrentBook);
 		}
 
 
 	}
 
 
 
 	return answer;
 }
 



 int main()
 {
 	cin.tie(nullptr);
 	ios_base::sync_with_stdio(false);
 
 	//cout << Solution({ 3,1,2 },{1,3,2});
 	cout << Solution({ 1,2,3,4 },{4,4,3,2,1});
 
 	return 0;
 }
 
