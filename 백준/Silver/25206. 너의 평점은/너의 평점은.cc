#include <iostream>
#include <map>
using namespace std;

void solve() {

	map<string, double> m;

	m["A+"] = 4.5;
	m["A0"] = 4.0;
	m["B+"] = 3.5;
	m["B0"] = 3.0;
	m["C+"] = 2.5;
	m["C0"] = 2.0;
	m["D+"] = 1.5;
	m["D0"] = 1.0;
	m["F"] = 0.0;

	int t = 20;
	double y, sum = 0, ans = 0;
	string x, z;

	while(t--) {

		cin >> x >> y >> z;
		
		if(z != "P") {
			ans += (y * m[z]);
			sum += y;
		}

	}
		ans /= sum;
		cout << ans << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}