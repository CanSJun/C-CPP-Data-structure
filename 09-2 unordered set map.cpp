#include <iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

/*
ㅇunordered_Set 컨테이너
-key타입의 키 값을 저장하는 순서없는 연관컨테이너
-데이터 삽입, 삭제 탐색은 O(1) 시간 복잡도로 동작한다
-만약에 중복되는 데이터를 unordered_set구조로 저장할려면 unordered_multiset 사용한다.
-사용자 정의 타입을 저장할 경우 ,햇 ㅣ함수 Hash와 비교를 위한 keyEqual을 지정해야 한다.
<unordered_set>에 정의 되어 있다.

ㅇunordered_map 컨테이너
-Key 타입의 키와 T 타입의 값(value)의 쌍을 저장하는 순서없는 연관 컨테이너이다
-데이터 삽입, 삭제 ,탐색은 O(1) 시간 복잡도로 동작해야한다.
-만약 중복되는 데이터 unordered_map 구조로 저장할려면 unorderded_multimap을 사용한다
-사용자 정의의 타입을 저장할 경우 ,해시 함수 Hash와 비교를 위한 KeyEqual을 지정해야한다.
<unordered_map>에 정의 되어 있음

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

	//중복되지않은 것 세기
	vector<int> numbers{ 1,5,3,1,5,7,4,5,6,3,2,7,3,6,2 };
	unordered_set<int> num_set(numbers.begin(), numbers.end()); // 반복자를 생성자 인수로 넣음 // 같으면 무시하게 된다 1, 1에서 1 후자꺼 무시
	cout << num_set.size() << endl; // 이러면 중복되지 않은것들 갯수임

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
	// map이랑 다른건 임의의 순서로 출력이 된다 map은 정렬이 돼서 나온다. 
}