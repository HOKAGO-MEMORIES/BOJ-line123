#include <iostream>
#include <vector>

using namespace std;

int check_ans(int N, int M, vector<vector<int>> field) {
	int ans = 0;

	for (int i = M; i <= N; i++) {
		for (int j = M; j <= N; j++) {
			int sum = field[i][j] - field[i - M][j] - field[i][j - M] + field[i - M][j - M];

			if (ans < sum)
				ans = sum;
		}
	}

	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;

		vector<vector<int>> field(N + 1, vector<int>(N + 1, 0));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int fly;
				cin >> fly;
				field[i][j] = fly + field[i - 1][j] + field[i][j - 1] - field[i - 1][j - 1];
			}
		}
		
		int ans = check_ans(N, M, field);
		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}
