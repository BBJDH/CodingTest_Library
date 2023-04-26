/*
 *=============================
 *
 *�������� - å �б�
 *
 *
 *������ �䱸����ó�� �Է� ���� å �迭�� �Ųٷ� ���ÿ� �־� ó�� å�� ���� ���¸� �����
 *
 *���� ���ϴ� å�� ���ö� ���� ���� ���ÿ� Pop&Push �Ͽ� å�� ������ ������ ���� ����ũ�⸸ŭ
 *������� �ջ��Ѵ�.
 *
 *���� �������� pop&push �Ͽ� �ٽ� å�� �װ� ������ ������ å�� �ִ´�.
 *
 *���� å�� ������
 *
 *���� ������ �Է¹��� ���� å �迭��ŭ ��� �ݺ��ϰ�
 *
 *������ �ջ� ����� ����Ѵ�.
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
 
