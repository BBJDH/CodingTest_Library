
/*
17219 - ��й�ȣ ã��
���ڿ� �Ľ��� �ʿ����, ã�Ƽ� ��ȯ
*/
#include<iostream>
#include<map>
#include<string>
#include<sstream>


using namespace std;

map<string, string> Sites{};


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Site_Count = 0;
	int Find_Count = 0;

	cin >> Site_Count >> Find_Count;
	cin.ignore();
	while (Site_Count--)
	{
		string Str{};
		getline(cin, Str);
		stringstream ss(Str);
		string Site{};
		string Password{};
		for (int i = 0; i < 2; i++)
		{

			getline(ss, Str, ' ');
			if (i == 0)
				Site = Str;
			else
				Password = Str;
		}
		Sites[Site] = Password;
	}

	while (Find_Count--)
	{
		string TargetSite{};
		cin >> TargetSite;
		cout << Sites[TargetSite] << "\n";
	}

	return 0;
}
