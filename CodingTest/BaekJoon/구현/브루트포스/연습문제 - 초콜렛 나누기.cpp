/*
 *======================================
 *
 *�������� - ���ݷ� ������
 *
 * DDDW
 * DDWW
 * MMMM
 *
 * DDDW
 *
 * DDWW
 *
 * MMMM
 *
 *
 *
 * DD DW
 * DD WW
 *
 * MMMM
 *
 *
 * DDD W
 * DDW W
 *
 * MMMM
 *
 * ���� ���� �б⸦ ������ ���������̴�.
 *
 * �������� ������ �������� �����°��(������ ����, �Ʒ����� ����)
 * �������θ� �����°��
 *
 * ������ ���������� ���� �����ʿ��� �������� ������ �������� ������ ���, �������θ� ������ ���
 *
 * ������ ���Ͽ� ������ ������, �̰��� ���Լ� ���� ���� �������� �����Ѵ�.
 *
 */

 #include <iostream>
 #include <vector>
 #include <string>
 
 using namespace std;
 
 struct _int2
 {
 	int X;
 	int Y;
 };
 
 struct _int3
 {
 	int DarkCount;
 	int MilkCount;
 	int WhiteCount;
 };
 
 vector<string> Chocolate{};
 void CountingChocolet(_int2 const & Start, _int2 const& End, _int3 & Result)
 {
 	Result = {};
 	for(int y= Start.Y; y< End.Y; y++)
 	{
 		for(int x= Start.X; x< End.X; x++)
 		{
 			if(Chocolate[y][x] =='D')
 			{
 				Result.DarkCount++;
 				continue;
 			}
 			if (Chocolate[y][x] == 'M')
 			{
 				Result.MilkCount++;
 				continue;
 			}
 			if (Chocolate[y][x] == 'W')
 			{
 				Result.WhiteCount++;
 				continue;
 			}
 		}
 	}
 }
 
 bool IsSucceed(vector<_int3> const & DividedChocolet)
 {
 
 	//0��° ���ݸ� Dark�� ���� �������
 	if(DividedChocolet[0].DarkCount > DividedChocolet[1].DarkCount and DividedChocolet[0].DarkCount > DividedChocolet[2].DarkCount)
 	{
 		//1��° Milk ���ݸ��� ���� ���� ���
 		if(DividedChocolet[1].MilkCount > DividedChocolet[0].MilkCount and DividedChocolet[1].MilkCount > DividedChocolet[2].MilkCount)
 		{
 			//White�� ���� ���ƾ� ��
 			if(DividedChocolet[2].WhiteCount > DividedChocolet[0].WhiteCount and DividedChocolet[2].WhiteCount > DividedChocolet[1].WhiteCount)
 			{
 				return true;
 			}
 		}
 		//2° �ΰ��
 		if (DividedChocolet[2].MilkCount > DividedChocolet[0].MilkCount and DividedChocolet[2].MilkCount > DividedChocolet[1].MilkCount)
 		{
 			//White�� ���� ���ƾ� ��
 			if (DividedChocolet[1].WhiteCount > DividedChocolet[0].WhiteCount and DividedChocolet[1].WhiteCount > DividedChocolet[2].WhiteCount)
 			{
 				return true;
 			}
 		}
 	}
 
 
 
 	//1��° ���ݸ� Dark�� ���� �������
 	if (DividedChocolet[1].DarkCount > DividedChocolet[2].DarkCount and DividedChocolet[1].DarkCount > DividedChocolet[0].DarkCount)
 	{
 		//0��° Milk ���ݸ��� ���� ���� ���
 		if (DividedChocolet[0].MilkCount > DividedChocolet[1].MilkCount and DividedChocolet[0].MilkCount > DividedChocolet[2].MilkCount)
 		{
 			//White�� ���� ���ƾ� ��
 			if (DividedChocolet[2].WhiteCount > DividedChocolet[0].WhiteCount and DividedChocolet[2].WhiteCount > DividedChocolet[1].WhiteCount)
 			{
 				return true;
 			}
 		}
 		//2 �ΰ��
 		if (DividedChocolet[2].MilkCount > DividedChocolet[0].MilkCount and DividedChocolet[2].MilkCount > DividedChocolet[1].MilkCount)
 		{
 			//White�� ���� ���ƾ� ��
 			if (DividedChocolet[0].WhiteCount > DividedChocolet[1].WhiteCount and DividedChocolet[0].WhiteCount > DividedChocolet[2].WhiteCount)
 			{
 				return true;
 			}
 		}
 	}
 
 
 	//2��° ���ݸ� Dark�� ���� �������
 	if (DividedChocolet[2].DarkCount > DividedChocolet[0].DarkCount and DividedChocolet[2].DarkCount > DividedChocolet[1].DarkCount)
 	{
 		//0��° Milk ���ݸ��� ���� ���� ���
 		if (DividedChocolet[0].MilkCount > DividedChocolet[1].MilkCount and DividedChocolet[0].MilkCount > DividedChocolet[2].MilkCount)
 		{
 			//White�� ���� ���ƾ� ��
 			if (DividedChocolet[1].WhiteCount > DividedChocolet[0].WhiteCount and DividedChocolet[1].WhiteCount > DividedChocolet[2].WhiteCount)
 			{
 				return true;
 			}
 		}
 		//1 �ΰ��
 		if (DividedChocolet[1].MilkCount > DividedChocolet[0].MilkCount and DividedChocolet[1].MilkCount > DividedChocolet[2].MilkCount)
 		{
 			//White�� ���� ���ƾ� ��
 			if (DividedChocolet[0].WhiteCount > DividedChocolet[1].WhiteCount and DividedChocolet[0].WhiteCount > DividedChocolet[2].WhiteCount)
 			{
 				return true;
 			}
 		}
 	}
 
 	return false;
 }
 
 int solution( vector<string> chocolate)
 {
 	int answer = 0;
 
 	Chocolate = chocolate;
 
 	vector<_int3> DividedChocolet{};
 	DividedChocolet.resize(3);
 
 	//�������
 	for(int y=0; y< chocolate.size(); y++)
 	{

        //�������θ�
        for (int secondy = y + 1; secondy < chocolate.size(); secondy++)
        {
            CountingChocolet({ 0,0 }, { static_cast<int>(chocolate[0].size()), y }, DividedChocolet[0]);
            CountingChocolet({ 0, y }, { static_cast<int>(chocolate[0].size()), secondy }, DividedChocolet[1]);
            CountingChocolet({ 0, secondy }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
            //����
            if (IsSucceed(DividedChocolet) == true)
            {
                answer++;
            }
        }

 		//�������� �� �Ʒ��� �߶�� ��
 		//���� �ڸ� ���
 		CountingChocolet({ 0,0 }, { static_cast<int>(chocolate[0].size()), y }, DividedChocolet[0]);
 		for (int x = 0; x < chocolate[0].size(); x++)
 		{
 
 			CountingChocolet({ 0, y }, { x, static_cast<int>(chocolate.size()) }, DividedChocolet[1]);
 			CountingChocolet({ x, y }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
 			if (IsSucceed(DividedChocolet) == true)
 			{
 				answer++;
 			}
 		}
 		//�Ʒ��� �ڸ� ���
 		CountingChocolet({ 0,static_cast<int>(chocolate.size() - y) }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[0]);
 		for (int x = 0; x < chocolate[y].size(); x++)
 		{
 			CountingChocolet({ 0, 0 }, { x, static_cast<int>(chocolate.size() - y) }, DividedChocolet[1]);
 			CountingChocolet({ x, 0 }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size() - y) }, DividedChocolet[2]);
 			if (IsSucceed(DividedChocolet) == true)
 			{
 				answer++;
 			}
 		}
 
 
 
 
 
 	}
 	//��������
 
 	for (int x = 0; x < chocolate[0].size(); x++)
 	{

        //DD DMM MWWW, DD DMMM WWW, DD DMMMW WW 
        //DDD MM MWWW, DDD MMM WWW, DDD MMMW WW
        //DDDM MM WWW, DDDM MMW WW
        //�������θ�
        for (int secondx = x + 1; secondx < chocolate[0].size(); secondx++)
        {
            CountingChocolet({ 0,0 }, { x, static_cast<int>(chocolate.size()) }, DividedChocolet[0]);
            CountingChocolet({ x, 0 }, { secondx, static_cast<int>(chocolate.size()) }, DividedChocolet[1]);
            CountingChocolet({ secondx, 0 }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
            //����
            if (IsSucceed(DividedChocolet) == true)
            {
                answer++;
            }
        }


 		//�������� ���ʺ��� �ڸ����,  �����ʺ��� �ڸ���� �����ؾ� ��
 
 		//�������� �ڸ� ���
 		CountingChocolet({ 0,0 }, { x, static_cast<int>(chocolate.size()) }, DividedChocolet[0]);
 		for (int y = 0; y < chocolate.size(); y++)
 		{
 			CountingChocolet({ x, 0 }, { static_cast<int>(chocolate[0].size()),y }, DividedChocolet[1]);
 			CountingChocolet({ x, y }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
 			if (IsSucceed(DividedChocolet) == true)
 			{
 				answer++;
 			}
 		}
 		
 		//�����ʺ��� �ڸ� ���
 		CountingChocolet({ static_cast<int>(chocolate[0].size() - x), 0 }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[0]);
 		for (int y = 0; y < chocolate.size(); y++)
 		{
 
 			CountingChocolet({ 0, 0 }, { static_cast<int>(chocolate[0].size() - x),  y }, DividedChocolet[1]);
 			CountingChocolet({ 0, y }, { static_cast<int>(chocolate[0].size() - x), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
 			if (IsSucceed(DividedChocolet) == true)
 			{
 				answer++;
 			}
 		}
 
 	}
 
 	return answer;
 }
 
 int main()
 {
 	cin.tie(nullptr);
 	ios_base::sync_with_stdio(false);
 
 	//cout << solution({ "DDMWWD","MDDMMW","WDDDDD", "MWDDWM", "WWWWDD", "WWWWWM"});
 	//cout << solution({ "DDMMWW"});
 	cout << solution({ "DDDW","DDWW","MMMM" });
 	//cout << solution({ "DDDMMMWWW" });
 
 	return 0;
 }