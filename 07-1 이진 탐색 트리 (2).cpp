#include<iostream>

using namespace std;

/*
ㅇ이진탐색트리에서 삭제
-데이터를 삭제는 해당 노드를 삭제 한 후, BST 속성을 만족할 수 있는 다른 적절한 노드를 찾아 해당 노드로 대체하여야 한다.

케이스가 3가지가 있다
1. 자식 노드가 없는경우 : 해당 노드를 삭제하고 부모노드가 가르키고있는 링크를 제거한다
2. 자식노드가 하나만 있는 경우 : 해당 노드를 삭제하고 부모 노드의 포인터가 해당 노드의 자식 노드를 가르키도록 설정
3. 자식 노드가 두개 있는 경우 : 후속노드의 값을 현재 노드로 복사하고 ,후속 노드를 삭제한다
-후속노드(successor) : 현재 노드 다음으로 큰 숫자를 가진 노드(현재 노드의 오른쪽 서브 트리에서 가장 작은 값의 노드)

				10
		5				14
	4		7		12		18
		6	  9			16		20

case 1인경우 4를 삭제한다고하자
10보다 작으니 왼쪽으로가고 5보다 작으니 또 왼쪽 서브트리로 가서 4가 저장된 곳을 찾는다.
자식노드가 하나도 없는 leaf node이기 때문에 해당 노드를 삭제하고(즉 4를 삭졔)
5가 4를 연결하고 있는 링크를 제거한다.

				10
		5				14
			7		12		18
		6	  9			16		20
case 2인 경우 5를 삭제한다고 하자.
오른쪽 서브트리 하나만 가지고 있다. 왼쪽 서브트리는 NULL 값.
이 노드를 삭제할려면 5를 삭제하고 
그 뒤 10이 5를 가르키고 있던 이 링크를 7을 가르키게 한다.

				10
			7			14
		6		9	12		18
						16		20
여기서 14를 삭제한다면
12를 연결할지 18을 연결할지 에매할 수 가 있다.
그리고 삭제를 하면서 이진탐색트리의 속성 부모노드는 왼쪽 서브트리노드 보다 값이 커야하고.  오른쪽보단 작아야한다.
이를 위해 삭제하려고하는 14보다 다음으로 큰 수 또는 다음으로 작은값을 찾아서 14값을 대체하는 형태로 트리를 조정해줘야 한다.
현재에선 12가 14다음으로 작은값이고. 16이 14 다음으로 큰 값이다.
12를 predecessor(현재노드보다 다음으로 작은 값)라고하고 16을 successor(현재 노드보다 다음으로 큰 값)라고한다.
sucessor값을 14노드로 복사한다. 

				10
			7			16
		6		9	12		18
						16		20
16이 두개다. 그러면 16을 삭제해야한다. 
그런데 이 후속노드는 자식이 하나도 없거나 또는 오른쪽 자식만 있는 형태로 볼 수 있다
왜냐하면 후속노드는 현재 노드의 오른쪽 서브트리에서 가장 왼쪽에 있는 노드를 찾는 형태로 동작을 하고 있기때문이다.
지금에선 자식노드가 아무것도 없으니 16을 삭제하고 18의 링크를 NULL로 변경한다.


				10
			7			16
		6		9	12		18
								20
15을 일단 추가하고 10을 삭제 해보겟다

				10
			7			16
		6		9	12		18
					  15		20
10의 후속노드를 찾아야하는데 오른쪽 서브트리에서 가장 왼쪽에있는 12라는 노드가 sucessor가 된다.
				12
			7			16
		6		9	12		18
					  15		20
12를 삭제해야하는데 하나의 자식노드를 가지고 있기때문에. 


				12
			7			16
		6		9	15		18
					  	    	20
이렇게 된다.

시간의 복잡도는 O(h)이다. 즉 O(log n)


*/

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int d) : data(d), left(nullptr), right(nullptr) {
	}
};
class binarysearchtree {
private:
	Node* root = nullptr;

public:
	~binarysearchtree();
	void erase(int value) { 
		root = erase_impl(root, value);
	}

private:

	Node* successor(Node* node) {
		auto curr = node->right;
		while (curr && curr->left)curr = curr->left;
		return curr;
	}

	//노드 삭제 후, 부모 노드 포인터가 가리켜야 할 노드의 주소를 반환.
	Node* erase_impl(Node* node, int value) {
		if (!node) return nullptr;

		if (value < node->data)node->left = erase_impl(node->left, value);
		else if (value > node->data)node->right = erase_impl(node->right, value);
		else {
			if (node->left && node->right) { // 자식노드가 두개가 있을 경우
				auto succ = successor(node);
				node->data = succ->data;
				node->right = erase_impl(node->right, succ->data);
			}
			else { // 자식 노드가 전혀 없거나, 한쪽 자식만 있는 경우
				auto tmp = node->left ? node->left : node->right;
				delete node;
				return tmp;
			}
		}
		return node;
	}
};

/*
ㅇ이진탐색트리의 문제점
-경우에따라 이진탐색트리의 시간복잡도가 O(n)이라고하는 선형시간복잡도로 나오는데
이거는 원소의 삽입순서에 따라 이진탐색트리가 한쪽으로 치우친 형태로 구성될 수 있기 떄문이다.

예롣르어서 5->3->7->2->4->9 순서로 하면 균형이 잡혀있는 이진트리가 만들어지는데
똑같은 데이터를 2->3->4->5->7->9를 입력하면 한쪽으로 치우쳐진 트리가 된다.
전자는 h = 2라고 할 수 있고 후자는 h = 5가 되버린다. h가 대략 n과 같은값이라고 볼 수 있기때문에.
O(n)이라고 표현이 가능하다

ㅇ이러한 문제점 해결방법이 있다.
-한쪽으로 치우친 트리의 구성을 변경하여 균형잡힌 트리 형태로 변경할 수 있다.

AVL 트리, 레드블랙트리(red-balck tree), B트리, 스플레이 트리(splay tree) 등이 있다.



*/


