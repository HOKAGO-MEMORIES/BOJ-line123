#include <iostream>
using namespace std;

void solve() {

	string s[5];

	for(int i = 0; i < 5; i++)
		cin >> s[i];

	for(int j = 0; j < 15; j++) {
		for(int i = 0; i < 5; i++) {
			if(j < s[i].length())
				cout << s[i][j];
		}
	}
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}