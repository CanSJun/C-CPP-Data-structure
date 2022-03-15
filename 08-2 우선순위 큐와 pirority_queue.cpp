#include<iostream>
#include<queue>
using namespace std;


/*
ㅇ우선순위 큐(priority_queue);
-각각의 데이터에 우선순위(priority)가 정의되어 있어서, 데이터 입력 순서에 상관없이 우선순위가 가장 높은 데이터가 먼저 출력되는 형태의 자료구조이다.
-일반 선입선출(FIFO) 큐 : 큐에 머무른 시간을 우선순위로 설정하면. 일반 큐와 같이 동작하게 된다.

ㅇ우선순위 큐 구현 방법

구현방법						삽입						삭제
순서없는 배열				O(1)-배열의 맨마지막             O(n) 
순서 없는 연결리스트		O(1)-순차탐색을 해야하기 때문	O(n)
정렬된 배열					O(n)-이진탐색으로 찾을 수 있음	O(1)
정렬된 연결리스트			O(n)-선형,순차탐색	     		O(1)
힙							O(log n)						O(log n)

ㅇpriority_queue
<queue>에 저장 되어있음

template < class T, class container = std::vector<T>, class Compare = std:less<T>>
class priority_queue

-우선순위 큐의 기능을 제공하는 컨테이너 어댑터이다
-삽입 순서에 상관없이 우선순위가 가장 높은(기본적으로 값이 가장 큰) 원소가 먼저 출력된다
-사용자 정의 타입을 저장할 경우, 비교연산을 지원해야함.

-주요 멤버함수
priority_queu::push(e) -- 우선순위 큐에 원소 e를 추가 O(log n)
priority_queu::pop() --- 우선순위 큐의 최상위 원소를 제거 O(log n)
priority_queu::top() ---- 우선순위 큐의 최상위 원소를 참조 O(1)

*/

/*
template<typename T>
void print_queue(T q) { // 참조가아니니 복사해서 출력한다해도 원래애들은 변경되지 않음.

	while (!q.empty()) {
		cout << q.top() << " , ";
		q.pop();
	}
	cout << endl;
}

class student {

public:
	string name;
	int score;

	bool operator < (const student& st) const {
		return score < st.score;
	}
};
int main() {

	vector<int> vec{ 4,2,3,5,1 };
	priority_queue<int> pq1(vec.begin(), vec.end()); // 큰값이 우선순위가 높다
	priority_queue<int,vector<int>,greater<int>> pq2(vec.begin(), vec.end()); // 작은값이 우선순위가 된다
	print_queue(pq1);
	print_queue(pq2);

	priority_queue<student> students;
	students.push({ "A" ,80 });
	students.push({ "B" ,40 });
	students.push({ "C" ,95 });
	students.push({ "D" ,70 });
	//비교를위한 객체가 필요하다 부등호 오버로딩 필요
	while (!students.empty()) {
		auto& s = students.top();
		cout << s.name << " ( " << s.score << " )" << endl;
		students.pop();
	}


}*/