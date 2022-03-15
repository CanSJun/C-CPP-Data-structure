#include<iostream>
#include<queue>
using namespace std;


/*
���켱���� ť(priority_queue);
-������ �����Ϳ� �켱����(priority)�� ���ǵǾ� �־, ������ �Է� ������ ������� �켱������ ���� ���� �����Ͱ� ���� ��µǴ� ������ �ڷᱸ���̴�.
-�Ϲ� ���Լ���(FIFO) ť : ť�� �ӹ��� �ð��� �켱������ �����ϸ�. �Ϲ� ť�� ���� �����ϰ� �ȴ�.

���켱���� ť ���� ���

�������						����						����
�������� �迭				O(1)-�迭�� �Ǹ�����             O(n) 
���� ���� ���Ḯ��Ʈ		O(1)-����Ž���� �ؾ��ϱ� ����	O(n)
���ĵ� �迭					O(n)-����Ž������ ã�� �� ����	O(1)
���ĵ� ���Ḯ��Ʈ			O(n)-����,����Ž��	     		O(1)
��							O(log n)						O(log n)

��priority_queue
<queue>�� ���� �Ǿ�����

template < class T, class container = std::vector<T>, class Compare = std:less<T>>
class priority_queue

-�켱���� ť�� ����� �����ϴ� �����̳� ������̴�
-���� ������ ������� �켱������ ���� ����(�⺻������ ���� ���� ū) ���Ұ� ���� ��µȴ�
-����� ���� Ÿ���� ������ ���, �񱳿����� �����ؾ���.

-�ֿ� ����Լ�
priority_queu::push(e) -- �켱���� ť�� ���� e�� �߰� O(log n)
priority_queu::pop() --- �켱���� ť�� �ֻ��� ���Ҹ� ���� O(log n)
priority_queu::top() ---- �켱���� ť�� �ֻ��� ���Ҹ� ���� O(1)

*/

/*
template<typename T>
void print_queue(T q) { // �������ƴϴ� �����ؼ� ����Ѵ��ص� �����ֵ��� ������� ����.

	while (!q.empty()) {
		cout << q.top() << " , ";
		q.pop();
	}
	cout << endl;
}

class student {

public:
	string name;
	int score;

	bool operator < (const student& st) const {
		return score < st.score;
	}
};
int main() {

	vector<int> vec{ 4,2,3,5,1 };
	priority_queue<int> pq1(vec.begin(), vec.end()); // ū���� �켱������ ����
	priority_queue<int,vector<int>,greater<int>> pq2(vec.begin(), vec.end()); // �������� �켱������ �ȴ�
	print_queue(pq1);
	print_queue(pq2);

	priority_queue<student> students;
	students.push({ "A" ,80 });
	students.push({ "B" ,40 });
	students.push({ "C" ,95 });
	students.push({ "D" ,70 });
	//�񱳸����� ��ü�� �ʿ��ϴ� �ε�ȣ �����ε� �ʿ�
	while (!students.empty()) {
		auto& s = students.top();
		cout << s.name << " ( " << s.score << " )" << endl;
		students.pop();
	}


}*/