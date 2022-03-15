#include <iostream>

using namespace std;
/*
-�ݺ���(iterator) ���� �߰�
-Ư�� ������ �˻�
-���� ������ ������ ���� Ŭ���� ���ø� �ۼ�

���� �߰��ѰŴ� //** ������


*/


template<typename T> // **
struct Node {
	T data;
	Node* prev;
	Node* next;
};

template<typename T> // **
struct linkedNode {
public:

	class iterator { //**
	public:
		iterator() : ptr(NULL){}
		iterator(Node<T> *p) : ptr(p){}

		T& operator*() { return ptr->data; } // ������ ����� ���� ���·� ��ȯ�ϵ��� §��

		iterator& operator++() { // ++it ���� ����� ������ ������ �ȵ�
			ptr = ptr->next;
			return *this; // �ڱ� �ڽ��� �����ϴ� ����
		}
		iterator& operator--() {//--it
			ptr = ptr->prev;
			return *this;
		
		}

		bool operator ==(const iterator& it) const {
			return ptr == it.ptr;
		}
		bool operator !=(const iterator& it) const {
			return ptr != it.ptr;
		}


		friend class linkedNode;
	private : 
		Node<T>* ptr;

	};


	linkedNode<T>() {
		count = 0;
		head = new Node<T>{ T(), NULL, NULL};
		tail = new Node<T>{ T(), NULL, NULL};
		head->next = tail;
		tail->prev = head;
	}
	~linkedNode<T>() {
		while (!empty())
		{
			pop_front();
		}
		delete head;
		delete tail;
	}

	iterator begin() const {//**
		return iterator(head->next);
	}	
	iterator end() const {//**
		return iterator(tail);
	}


	//void insert(Node<T>* p, int val) {
	//	Node<T>* new_Node<T> = new Node<T>{ val, p->prev, p };
	//	new_Node<T>->prev->next = new_Node<T>;
	//	new_Node<T>->next->prev = new_Node<T>;
	//	count++;
	//}
	//**
	void insert(const iterator& pos, const T& val) {
		Node<T>* p = pos.ptr;
		Node<T>* new_Node = new Node<T>{ val, p->prev, p };
		new_Node->prev->next = new_Node;
		new_Node->next->prev = new_Node;
		count++;
	}

	void push_front(const T& val) { //**
		insert(begin(), val);
	}
	void push_back(const T& val) { // **
		insert(end(), val);

	}
	

	//void earse(Node<T>* p) {
	//	p->prev->next = p->next;
	//	p->next->prev = p->prev;
	//	delete p;
	//	count--;
	//}
	//**
	void earse(const iterator& pos) {
		Node<T>* p = pos.ptr;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		count--;
	}

	void pop_front() {
		if (!empty())
			earse(begin()); // **
	}
	void pop_back() {
		if (!empty())
			earse(--end()); // ** --�Ⱥ����� Ʈ���Ϸ� ����
	}
	bool empty() {

		return count == 0;
	}
	int size() { return count; }
	void print_all() {
		Node<T>* curr = head->next;

		while (curr != tail) {
			cout << curr->data << ",";
			curr = curr->next;
		}
		cout << endl;
	}
	void reverse_print() {
		Node<T>* curr = tail->prev;
		while (curr != head) {
			cout << curr->data << ",";
			curr = curr->prev;
		}
		cout << endl;
	}

//**
	iterator find(const T& val) {
		Node<T>* curr = head->next;
		while (curr->data != val && curr != tail) curr = curr->next;
			return iterator(curr);

			//���� ã�����ڴ� ���� ã�ų�, ã�� ������ ��� return�� �Ǵµ� �׷��� Ʈ���̳ʿ� ������ �ٸ��� üũ������Ѵ�.
			//end()�ϰ� ������ �ȵȴٴ°�
	}
private:
	int count;
	Node<T>* head;
	Node<T>* tail;

};

int main() {
	linkedNode<int> test;

	test.push_back(10);
	test.push_back(20);
	test.push_back(30);

	auto it = test.find(20);
	if (it != test.end()) {
		test.insert(it, 50);


		for (auto n : test) cout << n << ", ";
		cout << endl;
	}
}