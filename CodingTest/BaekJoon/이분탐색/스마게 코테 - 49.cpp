/*
 *������ ���� - 49
 *
 *�� �迭�� ��ġ�µ� �ߺ��Ǵ� ���ڴ� ��� �����Ѵ�. �ϳ��� �������.
 *
 *���� ������ ���� �� ���� ���
 *
 *
 */

 #include<iostream>
 #include <algorithm>
 #include <vector>
 #include <set>
 
 using namespace std;

 int main()
 {
 	cin.tie(nullptr);
 	ios_base::sync_with_stdio(false);
 
 	int SizeA = 0;
 	int SizeB = 0;
 
 	vector<int> Array{};
 	set<int> Target{};
 
 	cin >> SizeA >> SizeB;
 
 	for(int i=0; i<SizeA+ SizeB; i++)
 	{
 		int Input=0;
 		cin >> Input;
 		Array.push_back(Input);
 		Target.insert(Input);
 	}
 	sort(Array.begin(), Array.end());
 
 	for (int const Elem : Target)
 	{
 		auto First = lower_bound(Array.begin(),Array.end(),Elem);
 		auto Second = upper_bound(Array.begin(),Array.end(),Elem);
 		if((Second-First) !=1)
 		{
 			Array.erase(First, Second);
 		}
 
 	}
 	for(int const Elem : Array)
 	{
 		cout << Elem << " ";
 	}
 
 
 	return 0;
 }

