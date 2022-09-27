

//#include<iostream>
//#include<vector>
//#include<map>
//#include<sstream>
//#include<string>
//using namespace std;
//
//string Today{};
//vector<string> Terms{};
//vector<string> Privacies{};
//
//map<string, int> FindTerm{};
//
//
//void ParseTerms_IntoMap()
//{
//	for (auto const& Elem : Terms)
//	{
//		stringstream ss(Elem);
//		string token{};
//		string Key{};
//		int term{};
//		for (int i = 0; i < 2; i++)
//		{
//
//			getline(ss, token, ' ');
//			if (i == 0)
//				Key = token;
//			else
//				term = stoi(token);
//		}
//		FindTerm[Key] = term;
//	}
//}
//
//void ParseYMD(string const & YMD, int& Year, int& Month, int& Day)
//{
//	string Target = YMD;
//	stringstream ss(Target);
//	string token{};
//	for (int i = 0; i < 3; i++)
//	{
//
//		getline(ss, token, '.');
//		if (i == 0)
//			Year = stoi(token);
//		else if (i == 1)
//			Month = stoi(token);
//		else
//			Day = stoi(token);
//	}
//}
//
//void GetLastDay(string const& StartDay, int const Term, int & LastYear, int& LastMonth, int& LastDay)
//{
//	ParseYMD(StartDay, LastYear, LastMonth, LastDay);
//	LastYear += (LastMonth + Term) / 12;
//	LastMonth = (LastMonth + Term) % 12;
//	LastDay--;
//
//	if (LastDay == 0)
//	{
//		LastDay = 28;
//		LastMonth--;
//	}
//	if (LastMonth == 0)
//	{
//		LastMonth = 12;
//		LastYear--;
//	}
//
//}
//
//void GetAnswer(vector<int> & answer)
//{
//	int CurrentYear{};
//	int CurrentMonth{};
//	int CurrentDay{};
//	ParseYMD(Today, CurrentYear, CurrentMonth, CurrentDay);
//	int Index = 1;
//	for (auto const& Elem : Privacies)
//	{
//		int LastYear{};
//		int LastMonth{};
//		int LastDay{};
//		stringstream ss(Elem);
//		string token{};
//		string StartDay{};
//		string term{};
//		for (int i = 0; i < 2; i++)
//		{
//
//			getline(ss, token, ' ');
//			if (i == 0)
//				StartDay = token;
//			else
//				term = token;
//		}
//		GetLastDay(StartDay, FindTerm[term], LastYear, LastMonth, LastDay);
//
//		if (LastYear < CurrentYear)
//			answer.push_back(Index);
//		else if(LastYear == CurrentYear)
//		{
//			if (LastMonth < CurrentMonth)
//			{
//				answer.push_back(Index);
//			}
//			else if (LastMonth == CurrentMonth)
//			{
//				if (LastDay < CurrentDay)
//				{
//					answer.push_back(Index);
//				}
//			}
//
//		}
//
//		Index++;
//	}
//}
//
//vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
//	Today = today;
//	Terms = terms;
//	Privacies = privacies;
//	vector<int> answer;
//	ParseTerms_IntoMap();
//	GetAnswer(answer);
//
//
//	return answer;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	//vector<int> Result = solution("2020.01.01", { "Z 3", "D 5" }, { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" });
//	vector<int> Result = solution("2023.01.01", { "A 6", "B 12", "C 3", "D 1"}, {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C", "2022.11.28"});
//
//	return 0;
//}

