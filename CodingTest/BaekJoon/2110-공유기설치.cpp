#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>

using namespace std;


//2110 ������ ��ġ
/*
������ �� TestCase, Hubum �� �Է¹���
while���� ���� TestCase��ŭ �Է� ����
���� ��ǥ ���� Location�� Vector<int> �� TestCase��ŭ ����
�켱 ������������ Location�� ����
12489
�Ÿ�������Ͽ� ���� �� ����
1241
�ּ� 1���� �ִ� 4���� ��������
�̺�Ž�� ����





�Ÿ��� �޾Ƽ� �� ����
������ �迭�� �Է� �޴´�

�� �Լ� �ۼ�
���� ���
������ ��ġ��ǥ, �̺�Ž�� ����(�ּҰŸ�, �ִ� �Ÿ�)
Mid ���� �˻�, ���� �ߴٸ� �Ϲ�, �����ߴٸ� ������� �˻�

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
		if (Simulate_Hub_Installation(location, search_mid, Hub_Num)) //��ġ�� ���� �ߴٸ� �ش� �Ÿ��� ���� �� ���� �Ÿ��� Ž��
		{
			search_Distance_Min = search_mid + 1;

			if (Anwser < search_mid)
				Anwser = search_mid;
		}
		else //��ġ�� �����ߴٸ� �Ѿ
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