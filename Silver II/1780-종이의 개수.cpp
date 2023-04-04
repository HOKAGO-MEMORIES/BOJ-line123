#include <iostream>
using namespace std;

int arr[2188][2188];
int answer[3];

void solve(int s, int e, int n) {
	int paper = arr[s][e];
	bool not_same = false;

	for (int i = s; i < s + n; i++) {
		for (int j = e; j < e + n; j++) {
			if (paper != arr[i][j]) {
				not_same = true;
				break;
			}
		}
		if (not_same)
			break;
	}

	if (not_same) {
		int next = n / 3;

		for (int k = 0; k < 3; k++) {
			for (int l = 0; l < 3; l++) {
				solve(s + next * k, e + next * l, next);
			}
		}
	}
	else {
		answer[paper + 1]++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	solve(0, 0, n);

	cout << answer[0] << '\n' << answer[1] << '\n' << answer[2] << '\n';

	return 0;
}