#include <iostream>
#include <list>
#include <forward_list>
using namespace std;
/*
ㅇstd::list
-이중연결 리스트를 구현한 컨테이너

template<class T, class Allocator = std::allocator<T>>
class list;

-특정 위치에 원소를 삽입, 또는 삭제를 상수시간으로 처리. 시간복잡도로 나타내면 O(1)
-그러나 여기서 위치를 지정할때. 벡터처럼 []와 같이 랜덤 액세스를 지원을 안함
begin(), end()등으로 얻은 양방향 반복자와 ++, -- 연산자로 위치 이동해야함

-<list>라는 헤더파이를 include해야함


ㅇforward_list
-단순연결 리스트를 구현한 컨테이너다
-begin() 함수로 순방향 반복자를 얻을 수 있고 오직 ++ 연산만 가능하다
-std::list보다 빠르게 동작하고 적은 메모리를 사용한다
-<forward_list>에 정의되어있음
*/

int main() {
	
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);

	list <int> l2 { 10, 20, 30, 40};



	l2.splice(l2.end(), l1);//l2 맨 마지막에 l1 전체를 이어 붙힘 l1 원소는 옮겨져서 l1안에 내용은 없어짐


	l2.sort(); // 오름차순으로 정렬 됨


	l2.unique(); // 10 10 20 20 이런거 하나만.
	for (auto n : l2)cout << n << ",";
	cout << endl;

	forward_list <int> l1{10, 20, 30, 40};
	l1.push_front(40);
	l1.push_front(30);

	for (auto n : l1)cout << n << " , ";
	cout << endl;

	int cnt = distance(l1.begin(), l1.end());
	printf("%d \n", cnt);

	l1.remove(40); // 40 전부다 삭제함
	l1.sort();

	for (auto n : l1)cout << n << " , ";
	cout << endl;

	l1.unique();
	for (auto n : l1)cout << n << " , ";
	cout << endl;


}	