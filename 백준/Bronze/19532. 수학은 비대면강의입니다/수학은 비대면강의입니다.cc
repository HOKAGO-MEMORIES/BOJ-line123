#include <iostream>
using namespace std;

void solve() {

	int a, b, c, d, e, f;
	double x, y;
	cin >> a >> b >> c >> d >> e >> f;
	y = (a * f - d * c) / (a * e - d * b);
	x = (b * f - e * c) / (b * d - a * e);

	cout << x << " " << y << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}