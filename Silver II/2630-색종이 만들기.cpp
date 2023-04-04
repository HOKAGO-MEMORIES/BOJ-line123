//계산도 못하네 ; ㅅ;
#include <iostream>
using namespace std;

int arr[129][129];
int white = 0;
int blue = 0;
//n, m 가로, x, y 세로
void check_paper(int n, int m, int x, int y) {

	bool is_blue = arr[n][x];
	
	if (n == m && x == y) {
		if (is_blue) 
			blue++;
		else 
			white++;
	}
	else {


		for (int i = n; i < m; i++) {
			for (int j = x; j < y; j++) {
				if (arr[i][j] != arr[n][x]) {
					check_paper(n, (n + m) / 2, x, (x + y) / 2);
					check_paper((n + m) / 2, m, x, (x + y) / 2);
					check_paper(n, (n + m) / 2, (x + y) / 2, y);
					check_paper((n + m) / 2, m, (x + y) / 2, y);
					return;
				}
			}
		}

		if (is_blue) {
			blue++;
		}
		else {
			white++;
		}
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> arr[i][j];

	check_paper(0, N, 0, N);

	cout << white << '\n' << blue << '\n';

	return 0;
}