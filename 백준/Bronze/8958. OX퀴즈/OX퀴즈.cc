#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	string result;
	for (int i = 0; i < n; i++) {
		int total = 0;
		int score = 0;
		cin >> result;
		for (char c : result) {
			if (c == 'O') {
				score++;
			}
			else {
				score = 0;
			}
			total += score;
		}
		cout << total << '\n';
	}
}