#include <iostream>

using namespace std;
/*
��Ʈ�� ��ȸ(traversal)
-�־��� Ʈ���� ��� ��带 �ѹ��� ����ϴ� �۾��̴�.
-��Ģ���� ������ ���ؼ� ��带 �湮�ؾ��Ѵ�


				A
		B				C
	D		E		F		G
 H	   I			  J

����ȸ ���
1.���� ��ȸ (preorder traversal) - ���� �켱 Ž��(depth first traversal DFT)
- ������� -> ���� ����Ʈ�� -> ������ ����Ʈ�� ������ �Ѵ�. (ROLR)

A->B->D->H->I->E->C->F->J->G

2.���� ��ȸ (inorder traversal) - ���� �켱 Ž��(depth first traversal DFT)
-���� ����Ʈ�� -> �������-> ������ ����Ʈ�� (LROR)

H->D->I->B->E->A->F->J->C->G

3.���� ��ȸ (postorder traversal) - ���� �켱 Ž��(depth first traversal DFT) 
-���� ����Ʈ�� -> ������ ����Ʈ�� ->  �������

H->I->D->E->B->J->F->G->C->A

4.���� ���� ��ȸ (level order traversal) - �ʺ� �켱 Ž��(breadth first traversal BFT)
-���� ������ �ִ� ��带 ��� �湮�� ��, ū ������ �̵��Ͽ� �湮�� �ݺ��Ѵ�
-ť�� ����Ͽ� �����Ѵ�

A->B->C->D->E->F->G->H->I->J


*/
struct Node {
	char data;
	Node* left;
	Node* right;

	Node(char d) : data(d), left(nullptr), right(nullptr) {}
};


void preorder(Node* node) { // ������ȸ
	if (node) {
		cout << node->data << ",";
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(Node* node) { // ���� ��ȸ
	if (node) {
		inorder(node->left);
		cout << node->data << ",";
		inorder(node->right);
	}
}
void postorder(Node* node) { // ���� ��ȸ
	if (node) {
		inorder(node->left);
		inorder(node->right);
		cout << node->data << ",";
	}
}

#include <queue>
void levelorder(Node* node) { // ���� ���� ��ȸ
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
������Ʈ�� �����ϱ�
-������ ��忡�� ���� �ڽ� ���� ������ �ڽĳ�带 ���� �����ϰ� ,�ڱ� �ڽ��� �����ϴ� �ڵ带 ����������Ѵ�.
-��ȸ ��ȸ ����̴�.
*/

void delete_tree(Node* node) {
	if (node) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
	}
}
