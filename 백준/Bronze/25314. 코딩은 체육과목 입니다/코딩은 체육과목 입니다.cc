#include <iostream>
using namespace std;

void solve() {
	int n;
	cin >> n;

	n = n / 4;
	while(n--)
		cout << "long ";

	cout << "int";
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}