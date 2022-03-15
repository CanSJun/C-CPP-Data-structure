#include <iostream>
#include <algorithm>
using namespace std;

/*
std::sort
<algorithm>에 정의되어 있음

template <class RandomIt>
void sort(RandomIt first, RandomIt last);

template <class RandomIt>
void sort(RandomIt first, RandomIt last, Compare comp);

순차컨테이너에서 frist, last 범위의 원소들을 정해진 방법으로 정렬(기본값 :오름차순)
하지만 같은 값을 갖는 원소의 순서는 보장되지 않는다( 안정된 형태로 수행하고 싶으면 std::Stable_sort()함수 이용 - 약간 느림)
std::sort()는 O(nlogn)으로 동작해야함

c스타일배열, vector,deque,array 같은 컨테이너를 정렬 할 수 있고
lst,forward_list는 자체 멤버 함수 사용한다.

comp인자에 비교함수 객체를 전달할 수 있다.


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

	sort(arr, arr + 5); // 오름차순 [1,2,3,4,5]

	vector<string> vec = { "orange", "banana", "apple", "lemon" };
	sort(vec.begin(), vec.end()); // 오름차순으로 정렬 된다.

	sort(begin(arr), end(arr)); // 가능하다 std::begin(), std::end() c++ 11 부터 가능 


	//내림차순으로 하고 싶다.

	sort(begin(arr), end(arr), greater<>()); // 내림차순으로 된다
	sort(vec.begin(), vec.end(), greater<>()); // 내림차순

	// 함수 포인터
	vector<int> nums = { 10, 2, -3, 5, 7 }; // 절대값으로 취한 상태로 하고싶다

	sort(nums.begin(), nums.end(), abs_cmp); //오름차순으로 정렬돼서 2, -3 , 5 , 7 , 10 이 된다
	// -> 다른방식으로도 가능하다 함수객체(functor)을 이용해서
	sort(nums.begin(), nums.end(), abscmp());

	//람다 표현식
	sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) < abs(b); });

	//오버로딩한 객체의 정렬
	vector<person> v;
	v.push_back({ "test", 10 });
	v.push_back({ "abc", 20 });
	v.push_back({ "sdg", 30 });
	sort(v.begin(), v.end());
}