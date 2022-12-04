//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//vector<int> Examiner{};
//vector<int> Checker{};
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int M = 0, N = 0;
//
//	cin >> N >> M;
//	Checker.resize(M);
//	for(int i=0; i<N; i++)
//	{
//		int inpuMoney{};
//		cin >> inpuMoney;
//		Examiner.emplace_back(inpuMoney);
//	}
//	for(int i=0; i <N; i++)
//	{
//		for(int examiner_Index=0; examiner_Index<N; examiner_Index++)
//		{
//			int inputMoney = 0;
//			cin >> inputMoney;
//			Examiner[examiner_Index] += inputMoney;
//			Examiner[i] -= inputMoney;
//		}
//		for(int Checker_Index=0; Checker_Index< Checker.size(); Checker_Index++)
//		{
//			int inputMoney = 0;
//			cin >> inputMoney;
//			Checker[Checker_Index] += inputMoney;
//			Examiner[i] -= inputMoney;
//		}
//
//	}
//
//	for (auto const& elem : Examiner)
//		cout << elem<<" ";
//
//	for (auto const& elem : Checker)
//		cout << elem << " ";
//
//	return 0;
//}