#include <iostream>
using namespace std;

void solve() {

	while(true) {
		int a, b, c;
		cin >> a >> b >> c;
		string s = "";

		if (a == 0 && b == 0 && c == 0)
			break;

		if (a >= b + c || b >= a + c || c >= a + b)
			s = "Invalid";
		else if (a == b && b == c)
			s = "Equilateral";
		else if (a == b || b == c || c == a)
			s = "Isosceles";
		else
			s = "Scalene";

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