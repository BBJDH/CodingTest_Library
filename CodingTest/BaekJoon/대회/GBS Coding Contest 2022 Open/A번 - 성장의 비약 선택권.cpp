/*
 *A번 - 성장의 비약 선택권
 *
 *200 -> 208 1번
 *
 *203 -> 210 1번
 *
 *205 -> 210 1번
 *
 *206 -> 210 2번 (1과 동일)
 *	.
 *	.
 *	.
 *218 -> 220 3번
 *	.
 *	.
 *	.
 *229 -> 230 태풍 성장의 비약
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
 