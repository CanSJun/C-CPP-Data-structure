#include <iostream>

using namespace std;

/*
ㅇ선형탐색(linear serach) : 주어진 데이터에 맨 처음부터 맨 마지막까지 차례대로 검색해서
찾고자하는 원소값이 있는지 찾는 것.
그래서 순차탐색이라고도 한다

시간 복잡도는 O(n)

ㅇ장단점
장점 : 가장 간단하고 직관적인 방법, 정렬되지 않은 데이터에도 가능하다
단점 : 비효율적이다 ( 최악의 경우 배열 전체를 다 탐색 해야한다)


*/

bool linear_serach(int data[], int n, int target) {

	for (int i = 0; i < n; i++) {
		if (data[i] == target) return true;
	}

	return false;
}

/*
ㅇ이진탐색
-정렬된 배열에 대해 적용할 수 있는 방법이다.
입력 배열에서 탐색하고자 하는 범위를 반씩 줄여가면서 찾아가는 것이다.

ex) 1 2 3 5 7 10 13 15 18 23 25 27 28 30 33
find(23)

첫번째 값을 lower 
마지막 인덱스값을 upper로 설정

총 15개로 구성 되어있으니 upper = 14 lower = 0 이다
정중앙은 middle 즉 15 (upper+lower/2)

23과 15와 비교해서 크기때문에 

우측에 존재할것이다.
그러면 lower부터 middle까지 다 버린다

18 23 25 27 28 30 33 
여기서 또 중앙은 27이다 
27과 23 비교해보면 23이 작으니깐 왼쪽에있다

18 23 25 에서 또 중앙을보니 23이다. 그럼 찾앗다.

즉 이걸 선형탐색으로하면 10번 해야한다.
하지만 이진탐색은 총 3번으로 도출이 가능했다.
즉 시간의 복잡도는 O(log n)

ㅇ장단점
장점 : 검색속도가 빠름
단점 : 이미 정렬되어 있는 데이터에만 적용이 가능하다


*/

bool binary_serach(int data[], int n, int target) {
	int lower = 0, upper = n - 1;

	if (data[lower] > target || data[upper] < target) return false;
	while (lower <= upper) {
		int mid = (lower + upper) / 2;

		if (data[mid] == target) return true;
		else if (data[mid] < target) lower = mid + 1; // 찾고자하는게 작은경우니깐 lower를 +1를 해주느것
		else upper = mid - 1; // 타겟보다 큰 경우 이때는 한칸 왼쪽값을 준다. 
	}

	return false;
}

/*
std::binary_search()제공한다
algorithm에 정의되어있따

template <class forwardit, classT>
bool binary_search(forwardit first, forwardit last, const T & value);

template <class forwardit, classT>
bool binary_search(forwardit first, forwardit last, const T & value, Compare comp);

사용하기 위해선 컨테이너가 정렬이 되어 있어야 함. first, last 범위에 value값이 있는지를 검사한다.
최소 first, last 범위 안에서라도 정렬이 되어있어야한다.

*/