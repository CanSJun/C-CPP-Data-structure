#include <iostream>

using namespace std;

/*
����
�ϳ����� ž
*/


//����(permutation) 
// => n���� ���ҷ� ������ ������ ���� ���, ��� ���Ҹ� ���� �ٸ� ������ �����ϴ� ���
//ex) {a,b,c} �ִٸ� abc , acb, bac, bca, cab , cba �̷��� �����ϴ�
// �� 3!���� �ȴ�.
//��� �˰������� Ǯ�� ���ؼ�, ��ȯ���� ���踦 �� ���� �ؾ��Ѵ�
// ���� ��� {a,b,c,d}�� ��� ������
// a�� �����ϰ� {b,c,d}�� ��� ����
// b�� �����ϰ� {a,c,d}�� ��� ����
// c�� �����ϰ� {b,a,d}�� ��� ����
// d�� �����ϰ� {b,c,a}�� ��� ����
// ���⼭ b�� ���� b�� �����ϰ� {c,a}�� ������
//				   c�� �����ϰ�{b,a}�� ������
//				  a�� �����ϰ� {c,b}�� ������

//1. ù���� ���ҿ� ��� ���Ҹ� ���� �¹ٲٴ� swap������ �����Ѵ�
//2. ù���� ���Ҹ� ������ ������ ���ҵ��� �������� ���� ���ϱ�.
// �׷��� �� 1,2���� �� ���� �ɰ��̴�.
#include<vector>
void print_vector(vector<int> vec) {
	for (const auto& e : vec) {
		cout << e << " ";
	}
	cout << endl;
}
void permutation(vector<int>& vec, int k) {
	if(k == vec.size() - 1){
		print_vector(vec);
		return;
	}
	for (int i = k; i < vec.size(); i++) {
		swap(vec[k], vec[i]);
		permutation(vec, k + 1); // �ڱ��ڽ� ȣ��
		swap(vec[k], vec[i]); // ������ ���� => ���ϰԵǸ� ���Ͱ� 0�����ϰ� 1��°�� �ٲ۰ű� ������ 0��°�� 2��°�� �ٲٴ� ���°� �ȴ�. 
	}
}

//c++���� <algorithm>�� next_permutation�� �ִ�. 
// 
// next_permutation(vec.begin(), vec.end());
#include<algorithm>

void hanoi(int n, int from, int to, int by);
int main() {
	vector<int> vec{ 1,2,3,4};
	permutation(vec, 0);
	//�ؿ��� STL���� ����
	sort(vec.begin(), vec.end()); // ����
	do {
		print_vector(vec);
	} while (next_permutation(vec.begin(), vec.end()));

	hanoi(5, 1, 2, 3);
	
}

// �ϳ����� ž 
//- ������ �����̴�
// - ������ ��հ� �� ��տ� ���� �� �ִ� ũ�Ⱑ �پ��� ���ǵ��� �ְ�,
// ó������ �ϳ��� ��տ� ���ǵ��� �������� ���� �ֵ��� ������� �׿��ִ�.
// �� ���ǵ��� �ٸ� ��� �ִ� ������� �̵��ϴ°� �����̴�.
// ���⼭ �ű涧 ������ �ִ�
// 1. �ѹ��� �ϳ��� ���Ǹ� �ű� �� �ִ�.
// 2. ����� �� ���� �ִ� ������ �ٸ� ����� �� ���� �ű� �� �ִ�.
// 3. ū ������ ���� ���� ���� �־�� �ȵȴ�.

//3���� ����� 1, 2, 3���̶�� �ϰ�
// ó�� 1���� ��տ� n���� ������ �ִٰ� ��������
// 1�� ����� ��� ������ 3�� ������� �ּ� Ƚ���� �ű�� ����� ����Ͻÿ�!
// ����� ��
// n	answer
// 2   1->2, 1->3, 2->3
// 3   1->3, 1->2, 3->2, 1->3, 2->1, 2->3, 1->3
// 2^n - 1 ���� �̵��� �־�� 1������ 3������ �ű� �� �ִ�.

// hanoi(����, ����, �ű���ġ, ������ �Ѱ��� ��չ�ȣ)
// if n == 1 : from���� to �������� �̵�
// otherwise : hanoi(n - 1, from, by, to)
// from���� to�� ���� �̵�
// hanoi(n - 1, by, to, from);
// by���� to �̵�

void hanoi(int n, int from, int to, int by) {
	if (n == 1) {
		cout << from << " -> " << to << endl;

	}
	else {
		hanoi(n - 1, from, by, to);
		cout << from << " -> " << to << endl;
		hanoi(n - 1, by, to, from);
	}
}