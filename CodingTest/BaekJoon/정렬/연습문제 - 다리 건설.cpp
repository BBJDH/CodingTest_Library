
/*
 *======================================================================
 *�������� - �ٸ� �Ǽ�
 *
 *���� ��� ������ �̾�� �� ������ �����Ѵ�.
 *
 *������ �̾�� �ִ� ���̸� ª�� ������ �ϹǷ�,
 *
 *��ǥ�� ũ�⸦ ����(X�� Y�� ��)���� �����Ѵ�.
 *
 *���� ���������� ũ�Ⱑ ���� ��ǥ(��) ���� ���������� �Ÿ��� ����
 *
 *������ �䱸���״�� �ø� ó���� �ǽ��Ͽ� ���� �� �Ÿ��� �����Ѵ�.
 *
 *������ ���� �� �Ÿ��� ����Ѵ�.
 *
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 struct _int2
 {
 	int X;
 	int Y;
 };
 
 bool operator>(_int2 const & Left, _int2 const& Right)
 {
 	return (Left.X + Left.Y) > (Right.X + Right.Y);
 }
 bool operator<(_int2 const& Left, _int2 const& Right)
 {
 	return (Left.X + Left.Y) < (Right.X + Right.Y);
 }
 
 int Distance(_int2 const & Left, _int2 const& Right)
 {
 	double SrcX = Left.X;
 	double SrcY = Left.Y;
 
 	double DestX = Right.X;
 	double DestY = Right.Y;
 
 	double Result = (DestX - SrcX) * (DestX - SrcX) + (DestY - SrcY) * (DestY - SrcY);
 	Result = sqrt(Result);
 	int ResultInt = Result;
 	if(Result> ResultInt)
 	{
 		ResultInt++;
 	}
 	return ResultInt;
 }
 
 int Solution(vector<int> x, vector<int> y)
 {
 	int answer = -1;
 	vector<_int2> Points{};
 	for (int i = 0; i < x.size(); i++)
 	{
 		Points.push_back({x[i], y[i]});
 	}
 	sort(Points.begin(), Points.end());
 
 	for(int i=1; i< Points.size(); i++)
 	{
 		answer = max(answer, Distance(Points[i-1], Points[i]));
 	}
 
 	return answer;	
 }
 
 int main()
 {
 	cin.tie(nullptr);
 	ios_base::sync_with_stdio(false);
 	vector<int> InputX = { 1,2,6,8};
 	vector<int> InputY = { 1,2,5,7};
 	//vector<int> InputX = { 1,2,4,2};
 	//vector<int> InputY = { 1,1,4,2};
 
 
 	cout<<Solution(InputX, InputY);
 
 	return 0;
 }
 
