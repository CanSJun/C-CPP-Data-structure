#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
괄호만으로 이루어진 문자열이 주어질때 괄호의 종류별로 쌍이 제대로 되어있는지를 검사하기
[] . {} , () 로 구성된다고 해보자

ㅇ올바른 괄호의 조건
-괄호의 종류별로 여는괄호와 닫는 괄호의 개수가 같아야 한다.
-같은 종류의 괄호에서 여는 괄호가 닫는 괄호보다 먼저 나타나야 한다.
-마지막 여는 괄호와 쌍이 되는 닫는 괄호가 먼저 나타나야한다.

ㅇ검사하는 알고리즘
-문자열의 각 문자를 차례대로 검사
 ->여는 괄호 ( { [를 만나면 스택에 push
 ->닫는 괄호 ), }, ]를 만나면. 스택이 비어있으면 false를 반환을 하고
 스택의 top에 있는 문자가 현재 닫는 괄호와 쌍을 이루는 여는 괄호인지를 검사하여서
 쌍이 맞으면 스택에서 pop 아니면 false를 한다.

 -모든 문자열을 검사한 후, 스택이 비어있는지를 검사한다
 비어있으면 true 반환
 그렇지 않으면 false를 반환한다
*/


bool paren_check(const string& s) {
	stack<char> stk;

	for (char c : s) {
		if (c == '(' || c == '{' || c == '[') {
			stk.push(c);
		}else {
			if (stk.empty() || stk.top() == '(' && c != ')' || stk.top() == '{' && c != '}' || stk.top() == '[' && c != ']') return false;
				stk.pop();
		}
	}
//	if (stk.empty()) { return true; }
//	else { return false; }

	return stk.empty();
}


int main() {

	cout << paren_check("[]()") << endl;
	cout << paren_check("[(])") << endl;
}
