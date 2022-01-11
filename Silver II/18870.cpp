#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int N, n;
	cin >> N;

	vector<int> vec, coord;

	for (int i = 0; i < N; i++) {
		cin >> n;
		vec.push_back(n);
		coord.push_back(n);
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int j = 0; j < N; j++) {
		cout << lower_bound(vec.begin(), vec.end(), coord[j]) - vec.begin() << " ";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}