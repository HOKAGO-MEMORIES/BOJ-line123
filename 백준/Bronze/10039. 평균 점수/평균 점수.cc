#include <iostream>
#include <algorithm>
using namespace std;

int solve() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int score;
		cin >> score;
		
		if (score < 40) sum += 40;
		else sum += score;
	}

	return sum / 5;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cout << solve() << '\n';

	return 0;
}
