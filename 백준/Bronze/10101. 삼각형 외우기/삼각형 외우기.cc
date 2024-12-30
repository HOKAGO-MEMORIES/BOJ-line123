#include <iostream>
#include <algorithm>
using namespace std;

void solve() {

	int a, b, c;
	string s = "";
	cin >> a >> b >> c;

	if (a + b + c != 180)
		s = "Error";
	else if (a == b && b == c)
		s = "Equilateral";
	else if (a == b || b == c || c == a)
		s = "Isosceles";
	else 
		s = "Scalene";

	cout << s << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}