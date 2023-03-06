#include <iostream>
#include <string>
using namespace std;

void solve() {
	string s;
	cin >> s;
	
	bool is_minus = false;
	int size = s.size();
	int answer = 0;
	string num = "";

	for (int i = 0; i <= size; i++) {
		if (s[i] == '+' || s[i] == '-' || i == size) {

			if (is_minus) {
				answer -= stoi(num);
			}
			else {
				answer += stoi(num);
			}

			if (s[i] == '-')
				is_minus = true;

			num = "";
		}
		else 
			num += s[i];
	}

	cout << answer << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}