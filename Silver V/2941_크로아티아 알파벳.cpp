#include <iostream>
using namespace std;

int len;
string s;

void input() {
	cin >> s; 
} 

void solve() {
	len = s.length();

	for (int i = s.length() - 1; i >= 0; i--) {
		switch(s[i]) {
		case '=':
			if(s[i - 1] == 'c' || s[i - 1] == 's') {
				len--;
				i--;
			}
			else if(s[i - 1] == 'z') {
				if(s[i - 2] == 'd') {
					len = len - 2;
					i = i - 2;
				}
				else {
					len--;
					i--;
				}
			}
			break;

		case '-':
			if(s[i - 1] == 'c' || s[i - 1] == 'd') {
				len--;
				i--;
			}
			break;

		case 'j':
			if(s[i - 1] == 'l' || s[i - 1] == 'n') {
				len--;
				i--;
			}
			break;

		default:
			break;
		}
	}

	cout << len << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	input();

	solve();

    return 0;
}