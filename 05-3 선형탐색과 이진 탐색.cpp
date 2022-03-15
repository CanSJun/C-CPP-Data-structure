#include <iostream>

using namespace std;

/*
������Ž��(linear serach) : �־��� �����Ϳ� �� ó������ �� ���������� ���ʴ�� �˻��ؼ�
ã�����ϴ� ���Ұ��� �ִ��� ã�� ��.
�׷��� ����Ž���̶�� �Ѵ�

�ð� ���⵵�� O(n)

�������
���� : ���� �����ϰ� �������� ���, ���ĵ��� ���� �����Ϳ��� �����ϴ�
���� : ��ȿ�����̴� ( �־��� ��� �迭 ��ü�� �� Ž�� �ؾ��Ѵ�)


*/

bool linear_serach(int data[], int n, int target) {

	for (int i = 0; i < n; i++) {
		if (data[i] == target) return true;
	}

	return false;
}

/*
������Ž��
-���ĵ� �迭�� ���� ������ �� �ִ� ����̴�.
�Է� �迭���� Ž���ϰ��� �ϴ� ������ �ݾ� �ٿ����鼭 ã�ư��� ���̴�.

ex) 1 2 3 5 7 10 13 15 18 23 25 27 28 30 33
find(23)

ù��° ���� lower 
������ �ε������� upper�� ����

�� 15���� ���� �Ǿ������� upper = 14 lower = 0 �̴�
���߾��� middle �� 15 (upper+lower/2)

23�� 15�� ���ؼ� ũ�⶧���� 

������ �����Ұ��̴�.
�׷��� lower���� middle���� �� ������

18 23 25 27 28 30 33 
���⼭ �� �߾��� 27�̴� 
27�� 23 ���غ��� 23�� �����ϱ� ���ʿ��ִ�

18 23 25 ���� �� �߾������� 23�̴�. �׷� ã�Ѵ�.

�� �̰� ����Ž�������ϸ� 10�� �ؾ��Ѵ�.
������ ����Ž���� �� 3������ ������ �����ߴ�.
�� �ð��� ���⵵�� O(log n)

�������
���� : �˻��ӵ��� ����
���� : �̹� ���ĵǾ� �ִ� �����Ϳ��� ������ �����ϴ�


*/

bool binary_serach(int data[], int n, int target) {
	int lower = 0, upper = n - 1;

	if (data[lower] > target || data[upper] < target) return false;
	while (lower <= upper) {
		int mid = (lower + upper) / 2;

		if (data[mid] == target) return true;
		else if (data[mid] < target) lower = mid + 1; // ã�����ϴ°� �������ϱ� lower�� +1�� ���ִ���
		else upper = mid - 1; // Ÿ�ٺ��� ū ��� �̶��� ��ĭ ���ʰ��� �ش�. 
	}

	return false;
}

/*
std::binary_search()�����Ѵ�
algorithm�� ���ǵǾ��ֵ�

template <class forwardit, classT>
bool binary_search(forwardit first, forwardit last, const T & value);

template <class forwardit, classT>
bool binary_search(forwardit first, forwardit last, const T & value, Compare comp);

����ϱ� ���ؼ� �����̳ʰ� ������ �Ǿ� �־�� ��. first, last ������ value���� �ִ����� �˻��Ѵ�.
�ּ� first, last ���� �ȿ����� ������ �Ǿ��־���Ѵ�.

*/