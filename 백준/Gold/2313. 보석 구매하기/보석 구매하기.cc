#include <iostream>
#include <vector>
using namespace std;

int L;
long long totalAnsSum;
int store[1000];
vector<pair<int, int>> ansIdx;

void solve() {
	vector<int> sum(L);
	sum.push_back(store[0]);

	int start = 0, end = 0, cur = 0;
	long long maxSum = store[0];
	long long curSum = store[0];

	for (int i = 1; i < L; i++) {
		if (curSum <= 0) {
			curSum = store[i];
			cur = i;
		}
		else {
			curSum += store[i];
		}

		if (curSum > maxSum) { 
			maxSum = curSum;
			start = cur;
			end = i;
		}
		else if (curSum == maxSum) {
			int len = i - cur + 1;
			int min_len = end - start + 1;

			if (len < min_len) {
				start = cur;
				end = i;
			}
		}
	}

	totalAnsSum += maxSum;
	ansIdx.push_back(make_pair(start + 1, end + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> L;
		for (int j = 0; j < L; j++)
			cin >> store[j];
		solve();
	}

	cout << totalAnsSum << '\n';
	for (auto idx : ansIdx)
		cout << idx.first << " " << idx.second << '\n';

	return 0;
}
