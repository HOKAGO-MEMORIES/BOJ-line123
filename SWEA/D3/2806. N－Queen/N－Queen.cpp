#include <iostream>
using namespace std;

const int MAXN = 11;
int n, ans;
int visited[MAXN];

bool checkQueen(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (visited[i] == col || 
			abs(visited[i] - col) == abs(row - i)) // 행의 차이 == 열의 차이 => 대각선 상에 있다
			return false;
	}
	return true;
}

void nQueen(int curRow) {
	if (curRow == n) {
		ans++;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (checkQueen(curRow, i)) {
			visited[curRow] = i;
			nQueen(curRow + 1);
		}
	}
}
 
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		ans = 0;
		nQueen(0);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}