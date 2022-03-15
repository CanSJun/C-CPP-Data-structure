#include <iostream>
#include <list>
#include <forward_list>
using namespace std;
/*
��std::list
-���߿��� ����Ʈ�� ������ �����̳�

template<class T, class Allocator = std::allocator<T>>
class list;

-Ư�� ��ġ�� ���Ҹ� ����, �Ǵ� ������ ����ð����� ó��. �ð����⵵�� ��Ÿ���� O(1)
-�׷��� ���⼭ ��ġ�� �����Ҷ�. ����ó�� []�� ���� ���� �׼����� ������ ����
begin(), end()������ ���� ����� �ݺ��ڿ� ++, -- �����ڷ� ��ġ �̵��ؾ���

-<list>��� ������̸� include�ؾ���


��forward_list
-�ܼ����� ����Ʈ�� ������ �����̳ʴ�
-begin() �Լ��� ������ �ݺ��ڸ� ���� �� �ְ� ���� ++ ���길 �����ϴ�
-std::list���� ������ �����ϰ� ���� �޸𸮸� ����Ѵ�
-<forward_list>�� ���ǵǾ�����
*/

int main() {
	
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);

	list <int> l2 { 10, 20, 30, 40};



	l2.splice(l2.end(), l1);//l2 �� �������� l1 ��ü�� �̾� ���� l1 ���Ҵ� �Ű����� l1�ȿ� ������ ������


	l2.sort(); // ������������ ���� ��


	l2.unique(); // 10 10 20 20 �̷��� �ϳ���.
	for (auto n : l2)cout << n << ",";
	cout << endl;

	forward_list <int> l1{10, 20, 30, 40};
	l1.push_front(40);
	l1.push_front(30);

	for (auto n : l1)cout << n << " , ";
	cout << endl;

	int cnt = distance(l1.begin(), l1.end());
	printf("%d \n", cnt);

	l1.remove(40); // 40 ���δ� ������
	l1.sort();

	for (auto n : l1)cout << n << " , ";
	cout << endl;

	l1.unique();
	for (auto n : l1)cout << n << " , ";
	cout << endl;


}	