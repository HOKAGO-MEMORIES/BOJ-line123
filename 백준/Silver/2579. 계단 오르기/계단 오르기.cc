#include <iostream>
using namespace std;

int stair[301], score[301];

void check_stair(int n) {
	if (n <= 2) 
		score[n] = stair[n] + stair[n - 1];
	else 
		score[n] = max(score[n - 3] + stair[n - 1], score[n - 2]) + stair[n];
}

void solve() {
	int t, m = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> stair[i];
		check_stair(i);
	}
	
	cout << score[t] << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}