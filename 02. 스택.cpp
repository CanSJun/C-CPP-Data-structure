#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
ㅇ스택
-데이터를 차곡차곡 서장하는 선형형태.
-후입선출(LIFO) 형태이다 : 나중에 들어온게 나중에 나간다.
-데이터 입출력이 한쪽 방향에서만 수행되는 리스트이다.

ㅇ주요 연산
push(e) : 스택의 맨 위에 원소 e를 추가
pop() : 스택의 맨 위에 있는 원소를 삭제
top() : 스택의 맨 위에 있는 원소를 참조. ( peek() 라고도 함)
empty() : 스택이 비어있냐, 스택이 비어있으면 true 를 변환
size() : 스택에 몇개 요소가 있냐 , 갯수 반환함

ㅇ배열을 이용한 스택의 구현
-미리 정해진 크기의 배열을 할당하고, 가장 최근에 입력된 자료 위치를 가르키는 t변수를 사용
push(e) : t값을 1 증가시키고 ,해당위치에 e를 대입
pop : t값을 1 감소
top : arr[t]값을 변환

장점 : 구현이 간단하고 ,삽입이나 삭제가 빠르게 가능
단점 : 미리 정해진 크기보다 많은 데이터를 삽입하면 스택 오버플로우가 발생한다

ㅇ연결리스트를 이용한 스택의 구현
1. 단순연결 리스트를 이용하여 새로 추가한 데이터를 연결리스트 맨 앞에 삽입하는 방식.
push(e) : push_first(e)
pop : pop_first()
top() : head->next 반환

넣은순서는 10 20 30
head 30 20 10 이런식임

장점 : 크기가 제한되지 않는다
단점 : 구현이 복잡하고, 삽입이나 삭제 시간이 (배열에 비해)오래 걸린다.
*/


template <typename T>
class Stack {


public:
	Stack() {

	}
	void push(const T& e) {
		v.push_back(e);
	}
	void pop() {
		v.pop_back();
	}
	const T& top() const {
		return v.back();
	}

	bool empty() const {
		return v.empty();
	}
	int size() const { return v.size(); }

	//시간복잡도 O(1)
private:
	vector<T> v;
};

int main() {

	Stack<int> test;
	test.push(10);
	test.push(20);
	test.push(30);
	test.pop();
	
	cout << test.top() << endl;

	test.push(40);
	cout << test.top() << endl;

	
	while (!test.empty()) {
		auto& e = test.top();
		cout << e << ", ";
		test.pop();
	}
	cout << endl;
	//여긴스택
	stack<int> test2;
	test2.push(50);
	test2.push(60);
	test2.push(70);
	test2.push(80);
	test2.pop();

	cout << test2.top() << endl;

	while (!test2.empty()) {
		auto& e = test2.top();
		cout << e << ", ";
		test2.pop();
	}
	cout << endl;

}



/*
std::stack 사용 가능하다.
template<class T, class container = std::deque<T>>
class stack;

-템플릿 매개변수 T는 스택에 저장할 타입을 지정하고, 컨테이너에는 내부에서 사용할 컨테이너를 지정한다
-컨테이너에는 deque, vector, list를 지정할 수 있음
-<stack>에 정의되어 있다.

*/