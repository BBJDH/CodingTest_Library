/*

4154 - 직각삼각형

일단 다 제곱해서 더하고 
세수중에 제일 큰수만 찾아서 빼준것과 비교

*/


#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int A = 1, B = 1, C = 1;

	while (true)
	{
		cin >> A >> B >> C;

		if (A == 0 and B == 0 and C == 0)
			break;

		int Temp = A * A + B * B + C * C;

		int Length_Max = max(A, max(B, C));
		Temp = Temp - Length_Max * Length_Max;

		if (Length_Max * Length_Max == Temp)
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";

	}

	return 0;
}