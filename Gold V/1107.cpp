#include <iostream>
#include <string>
using namespace std;

void solve() {
	string n;
	int m, x, answer = 0;
	cin >> n >> m;

	bool button[10] = {};
	for (int i = 0; i < m; i++) {
		cin >> x;
		button[x] = true;
	}
	
	if (n == "100") {
		cout << answer << '\n';
		return;
	}

	if (m == 10) {
		cout << abs(stoi(n) - 100) << '\n';
		return;
	}

	string s1, s2;
	for (int i = 0; ; i++) {
		bool is_ans = true;
		s1 = to_string(stoi(n) + i);

		if (stoi(n) - i > 0) {
			s2 = to_string(stoi(n) - i);
		}
		else {
			s2 = to_string(0);
		}

		for (char c2 : s2) {
			if (button[c2 - '0']) {
				is_ans = false;
				break;
			}
		}

		if (is_ans) {
			answer += (int)s2.size();
			break;
		}

		is_ans = true;


		for (char c1 : s1) {
			if (button[c1 - '0']) {
				is_ans = false;
				break;
			}
		}

		if (is_ans) {
			answer += (int)s1.size();
			break;
		}

		answer++;
	}
	answer = min(answer, abs(stoi(n) - 100));
	cout << answer << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}