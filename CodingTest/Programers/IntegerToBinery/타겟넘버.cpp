#include"stdafx.h"

using namespace std;


void Integer_To_Binery_Code(vector<int> & Binery_Code, int const target_num, int const code_size)
{
	for (int i = code_size-1; i >= 0; --i)
	{
		int single_Binery = target_num >> i & 1;
		Binery_Code.push_back(single_Binery);
	}
	return;
}

//
//int solution(vector<int> numbers, int target) {
//	
//	std::vector<int> Binery_Code = {};
//	int answer = 0;
//
//	
//
//	int binery_to_Operator_num = pow(2,numbers.size());
//	for (int i = 0; i < binery_to_Operator_num; ++i)
//	{
//
//		int sum = 0;
//		Binery_Code.clear();
//		Integer_To_Binery_Code(Binery_Code, i, numbers.size());
//		for (int j = 0; j < numbers.size(); ++j)
//		{
//			if (Binery_Code.at(j) == 1 )
//				sum += numbers[j];
//			else
//				sum += numbers[j] * (-1);
//		}
//		if (sum == target)
//			answer++;
//	}
//
//	return answer;
//}
//+ 혹은 -를 누적해서 리턴하는 함수를 호출
//배열, 인덱스, 누적 값을 전달


void DFS_Select_Operator(vector<int> const & number, int index, int sum, int const target, int & answer)
{
	index++;
	if (index >= number.size())
	{
		if (sum == target)
			answer++;
		return;
	}
	DFS_Select_Operator(number, index, sum + number[index], target, answer);
	DFS_Select_Operator(number, index, sum - number[index], target, answer);
}

int solution(vector<int> numbers, int target) 
{
	int answer = 0;

	if (numbers.empty())
		return 0;

	DFS_Select_Operator(numbers, 0, numbers[0], target, answer);
	DFS_Select_Operator(numbers, 0, -numbers[0], target, answer);

	return answer;
}


int main()
{
	std::vector<int> numbers = { 1,1,1,1,1};

	cout << solution(numbers, 3);
	//Make_Binery_Code(binery_code, 11, 8);


	//stringstream ss(str);
	//while (getline(ss, token, '-'))
	//{
	//	cout << token << endl;
	//}
	
	return 0;
}
//https://programmers.co.kr/learn/courses/30/lessons/43165

#pragma region 모범답안
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int total;
//
//void DFS(vector<int>& numbers, int& target, int sum, int n) {
//	if (n >= numbers.size()) {
//		if (sum == target) total++;
//		return;
//	}
//
//	DFS(numbers, target, sum + numbers[n], n + 1);
//	DFS(numbers, target, sum - numbers[n], n + 1);
//}
//
//int solution(vector<int> numbers, int target) {
//	int answer = 0;
//
//	DFS(numbers, target, numbers[0], 1);
//	DFS(numbers, target, -numbers[0], 1);
//
//	answer = total;
//
//	return answer;
//}
#pragma endregion
