#include <iostream>
#include<list>
#include <queue>

#define MAX_QUEUE 10

using namespace std;
/*

���迭���� ������ �ϳ����ִ� ���
0�� front, rear�̴�.

��ť�� �ʱ���´� 
front = 0
rear = -1


���迭�� �̿��� ť�� ������ ������
-ť�� �����͸� ����, ������ ���������� �߻��� ���, �̸� �Ҵ��س��� �迭�� �� �κп��� ��ȿȭ�Ǵ� ������ �þ��.

�̷��� ������ rightward drift��� �Ѵ�.

�̷��� ������ �����ϱ� ���ؼ� ������ ���·� �����ϴ� ȯ��ť��� ����� ����Ѵ�.
-���Լ��� ��Ģ�� ���� �۾��� ����ǰ� , ������ ��ġ�� ��ġ ���� �̷���� �ٽ� ù��° ��ġ�� ����Ǵ� ���������� �����̴�

-ť�� front�� rear���� �ð�������� ��ĭ�� �̵��ϴ� ����
->���� ���������� �迭 ��ü ũ�⸦ �̿��Ͽ� ������ ������ �����Ѵ�.
8�̶�� 7������ rear++; front++; ���� %8�� ���ش�.
-ť�� empty�Ǵ� full���������� Ȯ���ϱ� ���� ������ ������ ���� �����ؾ��Ѵ�!


�� rear = (rear + 1 ) % capacity;�� ���ش�. �̰� �ܼ��� rear++; ���Ѽ� if���༭
if(rear>=capcity) rear = 0; ���� �����ϸ� �ȴ�.

*/


template<typename T>

class Cqueue {
public : 
	Cqueue(int sz = MAX_QUEUE) {
		arr = new T[sz];
		front_idx = 0;
		rear_idx = -1;
		count = 0;
		capacity = sz;
	}
	~Cqueue() { delete[] arr; }

	void enqueu(const T& e) {
		if (full()) {
			cout << "overflow" << endl;
			return;
		}
		rear_idx = (rear_idx + 1) % capacity;
		arr[rear_idx] = e;
		count++;
	}

	void dequeue() {
		if (empty()) {
			cout << "underflow " << endl;
			return;
		}
		front_idx = (front_idx + 1) % capacity;
		count--;
	}
	const T& front() const { return arr[front_idx]; }
	bool empty() const { return count == 0; }
	int full() const { return count == capacity; }
	int size() const { return count; }

private:
	T* arr;
	int front_idx;
	int rear_idx;
	int count;
	int capacity;

};


int main() {
	Cqueue<int> q(5);

	q.enqueu(10);
	q.enqueu(20);
	q.enqueu(30);
	q.enqueu(40);
	q.enqueu(50);
	q.dequeue();
	q.dequeue();
	q.enqueu(60);
	q.enqueu(70);

	while (!q.empty()) {
		auto& e = q.front();
		cout << e << endl;
		q.dequeue();

	}


}