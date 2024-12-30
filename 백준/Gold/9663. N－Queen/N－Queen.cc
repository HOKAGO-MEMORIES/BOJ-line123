#include <iostream>
using namespace std;

const int MAXN = 16;
int visit[MAXN];
int n, ans = 0;

bool check(int row, int col) {
	for (int i = 0; i < row; i++) {
		//1. 같은 열에 퀸이 존재하는지 판별
		//2. 대각선에 퀸이 존재하는지 판별
		//nQueen 함수에서 각 행마다 퀸을 배치하기 때문에 이곳에서 판별할 필요 없음
		if (col == visit[i] ||
			abs(col - visit[i]) == abs(row - i))
			return false;
	}
	return true;
}

void nQueen(int curRow) {

	if (curRow == n) {
	//curRow와 n이 같아졌다면 모든 퀸의 배치가 끝난 경우
	//ans를 1 증가시키고 해당 경우 종료
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check(curRow, i)) {
			//둘 수 있는 퀸의 위치인 경우
			//현재 퀸의 위치 : (curRow, i)
			visit[curRow] = i;
			nQueen(curRow + 1);
		}
	}
}

void solve() {
	cin >> n;
	nQueen(0);
	cout << ans << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}