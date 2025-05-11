#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getProfit(int n, vector<vector<int>>& farm) {
	int ans = 0;

	for (int i = 0; i < n / 2; i++)  {
		int left = n / 2 - i;
		int right = n / 2 + 1 + i;
		for (int j = left; j < right; j++) {
			ans += farm[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		ans += farm[n / 2][i];
	}

	int k = 1;
	for (int i = n / 2 + 1; i < n; i++) {
		int left = k;
		int right = n - k;
		for (int j = left; j < right; j++) {
			ans += farm[i][j];
		}
		k++;
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
		int n;
		cin >> n;

		string s = "";
		vector<vector<int>> farm(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < n; j++) {
				farm[i][j] = s[j] - '0';
			}
		}

		int ans = getProfit(n, farm);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
