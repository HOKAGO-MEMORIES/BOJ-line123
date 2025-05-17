#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxScore(int n, int l, vector<int>& taste, vector<int>& cal) {
	vector<int> dp(l + 1, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = l; j >= cal[i]; --j) {
			dp[j] = max(dp[j], dp[j - cal[i]] + taste[i]);
		}
	}

	return *max_element(dp.begin(), dp.end());
}
 
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, l;
		cin >> n >> l;

		vector<int> taste(n), cal(n);
		for (int i = 0; i < n; i++)
			cin >> taste[i] >> cal[i];

		int ans = getMaxScore(n, l, taste, cal);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}