#include <iostream>
using namespace std;

int n;

int factorial(int n) {

	if(n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}

void solve() {
	
	cin >> n;

	cout << factorial(n) << '\n';
	

}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}