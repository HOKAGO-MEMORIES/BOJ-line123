#include <iostream>
using namespace std;

int a, b, c;

void input() {
	cin >> a >> b >> c;
} 

void solve() {
	a = a * 60 + b;
	int total = a + c;

	a = total / 60;
	b = total % 60;

	if(a >= 24) a = a - 24;

	cout << a << " " << b << '\n';
}


int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	input();

    solve();
    
    return 0;
}