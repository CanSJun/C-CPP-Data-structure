#include<iostream>

using namespace std;

/*
ㅇset, map
set : 키(key)만 저장
map : 키(key)와 값(value)을 저장

ㅇset과 multiset 차이
set : 고유한 키의 데이터만 저장(중복 허용 X)
multiset : 중복되는 데이터 저장 

ㅇset과 unordered_set 차이
set : 내부에서 데이터를 정렬해서 저장
unordered_set : 데이터를 정렬하지 않음.

ㅇset
template<class key, lcass compare = std::less<key> , class allocator = std::allocator<key>>
class set

-Key 타입의 키값을 저장하는 연관 컨테이너
-저장된 데이터는 오름차순으로 정렬된다
-데이터 삽입, 삭제, 탐색은 O(log n) 시간 복잡도로 동작한다.
-보통 red-black tree를 이용해 구현된다.
-만약 중복되는 데이터를 set 구조로 저장할려면 std::multiset 컨테이너 이용
-데이터를 정렬 되지 않은 상태로 저장혀려면 std::unordered_set 컨테이너 사용한다.
-사용자 정의 타입을 저장할 경우 ,비교 연산을 지원 하여야한다
<set>에 정의 되어있다

*/

/**/
#include <set>
#include <map>
/*
ㅇmap 컨테이너
template<class key,class T, cass compare = std::less<key> , class allocator = std::allocator<key>>
class map
-key타입의 키와 T타입의 value의 쌍을 저장하는 연관 컨테이너
-저장된 데이터는 키 값을 기준으로 정렬 된다
-데이터 삽입, 삭제, 탐색은 O(log n) 시간 복잡도로 동작한다.
-red-black tree를 이용하여 구현된다
-중복 데이터를 저장할려면 multimap 컨테이너 이용
-정렬하지 않은상태로 저장할꺼면 unordered_map 컨테이너 저장
-사용자 정의 타입을 저장할 경우 비교 연산을 지원해야함
<map>에 정의 되어있음

*/


int main() {
	set<int> odds{ 1, 7, 5, 3 ,9 };
	set<int, greater<>> evens{ 2,4,6,8 }; // 내림차순
	//odds.insert(1);
	//odds.insert(7);
	//odds.insert(5);
	//odds.insert(3);
	//odds.insert(9);

	for (auto n : odds) cout << n << " , ";
	cout << endl;

	if (evens.find(4) != evens.end()) { // 이 경우 4라는 값이 들어있따는 것
		//아니면 end값이 나옴.

	}
	else {
		//같으면 4를 찾지 못했다.
	}

	set<pair<string, int>> managers{ {"amelia", 29}, {"Noah", 25 }, {"olivia", 31} }; // 이 데이터 타입에 문자열과 정수 쌍을 저장한다 
	managers.insert(make_pair("gg", 35)); // 이렇게 해도 된다

	pair<string, int> person1 = { "Noah", 25 };
	if (managers.find(person1) != managers.end()) {
		//이러면 노아 25 찾음
	}
	else {
		//아니면 못찾음
	}

	//삭제하는것
	managers.erase({ "Noah", 25 });
	for (const auto& m : managers)cout << m.first << " ( " << m.second << " ) " << endl;
	//이름과 나이 출력 


	//ㅇmap
	map<string, int> fruits;
	fruits.insert({ "apple", 1000 });
	fruits.insert({ "banana", 1500 });
	//내부적으로 string기준으로 정렬이 된다.
	for (const auto& p : fruits)
		cout << p.first << " is " << p.second << " won." << endl;
	//대괄호 연산자 지원함
	cout << fruits["apple"] << endl; // 1000이 나옴
	fruits["orange"]; // 하면 oreange가 생성되고 value는 0으로 지정 됨
	fruits["grape"] = 3000; // grape를 생성하고 value는 3000을 추가한다
	fruits["apple"] = 5000; // 사과가격을 1000원에서 5000원으로 변경

	fruits.erase("apple"); // 사과 삭제 

	//c++ 17부터는 
	//for (auto [name, price] : fruits)
	//	cout << name << " is " << price << " won. " << endl;
	//가능하다
}

