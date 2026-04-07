#include <iostream>
#include <string>
using namespace std;

string solve(int n) {
	string ans;
	cin >> ans;
	
	while(n--) {
		string input;
		cin >> input;

		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] != input[i])
				ans[i] = '?';
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
    cin >> n;

    cout << solve(n - 1) << '\n';
}