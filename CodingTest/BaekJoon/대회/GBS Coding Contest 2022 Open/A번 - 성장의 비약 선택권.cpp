/*
 *A�� - ������ ��� ���ñ�
 *
 *200 -> 208 1��
 *
 *203 -> 210 1��
 *
 *205 -> 210 1��
 *
 *206 -> 210 2�� (1�� ����)
 *	.
 *	.
 *	.
 *218 -> 220 3��
 *	.
 *	.
 *	.
 *229 -> 230 ��ǳ ������ ���
 *
 *
 */

 
 #include <iostream>
 
 using namespace std;
 
 int main()
 {
 	cin.tie(NULL);
 	ios_base::sync_with_stdio(false);
 
 	int N = 0;
 
 	cin >> N;
 
 	if (N < 206)
 		cout << 1;
 	else if (N < 218)
 		cout << 2;
 	else if (N < 229)
 		cout << 3;
 	else
 		cout << 4;
 
 
 
 	return 0;
 }
 