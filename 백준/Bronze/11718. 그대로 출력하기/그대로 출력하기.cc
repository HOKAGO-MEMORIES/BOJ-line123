#include <iostream>
using namespace std;

void solve() {

	string s;

	while (true) {
		getline(cin, s);
		if(s == "")
			break;
		cout << s << '\n';
	}	
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}