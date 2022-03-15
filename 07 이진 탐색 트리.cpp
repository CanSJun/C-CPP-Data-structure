#include<iostream>

using namespace std;

/*
ㅇ이진탐색트리(BST[binary search tree])
-효율적인 자료의 탐색을 위한 이진트리기반의 자료구조
->자료의 계층적인 구조를 표현하기 위해 트리를 사용하는게 아니라, 자료의 효율적인 관리를 위해 트리구조를 사용하는 형태
->자료의 관리라는건 데이터를 삽입하거나 삭제하거나 특정데이터를 탐색하는 연산을 나타낸다

-트리에 있는 모든 노드 N에 대해, 왼쪽 서브트리에 있는 모든 노드의 키(key)값은 노드 N의 키값보다 작아야하고
오른쪽 서브트리에 있는 모든노드의 키 값은 노드 N의 키값보다 커야하는 조건을 만족해야한다.


ㅇ이진탐색트리의 특징
-자료의 탐색, 삽입, 삭제가 모두 O(log n) 시간 복잡도로 동작한다.
-이진탐색트리도 이진트리의 일종이기 때문에 중위순회를 할 수 있고. 이 경우에 오름차순으로 정렬된 값을 얻을 수 있다.

-시간복잡도 정리
자료구조		탐색			삽입				삭제
배열		    O(n)			O(1)				O(1) - 중간을 삭제한다해도 맨끝에 있는걸 옮기면 된다
연결리스트		O(n)			O(1)				O(1)
정렬된 배열	  O(log n)-이진탐색	O(n)-쉬프트연산수행 O(n) - 정렬 시켜야하니 쉬프트 해야한다. 
이진탐색트리   O(lon n)		  O(log n)			   O(log n)



ㅇ탐색

					10
			 5				14
		4		7				18
			  6				 16    20

find (7)을 한다하자. 먼저 root와 비교한다. 비교해서 작으면 왼쪽 서브트리로 크면 오른쪽 서브트리로 이동한다.
그러면 5로 이동하고 또 5랑 비교해서 크니깐 오른쪽 서브트리로 간다
7이랑 비교하는데 7와 같으니 true를 반환한다.

find(15)를 한다하자. 먼저 root와 비교한다 root가 적으니깐 오른쪽 서브트리로 이동한다
14와 비교해서 또 크니깐 오른쪽으로 간다. 18와 비교해서 18보다 작으니 왼쪽 서브트리로 이동한다
16이랑 비교해서 작으니깐 왼쪽으로 갈라했는데 NULL이 있으니. false를 반환하거나 NULL값을 반환한다.
->시간 복잡도 O(h)->h는 트리의 높이 => O(log n)으로 표현

ㅇ삽입
					10
			 5				14
		4		7				18
			  6				 16    20
-insert(9)를 삽입한다하면 위치를 찾는다
root와 비교해서 작으니깐 왼쪽 서브트리로 간다. 
5와 비교해서 크니깐 오른쪽 서브트리로 간다. 
7와 비교해서 크니깐 오른쪽으로 가는데 NULL을 만난다. 여기에 9라는 값을 넣는다.

					10
			 5				14
		4		7				18
			  6	   9		 16    20

12를 넣는다해보자.
10보다 크니깐 오른쪽으로 이동
14보다 작으니깐 왼쪽으로 가는데 NULL이니깐 여기에 12를 넣는다.
					10
			 5				14
		4		7		12		18
			  6	   9		 16    20
이것도 O(h)로 표현이 가능하다. => O(log n)

*/

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int d) : data(d), left(nullptr), right(nullptr){
	}
};
class binarysearchtree {
private : 
	Node* root = nullptr;

public:
	~binarysearchtree();
	void insert(int value) {
		if (!root)
			root = new Node(value);
		else
			insert_impl(root, value);
	}
	Node* find(int value) {

		return find_impl(root, value);

	}
	void inorder() {
		inorder_impl(root);
	}

private:
	void insert_impl(Node* curr, int value) {
		if (value < curr->data) {
			if (!curr->data) curr->left = new Node(value);
			else
				insert_impl(curr->left, value); // 재귀
		}
		else {
			if (!curr->right)curr->right = new Node(value);
			else
				insert_impl(curr->right, value);
		}
	}
	Node* find_impl(Node* curr, int value) {
		if (curr == nullptr) return nullptr;

		if (value == curr->data) {
			return curr;
		}
		else {
			if (value < curr->data)
				return find_impl(curr->left, value);
			else
				return find_impl(curr->right, value);
		}
	}
	void inorder_impl(Node* curr) { // 중위순회, 이걸 출력하면 오름차순으로 정렬돼서 나올 것이다.
		if (curr != nullptr) {
			inorder_impl(curr->left);
			cout << curr->data << ", ";
			inorder_impl(curr->right);
		}
		cout << endl;
	}
};
