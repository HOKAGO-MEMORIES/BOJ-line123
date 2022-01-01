#include <iostream>
#include <stack>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	stack<int> s;
	string ans = "";

	int input, num = 0, count = n;

	while (count > 0) {
		cin >> input;

		if(s.empty() || s.top() < input) {
			while (num < input) {
				s.push(++num);
				ans += '+';
			}
			s.pop();
			count--;
			ans += '-';
		}
		else {
			if (s.top() == input) {
				s.pop();
				count--;
				ans += '-';
			}
			else if (s.top() > input) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}

	for (char answer : ans)
		cout << answer << '\n';
	return 0;
}