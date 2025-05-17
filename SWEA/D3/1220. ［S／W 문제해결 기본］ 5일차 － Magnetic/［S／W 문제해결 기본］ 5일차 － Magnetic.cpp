#include <iostream>
#include <vector>
using namespace std;

int checkDeadlock(int n, vector<vector<int>>& table) {
	int ans = 0;
	for (int j = 0; j < n; ++j) {
		bool hasMagnet = false;
		for (int i = 0; i < n; ++i) {
			if (table[i][j] == 1) {
				hasMagnet = true;
			}
			else if (table[i][j] == 2) {
				if (hasMagnet) {
					ans++;
					hasMagnet = false;
				}
			}
		}
	}

	return ans;
}
 
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		vector<vector<int>> table(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cin >> table[i][j];
		}

		int ans = checkDeadlock(n, table);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
