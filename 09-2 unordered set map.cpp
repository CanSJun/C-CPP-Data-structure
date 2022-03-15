#include <iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

/*
��unordered_Set �����̳�
-keyŸ���� Ű ���� �����ϴ� �������� ���������̳�
-������ ����, ���� Ž���� O(1) �ð� ���⵵�� �����Ѵ�
-���࿡ �ߺ��Ǵ� �����͸� unordered_set������ �����ҷ��� unordered_multiset ����Ѵ�.
-����� ���� Ÿ���� ������ ��� ,�� ���Լ� Hash�� �񱳸� ���� keyEqual�� �����ؾ� �Ѵ�.
<unordered_set>�� ���� �Ǿ� �ִ�.

��unordered_map �����̳�
-Key Ÿ���� Ű�� T Ÿ���� ��(value)�� ���� �����ϴ� �������� ���� �����̳��̴�
-������ ����, ���� ,Ž���� O(1) �ð� ���⵵�� �����ؾ��Ѵ�.
-���� �ߺ��Ǵ� ������ unordered_map ������ �����ҷ��� unorderded_multimap�� ����Ѵ�
-����� ������ Ÿ���� ������ ��� ,�ؽ� �Լ� Hash�� �񱳸� ���� KeyEqual�� �����ؾ��Ѵ�.
<unordered_map>�� ���� �Ǿ� ����

*/


int main() {
	unordered_set<string> words;
	words.insert("car");
	words.insert("radio");
	words.insert("orange");
	words.insert("ear");
	
	string word = "radio";
	if (words.find(word) != words.end()) cout << word << " is used!" << endl;
	else cout << word << " is not used" << endl;

	//�ߺ��������� �� ����
	vector<int> numbers{ 1,5,3,1,5,7,4,5,6,3,2,7,3,6,2 };
	unordered_set<int> num_set(numbers.begin(), numbers.end()); // �ݺ��ڸ� ������ �μ��� ���� // ������ �����ϰ� �ȴ� 1, 1���� 1 ���ڲ� ����
	cout << num_set.size() << endl; // �̷��� �ߺ����� �����͵� ������

	unordered_map<string, int> fruits;
	fruits.insert({ "apple", 1000 });
	fruits.insert({ "banana", 1500 });

	for (const auto& p : fruits)
		cout << p.first << " is " << p.second << " won." << endl;

	cout << fruits["apple"] << endl;
	fruits["orange"];
	fruits["grape"] = 3000; 
	fruits["apple"] = 5000;
	fruits.erase("apple"); 
	// map�̶� �ٸ��� ������ ������ ����� �ȴ� map�� ������ �ż� ���´�. 
}