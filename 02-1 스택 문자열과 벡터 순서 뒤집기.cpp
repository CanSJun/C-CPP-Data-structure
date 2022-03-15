#include <iostream>
#include <vector>
#include <stack>


using namespace std;

/*
���ڿ� ������ �ٲٴ°�
Hello -> olleH
d
*/

// ���� ���� ������
// ���ڰ��ƴ϶� ������ ������ �����̴�.


template<typename T> // ���͵�����
void reverse2(vector <T>& vec) {
	stack<T, vector<T>> stk(vec); //���� �ʱⰪ�� ���͵����ͷ� �ʱ�ȭ

	//for (const auto& e : vec) stk.push(e);

	for (int i = 0; i < vec.size(); i++) {
		vec[i] = stk.top();
		stk.pop();
	}

}


string reverse(const string& str) {
	stack<char> stk;
	for (char c : str) {
		stk.push(c);
	}
	string res;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	return res;
}
int main() {
	//string test;
	//cin >> test;
	//cout << reverse(test) << endl;

	vector<string> vec{ "��", "��", "��"};

	reverse2<string>(vec);

	for (auto e : vec)cout << e << ", ";
	cout << endl;

}
