#include <iostream>

using namespace std;
/*
-반복자(iterator) 지원 추가
-특정 데이터 검색
-범용 데이터 저장을 위한 클래스 템플릿 작성

새로 추가한거는 //** 적겠음


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

		T& operator*() { return ptr->data; } // 데이터 멤버를 참조 형태로 반환하도록 짠것

		iterator& operator++() { // ++it 으로 써야함 후위로 적으면 안됨
			ptr = ptr->next;
			return *this; // 자기 자신을 참조하는 형태
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
			earse(--end()); // ** --안붙히면 트레일러 지움
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

			//내가 찾고하자는 값을 찾거나, 찾지 못했을 경우 return이 되는데 그래서 트레이너와 같은지 다른지 체크해줘야한다.
			//end()하고 같으면 안된다는것
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