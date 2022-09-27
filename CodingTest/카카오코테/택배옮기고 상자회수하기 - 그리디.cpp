//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//vector<long long> Distance{};
//vector<long long> Costs{};
//long long N = 0;
//long long Result = 0;
//
//void Solution()
//{
//	long long CurrentCost = Costs[0];
//	long long CurrentDistance = 0;
//	for (int i = 0; i < N - 2; i++)
//	{
//		CurrentDistance += Distance[i];
//
//		if (CurrentCost >= Costs[i + 1])
//		{
//			Result += CurrentDistance * CurrentCost;
//			CurrentCost = Costs[i + 1];
//			CurrentDistance = 0;
//		}
//	}
//	CurrentDistance += Distance[N - 2];
//	Result += CurrentDistance * CurrentCost;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//
//	cin >> N;
//	int Count = N - 1;
//	while (Count--)
//	{
//		int Input = 0;
//		cin >> Input;
//		Distance.push_back(Input);
//	}
//	Count = N - 1;
//
//	while (Count--)
//	{
//		int Input = 0;
//		cin >> Input;
//		Costs.push_back(Input);
//	}
//	Solution();
//	cout << Result;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//struct _int2
//{
//	int Distance;
//	int Elem;
//};
//
//int Cap{};
//int N{};
//vector<_int2> Deliveries{};
//vector<_int2> Pickups{};
//
//
//int NextDest()
//{
//	int Deliveries_Max = 0;
//	int Pickups_Max = 0;
//	if (!Deliveries.empty())
//		Deliveries_Max = Deliveries[Deliveries.size() - 1].Distance;
//	if (!Pickups.empty())
//		Pickups_Max = Pickups[Pickups.size()-1].Distance;
//	return max(Deliveries_Max, Pickups_Max);
//}
//
//void SetVisitList(vector<int> & deliveries, vector<int> & pickups)
//{
//	for (int i = 0; i < N; i++)
//	{
//		if (deliveries[i] != 0)
//			Deliveries.push_back({ i + 1 , deliveries[i] });
//		if (pickups[i] != 0)
//			Pickups.push_back({ i + 1 , pickups[i] });
//	}
//	
//}
//
//
//void Delivery()
//{
//	int CurrentCap_Delivery = Cap;
//	int CurrentCap_Pickup = Cap;
//
//
//	if (not Deliveries.empty())
//	{
//
//		for (size_t i = Deliveries.size()-1; i >= 0; i--)
//		{
//			if (CurrentCap_Delivery >= Deliveries[i].Elem)
//			{
//				CurrentCap_Delivery -= Deliveries[i].Elem;
//				Deliveries.erase(Deliveries.begin()+i);
//				if (Deliveries.empty())
//					break;
//			}
//			else
//			{
//				Deliveries[i].Elem -= CurrentCap_Delivery;
//				CurrentCap_Delivery = 0;
//			}
//			if (CurrentCap_Delivery == 0)
//				break;
//		}
//	}
//
//	if (not Pickups.empty())
//	{
//		for (size_t i = Pickups.size() - 1; i >= 0; i--)
//		{
//			if (CurrentCap_Pickup >= Pickups[i].Elem)
//			{
//				CurrentCap_Pickup -= Pickups[i].Elem;
//				Pickups.erase(Pickups.begin() + i);
//				if (Pickups.empty())
//					break;
//			}
//			else
//			{
//				Pickups[i].Elem -= CurrentCap_Pickup;
//				CurrentCap_Pickup = 0;
//			}
//			if (CurrentCap_Pickup == 0)
//				break;
//		}
//	}
//
//
//}
//
//long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
//
//	Cap = cap;
//	N = n;
//	SetVisitList(deliveries, pickups);
//	long long answer = 0;
//
//	int Dest = NextDest();
//	while (Dest)
//	{
//		answer += Dest;
//		Delivery();
//
//
//		Dest = NextDest();
//	}
//	
//
//	return answer*2;
//}
//
//int main()
//{
//	//solution(4, 5, { 1, 0, 3, 1, 2 }, { 0, 3, 0, 4, 0 });
//	//solution(2, 7, { 1, 0, 2, 0, 1, 0, 2 }, { 0, 2, 0, 1, 0, 2, 0 });
//	solution(5, 3, {5, 5,5}, { 0, 0, 0 });
//	//solution(1, 7, {1, 0, 2, 0, 1, 0, 0}, { 0, 2, 0, 1, 0, 2, 2 });
//	return 0;
//}