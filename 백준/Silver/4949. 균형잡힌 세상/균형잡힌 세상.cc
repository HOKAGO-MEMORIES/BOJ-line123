#include <iostream>
#include <string>
#include <stack>
using namespace std;

void is_balanced(string s) {
	int count1 = 0;
	int count2 = 0;
	int size = s.size();
	int i = 0;

	stack<int> now;
	string answer = "no";

	while (true) {
		if (i == size) {
			if(count1 == 0 && count2 == 0)
				answer = "yes";
			break;
		}

		if (s[i] == '(') {
			count1++;
			now.push(1);
		}
		else if (s[i] == ')') {
			if (now.empty() || now.top() != 1) break;
			count1--;
			now.pop();
		}
		else if (s[i] == '[') {
			count2++;
			now.push(2);
		}
		else if (s[i] == ']') {
			if (now.empty() || now.top() != 2) break;
			count2--;
			now.pop();
		}

		i++;
	}

	cout << answer << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s = "";

	while (true) {

		getline(cin, s);

		if (s == ".") break;

		is_balanced(s);
	}

	return 0;
}