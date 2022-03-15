#include <iostream>

using namespace std;
/*
ㅇ트리 순회(traversal)
-주어진 트리의 모든 노드를 한번씩 방법하는 작업이다.
-규칙적인 순서에 의해서 노드를 방문해야한다


				A
		B				C
	D		E		F		G
 H	   I			  J

ㅇ순회 방법
1.전위 순회 (preorder traversal) - 깊이 우선 탐색(depth first traversal DFT)
- 상위노드 -> 왼쪽 서브트리 -> 오른쪽 서브트리 순서로 한다. (ROLR)

A->B->D->H->I->E->C->F->J->G

2.중위 순회 (inorder traversal) - 깊이 우선 탐색(depth first traversal DFT)
-왼쪽 서브트리 -> 상위노드-> 오른쪽 서브트리 (LROR)

H->D->I->B->E->A->F->J->C->G

3.후위 순회 (postorder traversal) - 깊이 우선 탐색(depth first traversal DFT) 
-왼쪽 서브트리 -> 오른쪽 서브트리 ->  상위노드

H->I->D->E->B->J->F->G->C->A

4.레벨 순서 순회 (level order traversal) - 너비 우선 탐색(breadth first traversal BFT)
-낮은 레벨에 있는 노드를 모두 방문한 후, 큰 레벨로 이동하여 방문을 반복한다
-큐를 사용하여 구현한다

A->B->C->D->E->F->G->H->I->J


*/
struct Node {
	char data;
	Node* left;
	Node* right;

	Node(char d) : data(d), left(nullptr), right(nullptr) {}
};


void preorder(Node* node) { // 전위순회
	if (node) {
		cout << node->data << ",";
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(Node* node) { // 중위 순회
	if (node) {
		inorder(node->left);
		cout << node->data << ",";
		inorder(node->right);
	}
}
void postorder(Node* node) { // 후위 순회
	if (node) {
		inorder(node->left);
		inorder(node->right);
		cout << node->data << ",";
	}
}

#include <queue>
void levelorder(Node* node) { // 레벨 순서 순회
	queue<Node*> q;
	q.push(node);

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();
		cout << curr->data << ", ";
		if (curr->left)q.push(curr->left);
		if (curr->right)q.push(curr->right);

	}
}

/*
ㅇ이진트리 삭제하기
-각각의 노드에서 왼쪽 자식 노드와 오른쪽 자식노드를 먼저 삭제하고 ,자기 자신을 삭제하는 코드를 재귀적으로한다.
-후회 순회 방식이다.
*/

void delete_tree(Node* node) {
	if (node) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
	}
}
