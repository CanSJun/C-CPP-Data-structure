#include<iostream>
#include<vector>
using namespace std;

/*


 ㅇ 힙에서 원소 삭제
 -힙의 맨 마짐가 노드 값을 루트노드로 복사하고, 맨 마지막 노드를 삭제한다.
 -루트 노드와 두 자식을 비교하여 힙속성을 만족하지 않으면 두 자식 노드중에서 현재 힙에 맞게
 서로 교환하는 과정을 반복한다.


			15
		8		 14
	7	   4   9   10
  5  2    3

  -삭제를 시행 하면 맨 마지막 노드를 복사하고 삭제

			3
		8		 14
	7	   4   9   10
  5  2    

  최대힙 속성을 만족못함. 비교해서 이동한다

			3
		8		 14         //8을 바꾸면 8과 14서로 힙속성을 못마주니깐.[왜냐 8도 14보다 작음] 두개 자식노드중에서 큰값과 비교해서 바꾼다
	7	   4   9   10
  5  2    

			14
		8		 3
	7	   4   9   10
  5  2

			14
		8		 10
	7	   4   9   3
  5  2


*/

class MaxHeap
{
private:
	vector<int> vec;

public:
	MaxHeap() : vec(1) { }

	void push(int value) {
		vec.push_back(value);
		heapify_up(vec.size() - 1);
	}
	void pop() {
		vec[1] = vec.back(); // 맨 마지막 엘리먼트 참조
		vec.pop_back(); // 맨 마지막 노드 삭제
		heapify_down(1);

	}
	int top() const { return vec[1]; }
	int size() { return vec.size() - 1; }
	bool empty() { return vec.size() == 1; }

private:
	int parent(int i) { return i / 2; }
	int left(int i) { return 2 * i; }
	int right(int i) { return 2 * i + 1; }
	void heapify_up(int i) {
		if (i > 1 && vec[i] > vec[parent(i)]) { // i가 루트노드면 굳이 할 필요없으니깐 .
			swap(vec[i], vec[parent(i)]);
			heapify_up(parent(i));
		}
	}
	void heapify_down(int i) {
		int largest = i;

		if (left(i) < vec.size() && vec[left(i)] > vec[largest]) largest = left(i);
		if (right(i) < vec.size() && vec[right(i)] > vec[largest]) largest = right(i);

		if (largest != i) {
			swap(vec[i], vec[largest]);
			heapify_down(largest);
		}

	}

	/*
	int main() {
		MaxHeap heap;
		heap.push(10);
		heap.push(5);
		heap.push(15);
		heap.push(7);
		heap.push(3);
		heap.push(9);
		heap.push(14);
		heap.push(8);
		heap.push(2);
		heap.push(4);

		while (!heap.empty()) {
			cout << heap.top() << ", ";
			heap.pop();
		}
		cout << endl;
	}*/

};