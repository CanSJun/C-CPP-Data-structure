#include <iostream>
#include<list>
#include <queue>
using namespace std;

/*
ㅇQueue
-자료구조에서 큐는 데이터를 마치 줄을 세워 늘여 놓듯이 저장하는 성형 자료 구조이다.
-선입선출(FIFO) 원리에 따라 삽입과 삭제가 수행된다.
-데이터 삽입은 뒤쪽(rear)에서, 데이터 삭제는 앞쪽(front)에서 수행되는 list이다.
즉 삽입은 뒤쪽에서 ,삭제는 앞쪽에서 일어난다.

ㅇ주요연산
enqueue(e) : 큐의 rear에 원소 e를 추가한다. (push(e) 를 사용해도 된다)
dequeue() : 큐의 front에 있는 원소를 삭제한다 (pop()을 사용해도 된다)
front() : 큐의 맨 앞에 있는 원소를 참조하는 것 (peek()으로 연산 가능)
empty() : 큐바 비어있으면 true를 반환, 아니면 false
size() : 큐의 원소 개수를 반환.

ㅇ배열을 이용한 큐의 구현
-미리 정해진 크기의 배열을 할당하고, 큐의 앞과 뒤를 나타내는 front와 rear변수를 사용한다.
enqueue(e) : rear값을 1 증가 시키고, 해당 위치 (arr[rear])에 e를 대입
dequeue(): : front 값을 1 증가 시킨다.
front(): arr[front]값을 반환한다.

ㅇ연결리스트를 이용한 큐의 구현
-이중 연결 리스트를 이용하며, 새로 추가한 데이터를 연결 리스트 맨 앞에 삽입하는 방식
enqueue(e) : push_back(e)
dequeue() : pop_front()
front() : head->next 값을 반환


ㅇ클래스 template queue
template<class T, class container = std::deque<T>>
class queue
<queue>에 정의되어있음

주요 멤버 함수는
queue::push(e)
queue::pop()
queue::front()

*/
//std::list를 이용한 큐의 구현



template<typename T>
class Queue {
public:
	Queue() {}
	
	void enqueue(const T& e) { lst.push_back(e); }
	void dequeu() { lst.pop_front(); }
	const T& front() const { return lst.front(); }

	bool empty() const { return lst.empty(); }
	int size() const { return lst.size(); }

private:
	list<T> lst;
};

int main() {
	Queue<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);

	q.dequeu();

	cout << q.front() << endl;
	q.enqueue(40);

	while (!q.empty()) {
		auto& e = q.front();
		cout << e << endl;
		q.dequeu();
	}

	cout << endl;
	queue<int> test;
	test.push(10);
	test.push(20);
	test.push(30);
	test.pop();

	while (!test.empty()) {
		auto& e = test.front();
		cout << e << endl;
		test.pop();
	}

}
