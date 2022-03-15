#include <iostream>

using namespace std;

/*
순열
하노이의 탑
*/


//순열(permutation) 
// => n개의 원소로 구성된 집합이 있을 경우, 모든 원소를 서로 다른 순서로 나열하는 방법
//ex) {a,b,c} 있다면 abc , acb, bac, bca, cab , cba 이렇게 가능하다
// 즉 3!값이 된다.
//재귀 알고리즘으로 풀기 위해선, 순환적인 관계를 잘 유추 해야한다
// 예로 들어 {a,b,c,d}의 모든 순열은
// a로 시작하고 {b,c,d}의 모든 순열
// b로 시작하고 {a,c,d}의 모든 순열
// c로 시작하고 {b,a,d}의 모든 순열
// d로 시작하고 {b,c,a}의 모든 순열
// 여기서 b를 보면 b로 시작하고 {c,a}의 모든순열
//				   c로 시작하고{b,a}의 모든순열
//				  a로 시작하고 {c,b}의 모든순열

//1. 첫번쨰 원소와 모든 원소를 각각 맞바꾸는 swap연산을 진행한다
//2. 첫번쨰 원소를 제외한 나머지 원소들의 집합으로 순열 구하기.
// 그러면 또 1,2번을 또 돌게 될것이다.
#include<vector>
void print_vector(vector<int> vec) {
	for (const auto& e : vec) {
		cout << e << " ";
	}
	cout << endl;
}
void permutation(vector<int>& vec, int k) {
	if(k == vec.size() - 1){
		print_vector(vec);
		return;
	}
	for (int i = k; i < vec.size(); i++) {
		swap(vec[k], vec[i]);
		permutation(vec, k + 1); // 자기자신 호출
		swap(vec[k], vec[i]); // 순서를 원복 => 안하게되면 벡터가 0번쨰하고 1번째를 바꾼거기 때문에 0번째와 2번째를 바꾸는 형태가 된다. 
	}
}

//c++에서 <algorithm>에 next_permutation이 있다. 
// 
// next_permutation(vec.begin(), vec.end());
#include<algorithm>

void hanoi(int n, int from, int to, int by);
int main() {
	vector<int> vec{ 1,2,3,4};
	permutation(vec, 0);
	//밑에는 STL에서 제공
	sort(vec.begin(), vec.end()); // 정렬
	do {
		print_vector(vec);
	} while (next_permutation(vec.begin(), vec.end()));

	hanoi(5, 1, 2, 3);
	
}

// 하노이의 탑 
//- 퍼즐의 일종이다
// - 세개의 기둥과 이 기둥에 꽂을 수 있는 크기가 다양한 원판들이 있고,
// 처음에는 하나의 기둥에 원판들이 작은것이 위에 있도록 순서대로 쌓여있다.
// 이 원판들을 다른 비어 있는 기둥으로 이동하는게 목적이다.
// 여기서 옮길때 조건이 있다
// 1. 한번에 하나의 원판만 옮길 수 있다.
// 2. 기둥의 맨 위에 있는 원판을 다른 기둥의 맨 위로 옮길 수 있다.
// 3. 큰 원판이 작은 원판 위에 있어서는 안된다.

//3개의 기둥을 1, 2, 3번이라고 하고
// 처음 1번의 기둥에 n개의 원판이 있다고 가정하자
// 1번 기둥의 모든 원판을 3번 기둥으로 최소 횟수로 옮기는 방법을 출력하시오!
// 입출력 예
// n	answer
// 2   1->2, 1->3, 2->3
// 3   1->3, 1->2, 3->2, 1->3, 2->1, 2->3, 1->3
// 2^n - 1 번의 이동이 있어야 1번에서 3번으로 옮길 수 있다.

// hanoi(갯수, 시작, 옮길위치, 나머지 한개의 기둥번호)
// if n == 1 : from에서 to 원판으로 이동
// otherwise : hanoi(n - 1, from, by, to)
// from에서 to로 원판 이동
// hanoi(n - 1, by, to, from);
// by에서 to 이동

void hanoi(int n, int from, int to, int by) {
	if (n == 1) {
		cout << from << " -> " << to << endl;

	}
	else {
		hanoi(n - 1, from, by, to);
		cout << from << " -> " << to << endl;
		hanoi(n - 1, by, to, from);
	}
}