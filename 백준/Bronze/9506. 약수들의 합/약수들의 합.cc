#include <iostream>
using namespace std;

void solve() {

	int n;

	while (true) {
		cin >> n;
		string s = " = ";
		int sum = 0;

		if (n == -1)
			break;

		for (int i = 1; i < n; i++) {
			
			if (n % i == 0) {
				sum += i;
				s = s + to_string(i);

				if (n > sum)
					s += " + ";
			}
		}

		if (sum != n)
			s = " is NOT perfect.";

		cout << n << s << '\n';
	}
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}