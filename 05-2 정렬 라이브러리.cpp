#include <iostream>
#include <algorithm>
using namespace std;

/*
std::sort
<algorithm>�� ���ǵǾ� ����

template <class RandomIt>
void sort(RandomIt first, RandomIt last);

template <class RandomIt>
void sort(RandomIt first, RandomIt last, Compare comp);

���������̳ʿ��� frist, last ������ ���ҵ��� ������ ������� ����(�⺻�� :��������)
������ ���� ���� ���� ������ ������ ������� �ʴ´�( ������ ���·� �����ϰ� ������ std::Stable_sort()�Լ� �̿� - �ణ ����)
std::sort()�� O(nlogn)���� �����ؾ���

c��Ÿ�Ϲ迭, vector,deque,array ���� �����̳ʸ� ���� �� �� �ְ�
lst,forward_list�� ��ü ��� �Լ� ����Ѵ�.

comp���ڿ� ���Լ� ��ü�� ������ �� �ִ�.


*/
#include <vector>


bool abs_cmp(const int a, const int b) {
	return abs(a) < std::abs(b);
}

struct abscmp {
	bool operator()(int a, int b) const {
		return abs(a) < abs(b);
	}
};
class person {
public:
	string anme;
	int age;

	bool operator<(const person& a)const
	{
		return this->age < a.age;
	}

};

int main() {
	int arr[5] = { 4 , 2, 3, 5 ,1 };

	sort(arr, arr + 5); // �������� [1,2,3,4,5]

	vector<string> vec = { "orange", "banana", "apple", "lemon" };
	sort(vec.begin(), vec.end()); // ������������ ���� �ȴ�.

	sort(begin(arr), end(arr)); // �����ϴ� std::begin(), std::end() c++ 11 ���� ���� 


	//������������ �ϰ� �ʹ�.

	sort(begin(arr), end(arr), greater<>()); // ������������ �ȴ�
	sort(vec.begin(), vec.end(), greater<>()); // ��������

	// �Լ� ������
	vector<int> nums = { 10, 2, -3, 5, 7 }; // ���밪���� ���� ���·� �ϰ�ʹ�

	sort(nums.begin(), nums.end(), abs_cmp); //������������ ���ĵż� 2, -3 , 5 , 7 , 10 �� �ȴ�
	// -> �ٸ�������ε� �����ϴ� �Լ���ü(functor)�� �̿��ؼ�
	sort(nums.begin(), nums.end(), abscmp());

	//���� ǥ����
	sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) < abs(b); });

	//�����ε��� ��ü�� ����
	vector<person> v;
	v.push_back({ "test", 10 });
	v.push_back({ "abc", 20 });
	v.push_back({ "sdg", 30 });
	sort(v.begin(), v.end());
}