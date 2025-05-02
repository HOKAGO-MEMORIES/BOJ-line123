#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num;
int ans, max_cnt;

void dfs(int idx, int cnt) {
	if (cnt >= max_cnt) {
		ans = max(ans, stoi(num));
		return;
	}

	for (int i = idx; i < num.length() - 1; i++) {
		for (int j = i + 1; j < num.length(); j++) {
			if (num[i] <= num[j]) {
				swap(num[i], num[j]);
				dfs(i, cnt + 1);
				swap(num[i], num[j]);
			}

			if (i == num.length() - 2 && j == num.length() - 1) {
				swap(num[i], num[j]);
				dfs(i, cnt + 1);
				swap(num[i], num[j]);
			}
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
		cin >> num >> max_cnt;
		ans = 0;
		dfs(0, 0);

		cout << '#' << test_case << " " << ans << '\n';
	}
	return 0;
}
