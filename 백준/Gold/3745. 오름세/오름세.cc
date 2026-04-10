#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> vec;

int solve() {
	vector<int> LIS(N);
	LIS[0] = vec[0];
	int ans = 1;

	for (int i = 1; i < N; i++) {
		if (vec[i] > LIS[ans - 1]) {
			LIS[ans++] = vec[i];
		}
		else {
			int left = 0;
			int right = ans - 1;
			
			while (left <= right) {
				int mid = (left + right) / 2;
				if (vec[i] > LIS[mid]) left = mid + 1;
				else right = mid - 1;
			}

			LIS[left] = vec[i];
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (cin >> N) {
		vec.assign(N, 0);
		for (int i = 0; i < N; i++)
			cin >> vec[i];
		cout << solve() << '\n';
	}
	
	return 0;
}
