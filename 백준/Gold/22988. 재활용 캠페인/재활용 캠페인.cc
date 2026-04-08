#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, X;
vector<long long> C;

int solve() {
	int idx = lower_bound(C.begin(), C.end(), X) - C.begin();
	int left = 0;
	int right = idx - 1;
	int ans = N - idx;
	int full = 0;

	while (left < right) {
		if ((C[left++] + C[right]) * 2 >= X) {
			ans++;
			full += 2;
			right--;
		}
	}
	int remain = idx - full;
	ans += remain / 3;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		long long input;
		cin >> input;
		C.push_back(input);
	}
	sort(C.begin(), C.end());
	cout << solve() << '\n';
	
	return 0;
}
