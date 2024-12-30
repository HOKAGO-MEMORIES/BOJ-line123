#include <iostream>
using namespace std;

int n;

int fibonacci(int n) {

	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

void solve() {
	
	cin >> n;

	cout << fibonacci(n) << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}