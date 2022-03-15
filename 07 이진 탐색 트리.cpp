#include<iostream>

using namespace std;

/*
������Ž��Ʈ��(BST[binary search tree])
-ȿ������ �ڷ��� Ž���� ���� ����Ʈ������� �ڷᱸ��
->�ڷ��� �������� ������ ǥ���ϱ� ���� Ʈ���� ����ϴ°� �ƴ϶�, �ڷ��� ȿ������ ������ ���� Ʈ�������� ����ϴ� ����
->�ڷ��� ������°� �����͸� �����ϰų� �����ϰų� Ư�������͸� Ž���ϴ� ������ ��Ÿ����

-Ʈ���� �ִ� ��� ��� N�� ����, ���� ����Ʈ���� �ִ� ��� ����� Ű(key)���� ��� N�� Ű������ �۾ƾ��ϰ�
������ ����Ʈ���� �ִ� ������� Ű ���� ��� N�� Ű������ Ŀ���ϴ� ������ �����ؾ��Ѵ�.


������Ž��Ʈ���� Ư¡
-�ڷ��� Ž��, ����, ������ ��� O(log n) �ð� ���⵵�� �����Ѵ�.
-����Ž��Ʈ���� ����Ʈ���� �����̱� ������ ������ȸ�� �� �� �ְ�. �� ��쿡 ������������ ���ĵ� ���� ���� �� �ִ�.

-�ð����⵵ ����
�ڷᱸ��		Ž��			����				����
�迭		    O(n)			O(1)				O(1) - �߰��� �����Ѵ��ص� �ǳ��� �ִ°� �ű�� �ȴ�
���Ḯ��Ʈ		O(n)			O(1)				O(1)
���ĵ� �迭	  O(log n)-����Ž��	O(n)-����Ʈ������� O(n) - ���� ���Ѿ��ϴ� ����Ʈ �ؾ��Ѵ�. 
����Ž��Ʈ��   O(lon n)		  O(log n)			   O(log n)



��Ž��

					10
			 5				14
		4		7				18
			  6				 16    20

find (7)�� �Ѵ�����. ���� root�� ���Ѵ�. ���ؼ� ������ ���� ����Ʈ���� ũ�� ������ ����Ʈ���� �̵��Ѵ�.
�׷��� 5�� �̵��ϰ� �� 5�� ���ؼ� ũ�ϱ� ������ ����Ʈ���� ����
7�̶� ���ϴµ� 7�� ������ true�� ��ȯ�Ѵ�.

find(15)�� �Ѵ�����. ���� root�� ���Ѵ� root�� �����ϱ� ������ ����Ʈ���� �̵��Ѵ�
14�� ���ؼ� �� ũ�ϱ� ���������� ����. 18�� ���ؼ� 18���� ������ ���� ����Ʈ���� �̵��Ѵ�
16�̶� ���ؼ� �����ϱ� �������� �����ߴµ� NULL�� ������. false�� ��ȯ�ϰų� NULL���� ��ȯ�Ѵ�.
->�ð� ���⵵ O(h)->h�� Ʈ���� ���� => O(log n)���� ǥ��

������
					10
			 5				14
		4		7				18
			  6				 16    20
-insert(9)�� �����Ѵ��ϸ� ��ġ�� ã�´�
root�� ���ؼ� �����ϱ� ���� ����Ʈ���� ����. 
5�� ���ؼ� ũ�ϱ� ������ ����Ʈ���� ����. 
7�� ���ؼ� ũ�ϱ� ���������� ���µ� NULL�� ������. ���⿡ 9��� ���� �ִ´�.

					10
			 5				14
		4		7				18
			  6	   9		 16    20

12�� �ִ´��غ���.
10���� ũ�ϱ� ���������� �̵�
14���� �����ϱ� �������� ���µ� NULL�̴ϱ� ���⿡ 12�� �ִ´�.
					10
			 5				14
		4		7		12		18
			  6	   9		 16    20
�̰͵� O(h)�� ǥ���� �����ϴ�. => O(log n)

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
				insert_impl(curr->left, value); // ���
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
	void inorder_impl(Node* curr) { // ������ȸ, �̰� ����ϸ� ������������ ���ĵż� ���� ���̴�.
		if (curr != nullptr) {
			inorder_impl(curr->left);
			cout << curr->data << ", ";
			inorder_impl(curr->right);
		}
		cout << endl;
	}
};
