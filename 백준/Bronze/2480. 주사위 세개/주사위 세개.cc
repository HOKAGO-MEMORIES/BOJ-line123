#include <iostream>
using namespace std;

int a, b, c;

void input() {
	cin >> a >> b >> c;
} 

int solve() {
	if (a == b && b == c && c == a) 
		return 10000 + a * 1000;
	else if (a == b || b == c) 
		return 1000 + b * 100;
	else if (c == a)
		return 1000 + c * 100;
	else {
		int max = ((a > b) && (a > c) ? a : (b > a) && (b > c) ? b : c);
		return max  * 100;
	}
		
		
}


int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	input();

    cout << solve() << '\n';
    
    return 0;
}