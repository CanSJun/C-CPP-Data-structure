#include <iostream>

using namespace std;

/*
//
ㅇList란? : 순서를 가진 데이터를 모임이다.
ex)요일 (일요일 ,월요일, 토요일)

ㅇ리스트의 주요 연산
-원소의 참조, 삽입(insert), 삭제(remove), 검색(search)

ㅇ구현하는 방법
						배열				연결리스트
저장공간		  연속된 메모리 공간	임의의 메모리 공간
원소의 삽입&삭제	   비효율적			      효율적
구현				 	쉬움			      어려움


ㅇ연결리스트(linked list)란?
-데이터와 링크로 구성된 node가 연결되어 있는 자료구조.
데이터(data) : 정수, 문자열, 복합 자료형
링크(link, next) : 다른 노드를 가르키는 포인터
노드 : 데이터와 링크가 결합되어있는 형태. 연결리스트를 구성하는 단위

ex ) 10(data)| next-> 20(data) | next-> 30(data) |  next-> NULL

struct node{
int data;
Node* next;
};

첫번째 노드를 가르키는 Node* head; 포인터변수를 둔다.

*/

/*
struct Node {
	int data;
	Node* next;
};
class Nodelist {

public:
	Nodelist() : head(NULL){}
	~Nodelist() {
		while (!empty()) {
			pop_front();
		}
	}

	void push_front(const int val) {
		Node* new_node = new Node{ val, head };
		if (head != NULL) { //노드가 비어있지 않을경우
			new_node->next = head; // 넥스트를 이미 작성되어있는 헤드가 가르키고있는 next로 넘겨준다. 즉 head 10 20 30이면 10에다가 연결해준다는 뜻이다.
			head = new_node; // head는 뉴노드에 연결시켜준다 
		}
		else {
			new_node->next = NULL;
			head = new_node;
		}
	}
	void pop_front() {
		if (head == NULL) return;
		Node* first = head;
		head = head->next;
		delete first;
	}

	void printall() {
		Node* current = head;
		while (current != NULL) {
			cout << current->data << ", ";
			current = current->next;
		}
		cout << endl;
	}

	bool empty()
	{
		return head == NULL;
	}
private:
	Node* head;
};

int main()
{
	Nodelist test;
	test.push_front(10);
	test.push_front(20);
	test.push_front(30);
	test.printall();

	test.pop_front();
	test.printall();

	test.pop_front();
	test.printall();



}
*/


/*
장점 :
1.임의의 위치에 원소의 삽입&삭제가 효율적 : 시간 복잡도  O(1)
2.크기 제한이 없다.

단점 :
1. 임의의 원소 접근이 비효율적 : 시간 복잡도  O(N)
2. 링크를 위한 여분의 공간 사용
3. 구현이 복잡하다.

*/
