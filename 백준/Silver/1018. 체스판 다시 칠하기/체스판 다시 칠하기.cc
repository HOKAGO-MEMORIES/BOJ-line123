//짜놓고 보니 조금 억지같기도 하고..
#include <iostream>
using namespace std;

char chess[50][50];

int compare_chess(int plus_i, int plus_j, int choose) {
	
	int chess_count = 0;

	for (int i = plus_i; i < 8 + plus_i; i++) {
		choose = (choose + 1) % 2;

		for (int j = plus_j; j < 8 + plus_j; j++) {

			if (choose == 0) {
				if (chess[i][j] != 'B')
					chess_count++;
			}
			else {
				if (chess[i][j] != 'W')
					chess_count++;
			}
			choose = (choose + 1) % 2;
		}
	}
	return chess_count;
}

int main() {

	int N, M;
	cin >> N >> M;

	int chess_now = 0;
	int chess_now_black = 0;
	int chess_now_white = 0;
	int answer = 64;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)
			cin >> chess[i][j];

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			chess_now_black = compare_chess(i, j, 1);
			chess_now_white = compare_chess(i, j, 0);
			chess_now = (chess_now_black > chess_now_white) ? chess_now_white : chess_now_black;
			answer = (answer > chess_now) ? chess_now : answer;
		}
	}

	cout << answer << endl;

	return 0;
}