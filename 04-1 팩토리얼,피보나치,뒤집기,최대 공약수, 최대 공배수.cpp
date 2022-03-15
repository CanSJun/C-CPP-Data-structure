#include <iostream>

using namespace std;

/*
팩토리얼
피보나치 수
문자열 뒤집기
최대 공약수와 최소 공배수


*/

// 1 팩토리얼 : 어떤 자연수 N이 주어졌을때 1~n까지 모든 곱한 값.

long long factorial(int n) { 
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);

}

// 2 피보나치 수 : 첫째 및 둘째항이 1 이며 그 뒤의 모든 항은 바로 앞  두항의 합인 수열
//ex ) 1 , 1 ,  2 , 3 , 5 , 8 , 13 , 21 , 34  , 55 ...
// 편의상 0번째 항을 0으로 설정하기도 한다.
// 재귀에 의한 피보나치 수 계산의 문제점 : 중복되는 부분 문제 (overlapping subproblem)로 인해 계싼 효율이 떨어진다
//

long long fibo(int n) {
	if (n <= 1)
		return n;
	else
		return fibo(n - 1) + fibo(n - 2);
}


// 3 문자열 뒤집기 
//

string reverse(const string& str) {
	if (str.length() == 0)
		return "";
	else
		return reverse(str.substr(1)) + str[0];
}

// ㅇ 최대 공약수와 최소 공배수
// 최대 공약수  gcd(a,b): 두개의 자연수 a 와 b가 있을 때, a와 b모두의 약수중에서 가장 큰 정수
// -> 유클리드 알고리즘(유킬리드 호제법) : 두개의 정수 ab가 주어지면 b가 0이면 a를 최대 공약수를 판단함 .
// b가 0이 아니면 입력이 들어온 a와 b값을 적절히 변경해서 자기자신을 호출하는 형태로 구성이 되어 있다.
// 즉 b가 0이 아닌 경우 두번째 들어온 정수값을 gcd(b,a %b)로넣고 a를 %b나눈 나머짓값을 한다.

//예로들면 gcd(24,18) 6 * 4 , 6 * 3  => 최대 공약수는 6이다.
//일단 24와 18에서 2번째 정수 즉 b가 0이 아니때문에
// gcd(18, 24 % 18);이 된다 => gdc(18,6)으로 변경이 된다.  => gcd(6, 0)이 된다
// 2번쨰가 0이 되니깐 6이 그대로 최대 공약수로 선택이 된다.

// gcd(18,24)일 경우 =>  gcd(18, 24 % 18 ) => gcd(24, 18 (나누게되면  몫은 0이 되고 나머지가 18이된다)가 된다
// 그럼 위 처럼되니 쭉 된다

int gcd(int a, int b) { // 최대 공약수
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);

}

//최소 공배수 : lcm(a,b) : 두 정수 a 와 b가 있을때 a와 b로 모두 나누어 떨어지는 가장 작은 수
//두 정수의 곱은 두 정수의 최대 공약수와 최소 공배수의 곱과 같다는 성질을 이용한다
// a x b = gcd(a,b) * lcm(a,b) => lcm(a,b) = ab/gcd(a,b);

int lcm(int a, int b) { // 최대 공배수
	return a * b / gcd(a, b);
}
// c++17부터 지원 <numeric>에 정의 되어있다 gcd와 lcm이.