#include <iostream>
using namespace std;

int block[501][501] = {};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, B;
	cin >> N >> M >> B;

	int min = 257, max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> block[i][j];
			min = (block[i][j] < min) ? block[i][j] : min;
			max = (block[i][j] > max) ? block[i][j] : max;
		}
	}

	int now_B, t, min_t = 2147483647, max_h = 0;

	for (int i = min; i <= max; i++) {

		now_B = B;
		t = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {

				if (block[j][k] > i) {
					now_B = now_B + (block[j][k] - i);
					t = t + 2 * (block[j][k] - i);
				}
				else if (block[j][k] < i) {
					now_B = now_B - (i - block[j][k]);
					t = t + (i - block[j][k]);
				}

			}
		}

		if (now_B > -1) {
			if (t < min_t) {
				min_t = t;
				max_h = i;
			}
			if (t == min_t) {
				max_h = (i > max_h) ? i : max_h;
			}
		}
	}

	cout << min_t << " " << max_h << '\n';
	return 0;
}