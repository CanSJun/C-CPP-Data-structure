#include <iostream>

using namespace std;
/*
ㅇ연결리스트 종류
1. 단순연결리스트(singly linked list)
-다음 노드에 대한 링크만 가지고 있는 연결리스트
-한쪽 방향으로만 순회가 가능(단방향 연결리스트)

2. 이중 연결 리스트(doubly linked list)
-이전 노드와 다음 노드에 대한 링크를 가지고 있는 연결리스트
-양방향 순회가 가능(양방향 연결리스트)

3. 원형 연결 리스트(circular linked list)
-일반적인 연결 리스트의 마지막 노드 링크가 처음 노드를 가르키도록 구성된 자료 구조.
-처음 노드가 다시나타나면 순회를 멈춤


*/


struct Node {
	int data;
	Node* prev;
	Node* next;
};
struct linkedNode {
public:

	linkedNode() {
		count = 0;
		head = new Node{ 0, NULL, NULL };
		tail = new Node{ 0, NULL, NULL };
		head->next = tail;
		tail->prev = head;
	}
	~linkedNode(){
		while (!empty())
		{
			pop_front();
		}
		delete head;
		delete tail;
	}

	void insert(Node* p, int val) {
		Node* new_node = new Node{ val, p->prev, p };
		new_node->prev->next = new_node;
		new_node->next->prev = new_node;	
		count++;
	}
	void push_front(int val) {
		insert(head->next, val);
	}
	void push_back(int val) {
		insert(tail, val);

	}

	void earse(Node* p){
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		count--;
	}


		void pop_front() {
			if (!empty())
				earse(head->next); 
		}
		void pop_back() {
			if (!empty())
				earse(tail->prev);
		}
		bool empty() {

			return count == 0;
		}
		int size() { return count; }
	void print_all(){
		Node* curr = head->next;

		while (curr != tail) {
			cout << curr->data << ",";
			curr = curr->next;
		}
		cout << endl;
	}
	void reverse_print(){
		Node* curr = tail->prev;
		while (curr != head) {
			cout << curr->data << ",";
			curr = curr->prev;
		}
		cout << endl;
	}


private:
	int count;
	Node* head;
	Node* tail;

};

int main() {
	linkedNode test;
	test.push_back(10);
	test.push_back(20);
	test.push_back(30);
	test.print_all();

	test.pop_front();
	test.print_all();
	test.pop_back();
	test.print_all();

	test.push_back(400);
	test.push_front(100);
	test.print_all();
}


/*
이중연결 리스트의 장 단점
ㅇ(단순 연결 리스트 대비) 이중 연결리스트의 장점
-양방향 링크를 가지고 있기 때문에 양방향으로 검색 가능

ㅇ(단순 연결 리스트 대비) 이중 연결리스트의 단점
1.이전 노드 링크를 위한 여분의 공간 사용
2.데이터의 삽입과 삭제 구현이 더 복잡

*/