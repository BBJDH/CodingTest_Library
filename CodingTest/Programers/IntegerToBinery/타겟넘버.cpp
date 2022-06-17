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


int solution(vector<int> numbers, int target) {
	
	std::vector<int> Binery_Code = {};
	int answer = 0;

	

	int binery_to_Operator_num = pow(2,numbers.size());
	for (int i = 0; i < binery_to_Operator_num; ++i)
	{

		int sum = 0;
		Binery_Code.clear();
		Integer_To_Binery_Code(Binery_Code, i, numbers.size());
		for (int j = 0; j < numbers.size(); ++j)
		{
			if (Binery_Code.at(j) == 1 )
				sum += numbers[j];
			else
				sum += numbers[j] * (-1);
		}
		if (sum == target)
			answer++;
	}

	return answer;
}


int main()
{
	std::vector<int> numbers = { 1,1,1,1,1 };
	std::vector<int> binery_code;

	Make_Binery_Code(binery_code, 11, 8);

	cout << solution(numbers, 3);

	//stringstream ss(str);
	//while (getline(ss, token, '-'))
	//{
	//	cout << token << endl;
	//}
	
	return 0;
}


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
