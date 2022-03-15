#include <iostream>

using namespace std;
/*
ㅇ동적계획법(dynamic programming)  / 동적 프로그래밍이라고도 함
-복잡한 문제를  간단한 여러개의 부분 문제(subproblem)으로 나누고, 부분 문제에 대한 해답을 구해서
전체 문제의 해결하는 문제 해결 방식이다.
-분할 정복법(divide and conquer)과 동적 계획법과 차이는
분할 정복법에는 부분 문제들이 서로 겹치지않지만 , 동적 계획법에서는 중복되는 부분 문제가 발생한다는 점이 다르다.

-보통 최적화 문제 (optimization problem) 또는 카운팅(counting)문제에 적용한다

-유명한 동적 계획법 문제들
1.0-1배낭 문제 (0-1 knapsack problem)
2. 부분집합의 문제 (subset sum problem)
3. 최장 공통 부분 시컨스(LCS : longest common subsequence)
4. 연쇄 행렬 곱셈 ( chain matrix multiplication)
5. 최소 비용 경료 (minimum cost path)

ㅇ동적 계획법 필요 조건.
1. 중복되는 부분 문제(overlapping usbproblems)
-주어진 문제를 여러개의 부분 문제로 분할했을 경우, 몇몇 부분 문제가 중복되어 나타나는 현상
-부분 문제가 중복되지 않은 경우, 분할정복법을 이용해서 해결이 가능하다. 
발생하면 부분 문제의 해결방법을 저장하여, 중복되는 부분이 나왔을떄 이 솔루션을 이용해서 중복 해서 계산하지 않도록 설정한다

2.최적부분구조(optimal substrucutre)
-부분문제을 해결하는 최적의 솔루션 최적해(optimal solution)를 구했을때 이 솔루션들을 조합해서
전체 문제의 optimal solution을 구할 수 있을 경우에 최적부분구조를 가졌다고 한다.

ㅇ동적계획법 문제의 해결 방법
1.기저 조건(base case)정의
2. 상태 전환(state transition)을 나타내는 순환식을 정의
3. 순환식을 memoization 또는 tabulation 방식으로 풀이.


ㅇ피보나치 수열을 동적 계획법으로 계산.
0,1,1,2,3,5,8,13,21,34,55
---         -+- --- : 두개의 값을 구해서 자기 자신을 만드는 이러한 관계식을 상태전환이라고 한다.
관계씩을 표현하는게 아니라 특정한 조건에서 결과값을 그대로 설정해논걸 기저조건이라고 한다.

-중복되는 부분문제 발생이 일어난다. 그래서 재귀 함수로 계산하면 시간 복잡도가, O(N^2)이 된다.

해결로는
ㅇmemoization 방법
-중복 계산될 수 있는 값을 cashe(캐시)에 저장 하여 재 사용. 
-하향식(top-down)접근 방법.

memo라는 배열에 푼걸 저장을하는데, 나중에 똑같은게 나오면 그 배열에서 가져온다. 

중복되는걸 없에서 시간 복잡도는 O(n) 형태로 나타낼 수 있다.

ㅇtabulation 방법
-모든 부분문제 연산 결과를 미리 표(table)에 저장하여 사용하는 방식
-상향식(bottom - up) 접근 방법.

시간복잡도는 O(n)으로 나탈 내수 있다.

두개의 차이는?

						memoization									 vs						 tabulation
재귀호출이 많이 발생하므로, 함수 호출에 따른 오버헤드가 있다.				표(배열)에 저장된 값을 참조하는 방식으로 빠르게 동작한다
경우에 따라 모든 부분 문제를 풀지 않아도 문제에 대한 해답을 구할 수 있다.   상향식 방식이기 때문에 모든 부분 문제에 대한 해답을 구해서 표에 저장
캐시로 사용하는 표의 일부만 필요에따라 계산하여 채운다						 표의 맨 처음부터 끝까지 차례대로 계산하여 모두 채운다.

*/
#include <vector>

vector<int> memo(50, -1);
int fibo(int n) { //memoization
	if (n < 2)return n;
	if(memo[n] != -1) return memo[n]; // 메모배열에 있다면? 반환

	memo[n] = fibo(n - 2) + fibo(n - 1);
	return memo[n];
}


int fibo(int n) // tabulation
{
	vector<int> dp(n + 1, 0); // 모든 값이 0으로 초기화 되어있음 0 0 0 0 0 0 
	dp[1] = 1; // 0 1 0 0 0 0 // 0 , 1 이 항은 피보나치 수열 기저조건을 만족한다. 

	for (int i = 2; i <= n; i++) // 5를 계산하기위해. i 2번부터 5번쨰 항까지 올라가면서
		dp[i] = dp[i - 2] + dp[i - 1]; // dp 벡터값을 채운다.
	// 0 1 1 2 3 5
	return dp[n];
	
}
