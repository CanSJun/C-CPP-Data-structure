#include <iostream>

using namespace std;

/*
ㅇ트리
-계층적인 구조를 나타내는 자료 구조
-뿌리가 위에가고 나뭇가지와 잎이 아래로 자라나는 형태로 표현

ㅇ구성요소
노드(node, vertex) : 트리의 데이터를 저장하는 원소 단위, 정점이라고도 한다

에지(edge, linke) :
노드와 노드를 연결하는 선, 간선이라고도 한다
트리의 edge는 부모-자식 계층 관계만을 나타낸다.
노드의 개수가 N이면 항상 N-1개의 edge가 존재한다!

ㅇ트리의 용어
-root : 트리의 맨 위에 있는 node
-parent-child 관계로 정의 되어있다. : 자식의 node는 임의의 갯수를 가질 수 있다.
-leap : 트리자료구조에서 맨 아래쪽에 위치해서 자식노드가 존재하지않은 걸 말한다. terminal/external node라고도 한다
-internal node(내부 노드) : leap node가 아닌 node들 즉 자식이 한개라도 있을 시 내부노드
-sibling(형제) : 부모가 같은 노드들
-ancestor(조상)-descendant(후손) : 조상은 자기자신 부모와 부모의 부모 등등 다 합쳐서 조상이라고 한다. 후손은 자신의 자식들 그리고 자식의 자식들을 후손이라고 한다
-degree(차수) : 자기 자식의 node의 갯수 
-level : 루트노드부터 시작해서 얼마나 떨어져있는지. 루트가 레벨 0이다. 이제 레벨 1씩 증가한다.
-height : 루트노드부터 리프노트까지의 거리. 즉 가장큰 레벨 값에 + 1 값
-subtree(부트리, 부분트리라고도 한다) :특정 노드 기준으로 해당 노드의 후손들만으로 구성한것.

ㅇ이진트리(binary tree)
-모든 노드가 최대 두개의 자식을 갖는트리
즉 모든 노드의 차수가 2 이하인 트리
또는 모든 노드가 2개의 서브트리를 가지고 있는 트리이다.(서브트리는 빈 트리 일 수 있다)
-각각의 자식 노드는 부모의 왼쪽 자식(left child) 또는 오른쪽 자식(right child)로 이야기한다

ㅇ정 이진트리(proper binary tree, full binary tree)
-각각의 자식노드가 한개도 없거나 2개가 꽉 차있는 자식노드로 이루어진 이진트리
즉 리프노드를 제외한 노드들은 모두 자식이 2개인것.

ㅇ포화 이진트리(perfect binary tree)
-모든 레벨에서 노드가 가득 채워져있는 트리.
-높이가 h이면 노드 개수가 2^h - 1

ㅇ완전이진트리(complete binary tree)
-마지막 레벨을 제외한 모든 레벨에는 노드가 와전히 채워져있고 마지막 레벨에는
노드가 왼쪽부터 채워져 있는 이진트리이다.

ㅇ균형 이진트리(balanced binary tree)
-모든 노드의 서브트리간의 높이 차이가 1 이하인 트리

ㅇ편향 트리(skewed tree)
-리프 노드를 제외한 모든 노드가 하나의 자식 노드만 갖는 트리


ㅇ이진트리 구현 방법
-배열 
완전 이진트리의 경우 배열을 이용하여 효율적으로 표현이 가능하다.(우선순위 큐에서 설명한다 heap 쪽)
-연결리스트
저장할 데이터와 왼쪽 자식과 오른쪽 자식 노드를 가르키는 포인터 2개를 갖는 구조체를 사용한다.

*/


struct Node {
	char data;
	Node* left;
	Node* right;

	Node(char d) : data(d), left(nullptr), right(nullptr){}
};

int main() {
	Node* root = new Node('A');
	root->left = new Node('B');
	root->right = new Node('C');

	root->left->left = new Node('D');
	root->left->right = new Node('E');

	root->right->right = new Node('F');


}