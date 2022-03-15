#include<iostream>

using namespace std;

/*
��set, map
set : Ű(key)�� ����
map : Ű(key)�� ��(value)�� ����

��set�� multiset ����
set : ������ Ű�� �����͸� ����(�ߺ� ��� X)
multiset : �ߺ��Ǵ� ������ ���� 

��set�� unordered_set ����
set : ���ο��� �����͸� �����ؼ� ����
unordered_set : �����͸� �������� ����.

��set
template<class key, lcass compare = std::less<key> , class allocator = std::allocator<key>>
class set

-Key Ÿ���� Ű���� �����ϴ� ���� �����̳�
-����� �����ʹ� ������������ ���ĵȴ�
-������ ����, ����, Ž���� O(log n) �ð� ���⵵�� �����Ѵ�.
-���� red-black tree�� �̿��� �����ȴ�.
-���� �ߺ��Ǵ� �����͸� set ������ �����ҷ��� std::multiset �����̳� �̿�
-�����͸� ���� ���� ���� ���·� ���������� std::unordered_set �����̳� ����Ѵ�.
-����� ���� Ÿ���� ������ ��� ,�� ������ ���� �Ͽ����Ѵ�
<set>�� ���� �Ǿ��ִ�

*/

/**/
#include <set>
#include <map>
/*
��map �����̳�
template<class key,class T, cass compare = std::less<key> , class allocator = std::allocator<key>>
class map
-keyŸ���� Ű�� TŸ���� value�� ���� �����ϴ� ���� �����̳�
-����� �����ʹ� Ű ���� �������� ���� �ȴ�
-������ ����, ����, Ž���� O(log n) �ð� ���⵵�� �����Ѵ�.
-red-black tree�� �̿��Ͽ� �����ȴ�
-�ߺ� �����͸� �����ҷ��� multimap �����̳� �̿�
-�������� �������·� �����Ҳ��� unordered_map �����̳� ����
-����� ���� Ÿ���� ������ ��� �� ������ �����ؾ���
<map>�� ���� �Ǿ�����

*/

/*
int main() {
	set<int> odds{ 1, 7, 5, 3 ,9 };
	set<int, greater<>> evens{ 2,4,6,8 }; // ��������
	//odds.insert(1);
	//odds.insert(7);
	//odds.insert(5);
	//odds.insert(3);
	//odds.insert(9);

	for (auto n : odds) cout << n << " , ";
	cout << endl;

	if (evens.find(4) != evens.end()) { // �� ��� 4��� ���� ����ֵ��� ��
		//�ƴϸ� end���� ����.

	}
	else {
		//������ 4�� ã�� ���ߴ�.
	}

	set<pair<string, int>> managers{ {"amelia", 29}, {"Noah", 25 }, {"olivia", 31} }; // �� ������ Ÿ�Կ� ���ڿ��� ���� ���� �����Ѵ� 
	managers.insert(make_pair("gg", 35)); // �̷��� �ص� �ȴ�

	pair<string, int> person1 = { "Noah", 25 };
	if (managers.find(person1) != managers.end()) {
		//�̷��� ��� 25 ã��
	}
	else {
		//�ƴϸ� ��ã��
	}

	//�����ϴ°�
	managers.erase({ "Noah", 25 });
	for (const auto& m : managers)cout << m.first << " ( " << m.second << " ) " << endl;
	//�̸��� ���� ��� 


	//��map
	map<string, int> fruits;
	fruits.insert({ "apple", 1000 });
	fruits.insert({ "banana", 1500 });
	//���������� string�������� ������ �ȴ�.
	for (const auto& p : fruits)
		cout << p.first << " is " << p.second << " won." << endl;
	//���ȣ ������ ������
	cout << fruits["apple"] << endl; // 1000�� ����
	fruits["orange"]; // �ϸ� oreange�� �����ǰ� value�� 0���� ���� ��
	fruits["grape"] = 3000; // grape�� �����ϰ� value�� 3000�� �߰��Ѵ�
	fruits["apple"] = 5000; // ��������� 1000������ 5000������ ����

	fruits.erase("apple"); // ��� ���� 

	//c++ 17���ʹ� 
	//for (auto [name, price] : fruits)
	//	cout << name << " is " << price << " won. " << endl;
	//�����ϴ�
}

*/