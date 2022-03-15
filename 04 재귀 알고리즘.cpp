#include <iostream>

using namespace std;

/*
ㅇ재귀알고리즘
-알고리즘이나 함수가 수행 도중에 자기 자신을 다치 호출하여 문제를 해결하는 기법이다.
-많은 종류 문제가 재귀적으로(recursively)해결 가능
ex) 피보나치 수열, 이진탐색, 병합정렬, 퀵 정렬 등

ㅇ재귀함수
-자기자신을 다시 호출하는 함수, 순환함수라고도 한다
-자기 자신을 완전히 그대로 호출하지 않고, 함수의 인자를 특정한 방식으로 변경하여 호출한다.

ㅇ재귀함수의 구성
-기저조건(base case) : 더 이상 재귀호출을 하지 않고 재귀를 종료 할 수 있는 조건이 있기때문에 이걸 종료 조건이라고 한다.
즉 재귀를 종료하기 위한 조건이 있어야한다는 것
-재귀 호출(recursive case) : 자기 자신을 다시 호출하는 부분이다. 재귀를 반복하다 보면 반드시 기저 조건으로 수렴해야 한다.


예제는 자연수의 합을 구하는 예쩨제
양의 정수 N이 입력으로 주어질 경우 1 부터 N 까지 합을 반환하는 함수 sum(n)을 작성하시오

int sum(int n)

if(n != 0){
return n + sum(n - 1);
}

ㅇ재귀함수 특징
-모든 재귀 함수는 반복문을 사용하는 함수로 변환이 가능하다.

재귀함수에서의 시간 복잡도에서는 O(n)
반복문으로 해버리면 O(n)


ㅇ장점, 단점
장점 : 코드를 간결하게 작성 가능
단점 : 디버깅이 어렵다, 스택 오버플로우 주의, 반복문 사용 코드보다 낮은 효율

ㅇ재귀함수와 반복문 사용 함수의 연산 시간 비교를 해보자
1부터 n 까지 자연수의 합을 재귀 방법과 반복문 사용 방법으로 각각 계산해서 실행시간을 비교해보니
n값은 1부터 20000변환시키면서 입력을 전달 했음

여러번 함수 호출에 의한 오버헤드가 발생해서 더 느리다 재귀함수가

*/


int sum(int n, int* res) {

//	if (n == 1) // 기저조건
	//	return 1;
	//else
	//	return n + sum(n - 1); //
	static int count = 0;
	int result = 0;


	if (n < 2) return result;  
	if (n % 3 == 0) {
		result = sum(n - 1, res) + n; 
		count++;  
	}
	else {
		result = sum(n - 1, res);

	}

	*res = result + count;
	return result;
	//if (n != 0) return n + sum(n - 1);
	//return n;
}

int main() {
	int result = 0, sum2;
	sum2 = sum(5, &result);
	printf("1) %d, %d\n", sum2, result);
	sum2 = sum(6, &result);
	printf("2) %d, %d\n", sum2, result);
	sum2 = sum(8, &result);
	printf("3) %d, %d\n", sum2, result);
}
