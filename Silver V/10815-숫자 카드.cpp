#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

int binarySearch(int lo, int hi, int k) {
	if (lo > hi)
		return 0;
	int mid = (lo + hi) / 2;

	if (arr[mid] == k)
		return 1;
	else if (arr[mid] > k)
		return binarySearch(lo, mid - 1, k);
	else
		return binarySearch(mid + 1, hi, k);
}

void solve() {
	
	int n, m, k;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n);

	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> k;
		cout << binarySearch(0, n - 1, k) << " ";
	}
	
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}