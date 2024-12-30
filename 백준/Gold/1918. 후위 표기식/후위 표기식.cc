#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

int precedence(char c) {
	if (c == '(')
		return 0;
	
	if (c == '+' || c == '-')
		return 1;

	return 2;
}

void doPrint() {
	cout << st.top();
	st.pop();
}

void printPostfix(string s) {
	for (char c : s) {
		if (c >= 'A' && c <= 'Z') 
			cout << c;

		else if (c == '(')		
			st.push(c);

		else if (c == ')') {
			while (true) {
				if (st.top() == '(') {
					st.pop();
					break;
				}
				
				doPrint();
			}
		}

		else {
			while (!st.empty() && precedence(c) <= precedence(st.top())) 
				doPrint();
			st.push(c);
		}

	}

	while (!st.empty()) 
		doPrint();
}

void solve() {
	string s;
	cin >> s;

	printPostfix(s);	
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}