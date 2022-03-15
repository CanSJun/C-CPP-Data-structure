#include <iostream>
#include<list>
#include <deque>

using namespace std;

/*
ㅇ양방향 큐(deque)란?
-삽입과 삭제가 양쪽끝에서 모두 가능한 구조

ㅇ주요 연산
push_front(E) : 양방향 큐의 맨 앞에 원소 E를 추가
pop_front(): 양방향 큐의 맨 앞에 있는 원소를 삭제

push_back(e): 양방향 큐의 맨 뒤에 원소 E를 추가
pop_back: 양방향 큐의 맨 뒤에 있는 원소를 삭제

front()
back()

empty()
size()


ㅇ배열을 이용한 양방향 큐의 구현
-환형 큐와 비슷한 방식으로, 양방향 큐의 맨 앞과 맨 마지막 위치를 갱신

ㅇ연결리스트로도 가능
이중연결 리스트를 이용하여 연결 리스트 맨 앞과 맨 뒤에 자료를 각각 추가 & 삭제 가능

ㅇdeque
template<class T, class allocator = std::allocator<T>>
class deque;
-양방향 큐의 동작을 지원하는 순차컨테이너
-<deque>에 저장되어잇음

-특징
원소에 대해 임의 접근 동작이 O(1) 시간 복잡도로 동작
맨앞과 맨뒤에 자료를 추가 또는 삭제하는 연산이 O(1)시간 복잡도로 동작
그렇지만 중간 위치에서 자료를 삽입 또는 삭제는 O(n) 시간 복잡도로 동작(n은 원소갯수)

std::stack과 std:queue등의 STL컨테이너 어댑터의 기본 컨테이너로 사용한다.


*/

int main() {

	deque<int> d{ 10, 20, 30 ,40};
	d.push_front(50);
	d.push_back(60);

	for (auto& i : d) {
		cout << i << ", ";

	}
	cout << endl;


}