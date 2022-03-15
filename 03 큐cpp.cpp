#include <iostream>
#include<list>
#include <queue>
using namespace std;

/*
��Queue
-�ڷᱸ������ ť�� �����͸� ��ġ ���� ���� �ÿ� ������ �����ϴ� ���� �ڷ� �����̴�.
-���Լ���(FIFO) ������ ���� ���԰� ������ ����ȴ�.
-������ ������ ����(rear)����, ������ ������ ����(front)���� ����Ǵ� list�̴�.
�� ������ ���ʿ��� ,������ ���ʿ��� �Ͼ��.

���ֿ俬��
enqueue(e) : ť�� rear�� ���� e�� �߰��Ѵ�. (push(e) �� ����ص� �ȴ�)
dequeue() : ť�� front�� �ִ� ���Ҹ� �����Ѵ� (pop()�� ����ص� �ȴ�)
front() : ť�� �� �տ� �ִ� ���Ҹ� �����ϴ� �� (peek()���� ���� ����)
empty() : ť�� ��������� true�� ��ȯ, �ƴϸ� false
size() : ť�� ���� ������ ��ȯ.

���迭�� �̿��� ť�� ����
-�̸� ������ ũ���� �迭�� �Ҵ��ϰ�, ť�� �հ� �ڸ� ��Ÿ���� front�� rear������ ����Ѵ�.
enqueue(e) : rear���� 1 ���� ��Ű��, �ش� ��ġ (arr[rear])�� e�� ����
dequeue(): : front ���� 1 ���� ��Ų��.
front(): arr[front]���� ��ȯ�Ѵ�.

�����Ḯ��Ʈ�� �̿��� ť�� ����
-���� ���� ����Ʈ�� �̿��ϸ�, ���� �߰��� �����͸� ���� ����Ʈ �� �տ� �����ϴ� ���
enqueue(e) : push_back(e)
dequeue() : pop_front()
front() : head->next ���� ��ȯ


��Ŭ���� template queue
template<class T, class container = std::deque<T>>
class queue
<queue>�� ���ǵǾ�����

�ֿ� ��� �Լ���
queue::push(e)
queue::pop()
queue::front()

*/
//std::list�� �̿��� ť�� ����



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
