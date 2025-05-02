#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> make_Snail(int N) {
	vector<vector<int>> snail(N, vector<int>(N, 0));

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	int dir = 0, x = 0, y = 0;

	for (int num = 1; num <= N * N; num++) {
		snail[x][y] = num;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N || snail[nx][ny] != 0) {
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}

		x = nx;
		y = ny;
	}

	return snail;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		vector<vector<int>> result = make_Snail(N);

		cout << "#" << test_case << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cout << result[i][j] << " ";

			cout << '\n';
		}
	
	}

	return 0;
}
