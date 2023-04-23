/*
 *======================================================================
 *�������� - �Ͽ�¡ �ý���
 *
 * �� ĭ�� ���ٺ�� => ĭ���� �ü����� �Ÿ� * �߿䵵
 *
 * ĭ�� �������� ��� �ü� ���ٺ���� �� ĭ ���� �ִ������� ����
 *
 * �䱸���״�� ���� �� ���Ʈ������ Ǯ���Ѵ�.
 *
 */


 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 int Solution(int N, vector<vector<int>> facility)
 {
 	int answer = 100000000;
 
 
 
 	for(int y=1; y<=N; y++)
 	{
 		for(int x=1; x<=N; x++)
 		{
 			int MaxCost = 0;
 			for(vector<int> const & elem : facility)
 			{
 				int Distance = abs(x - elem[1]) + abs(y - elem[0]);
 				MaxCost = max(MaxCost, Distance * elem[2]);
 			}
 			answer = min(answer, MaxCost);
 		}
 	}
 
 	return answer;	
 }
 
 int main()
 {
 	cin.tie(nullptr);
 	ios_base::sync_with_stdio(false);
 	vector<vector<int>> Input = { {1,3,1}, {3,1,1}};
 	vector<vector<int>> Input = { {1,3,2}, {3,1,1}};
 	vector<vector<int>> Input = { {1, 1, 1}};
 	cout<<Solution(3, Input);
 
 	return 0;
 }
 
