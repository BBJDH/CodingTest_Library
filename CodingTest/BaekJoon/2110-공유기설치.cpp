#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>

using namespace std;


//2110 공유기 설치
/*
임의의 수 TestCase, Hubum 를 입력받음
while문을 통해 TestCase만큼 입력 받음
집의 좌표 정수 Location을 Vector<int> 에 TestCase만큼 저장
우선 오름차순으로 Location을 정렬
12489
거리를계산하여 생성 및 정렬
1241
최소 1부터 최대 4까지 좁혀진다
이분탐색 시작





거리를 받아서 비교 시작
집들의 배열을 입력 받는다

비교 함수 작성
인자 목록
집들의 위치좌표, 이분탐색 범위(최소거리, 최대 거리)
Mid 선정 검색, 실패 했다면 하방, 성공했다면 상방으로 검색

*/
bool Simulate_Hub_Installation(vector<int>& location, int const Check_Distance, int const Hub_Num)
{
	int Prev_Hub = location[0];
	int Installed_Hub_Num = 1;
	for (size_t i = 1; i < location.size(); i++)
	{
		if (Check_Distance <= (location[i] - Prev_Hub))
		{
			Installed_Hub_Num++;
			Prev_Hub = location[i];
		}
	}

	return Installed_Hub_Num >= Hub_Num;
}

int BinerySearch(vector<int>& location, int search_Distance_Min, int search_Distance_Max, int const Hub_Num)
{
	int Anwser = 0;
	while (search_Distance_Max >= search_Distance_Min)
	{
		int search_mid = search_Distance_Min + (search_Distance_Max - search_Distance_Min) / 2;
		if (Simulate_Hub_Installation(location, search_mid, Hub_Num)) //설치에 성공 했다면 해당 거리를 보존 후 다음 거리로 탐색
		{
			search_Distance_Min = search_mid + 1;

			if (Anwser < search_mid)
				Anwser = search_mid;
		}
		else //설치에 실패했다면 넘어감
		{
			search_Distance_Max = search_mid - 1;
		}
	}
	return Anwser;
}


int main()
{
	int TestCase = 0, HubNum = 0;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> location{};


	cin >> TestCase >> HubNum;
	while (TestCase--)
	{
		int input_location = 0;
		cin >> input_location;
		location.push_back(input_location);
	}
	sort(location.begin(), location.begin() + location.size());

	vector<int> distance{};
	for (size_t i = 0; i < location.size() - 1; i++)
	{
		int calc_distance = location[i + 1] - location[i];
		distance.push_back(calc_distance);
	}
	sort(distance.begin(), distance.begin() + distance.size());


	cout << BinerySearch(location, distance[0], location[location.size() - 1], HubNum);


	return 0;
}