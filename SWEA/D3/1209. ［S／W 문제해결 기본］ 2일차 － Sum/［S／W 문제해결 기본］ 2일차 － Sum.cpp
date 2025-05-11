#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checkMax(vector<vector<int>>& vec) {
	int ans = 0;

	for (int i = 0; i < 100; i++) {
		int row_sum = 0;
		for (int j = 0; j < 100; j++) {
			row_sum += vec[i][j];
		}
		ans = max(ans, row_sum);
	}

	for (int j = 0; j < 100; j++) {
		int col_sum = 0;
		for (int i = 0; i < 100; i++) {
			col_sum += vec[i][j];
		}
		ans = max(ans, col_sum);
	}

	int diag1_sum = 0;
	for (int i = 0; i < 100; i++) {
		diag1_sum += vec[i][i];
	}
	ans = max(ans, diag1_sum);

	int diag2_sum = 0;
	for (int i = 0; i < 100; i++) {
		diag2_sum += vec[i][99 - i];
	}
	ans = max(ans, diag2_sum);

	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tc;
		cin >> tc;

		vector<vector<int>> vec(100, vector<int>(100));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> vec[i][j];
			}
		}

		int ans = checkMax(vec);
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}
