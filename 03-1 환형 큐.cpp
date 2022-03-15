#include <iostream>
#include<list>
#include <queue>

#define MAX_QUEUE 10

using namespace std;
/*

ㅇ배열에서 데이터 하나만있는 경우
0에 front, rear이다.

ㅇ큐의 초기상태는 
front = 0
rear = -1


ㅇ배열을 이용한 큐의 구현에 문제점
-큐에 데이터를 삽입, 삭제가 지속적으로 발생한 경우, 미리 할당해놓은 배열의 앞 부분에는 무효화되는 공간이 늘어난다.

이러한 현상을 rightward drift라고 한다.

이러한 단점을 보완하기 위해서 원형의 형태로 구현하는 환형큐라는 기법을 사용한다.
-선입선출 원칙에 따라 작업이 수행되고 , 마지막 위치가 마치 원을 이루듯이 다시 첫번째 위치와 연결되는 선형데이터 구조이다

-큐의 front와 rear값이 시계방향으로 한칸씩 이동하는 형태
->실제 구현에서는 배열 전체 크기를 이용하여 나머지 연산을 수행한다.
8이라면 7값에서 rear++; front++; 에서 %8를 해준다.
-큐가 empty또는 full상태인지를 확인하기 위해 원소의 개수를 따로 저장해야한다!


즉 rear = (rear + 1 ) % capacity;를 해준다. 이걸 단순히 rear++; 시켜서 if문줘서
if(rear>=capcity) rear = 0; 으로 설정하면 된다.

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