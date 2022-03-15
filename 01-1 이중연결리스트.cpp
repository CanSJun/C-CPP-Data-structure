#include <iostream>

using namespace std;
/*
�����Ḯ��Ʈ ����
1. �ܼ����Ḯ��Ʈ(singly linked list)
-���� ��忡 ���� ��ũ�� ������ �ִ� ���Ḯ��Ʈ
-���� �������θ� ��ȸ�� ����(�ܹ��� ���Ḯ��Ʈ)

2. ���� ���� ����Ʈ(doubly linked list)
-���� ���� ���� ��忡 ���� ��ũ�� ������ �ִ� ���Ḯ��Ʈ
-����� ��ȸ�� ����(����� ���Ḯ��Ʈ)

3. ���� ���� ����Ʈ(circular linked list)
-�Ϲ����� ���� ����Ʈ�� ������ ��� ��ũ�� ó�� ��带 ����Ű���� ������ �ڷ� ����.
-ó�� ��尡 �ٽó�Ÿ���� ��ȸ�� ����


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
���߿��� ����Ʈ�� �� ����
��(�ܼ� ���� ����Ʈ ���) ���� ���Ḯ��Ʈ�� ����
-����� ��ũ�� ������ �ֱ� ������ ��������� �˻� ����

��(�ܼ� ���� ����Ʈ ���) ���� ���Ḯ��Ʈ�� ����
1.���� ��� ��ũ�� ���� ������ ���� ���
2.�������� ���԰� ���� ������ �� ����

*/