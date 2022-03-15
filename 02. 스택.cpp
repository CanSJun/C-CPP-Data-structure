#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
������
-�����͸� �������� �����ϴ� ��������.
-���Լ���(LIFO) �����̴� : ���߿� ���°� ���߿� ������.
-������ ������� ���� ���⿡���� ����Ǵ� ����Ʈ�̴�.

���ֿ� ����
push(e) : ������ �� ���� ���� e�� �߰�
pop() : ������ �� ���� �ִ� ���Ҹ� ����
top() : ������ �� ���� �ִ� ���Ҹ� ����. ( peek() ��� ��)
empty() : ������ ����ֳ�, ������ ��������� true �� ��ȯ
size() : ���ÿ� � ��Ұ� �ֳ� , ���� ��ȯ��

���迭�� �̿��� ������ ����
-�̸� ������ ũ���� �迭�� �Ҵ��ϰ�, ���� �ֱٿ� �Էµ� �ڷ� ��ġ�� ����Ű�� t������ ���
push(e) : t���� 1 ������Ű�� ,�ش���ġ�� e�� ����
pop : t���� 1 ����
top : arr[t]���� ��ȯ

���� : ������ �����ϰ� ,�����̳� ������ ������ ����
���� : �̸� ������ ũ�⺸�� ���� �����͸� �����ϸ� ���� �����÷ο찡 �߻��Ѵ�

�����Ḯ��Ʈ�� �̿��� ������ ����
1. �ܼ����� ����Ʈ�� �̿��Ͽ� ���� �߰��� �����͸� ���Ḯ��Ʈ �� �տ� �����ϴ� ���.
push(e) : push_first(e)
pop : pop_first()
top() : head->next ��ȯ

���������� 10 20 30
head 30 20 10 �̷�����

���� : ũ�Ⱑ ���ѵ��� �ʴ´�
���� : ������ �����ϰ�, �����̳� ���� �ð��� (�迭�� ����)���� �ɸ���.
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

	//�ð����⵵ O(1)
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
	//���佺��
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
std::stack ��� �����ϴ�.
template<class T, class container = std::deque<T>>
class stack;

-���ø� �Ű����� T�� ���ÿ� ������ Ÿ���� �����ϰ�, �����̳ʿ��� ���ο��� ����� �����̳ʸ� �����Ѵ�
-�����̳ʿ��� deque, vector, list�� ������ �� ����
-<stack>�� ���ǵǾ� �ִ�.

*/