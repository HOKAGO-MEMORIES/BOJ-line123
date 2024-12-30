#include <iostream>
using namespace std;

string s;
int answer;
int num[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

void input() {
	cin >> s;
} 

void solve() {
	for (int i = 0; i < s.length(); i++) {
		int index = s[i] - 'A';
		answer += num[index];
	}

	cout << answer << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	input();

	solve();

    return 0;
}