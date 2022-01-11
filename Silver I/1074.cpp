#include <iostream>
using namespace std;

int N, r, c, answer = 0;

void solve(int x, int y, int s) {
	int half = s >> 1;
	int square = half * half;

	if (half == 1) {
		if (!x && !y) 
			return;
		else if (!x && y) 
			answer++;
		else if (x && !y) 
			answer += 2;
		else if (x && y)
			answer += 3;
		return;
	}
	
	if (x < half && y < half) {
		solve(x, y, half);
	}
	else if (x < half && y >= half) {
		answer += square;
		solve(x, y - half, half);
	}
	else if (x >= half && y < half) {
		answer += (2 * square);
		solve(x - half, y, half);
	}
	else if (x >= half && y >= half) {
		answer += (3 * square);
		solve(x - half, y - half, half);
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	solve(r, c, (1 << N));

	cout << answer << '\n';
	return 0;
}