#include <iostream>
#include <vector>
#include <stack>


using namespace std;

/*
문자열 순서를 바꾸는것
Hello -> olleH
d
*/

// 벡터 순서 뒤집기
// 문자가아니라 임의의 데이터 파일이다.


template<typename T> // 벡터뒤집기
void reverse2(vector <T>& vec) {
	stack<T, vector<T>> stk(vec); //스택 초기값을 벡터데이터로 초기화

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

	vector<string> vec{ "가", "나", "다"};

	reverse2<string>(vec);

	for (auto e : vec)cout << e << ", ";
	cout << endl;

}
