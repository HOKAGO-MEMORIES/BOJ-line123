#include <iostream>
using namespace std;

int n, k, cnt, ans = -1;

void merge(int *A, int p, int q, int r) {

	int *tmp = new int[n + 1];
	int i = p, j = q + 1, t = 1;
	
	while (i <= q && j <= r) {
		if (A[i] <= A[j])
			tmp[t++] = A[i++];
		else
			tmp[t++] = A[j++];
	}

	while (i <= q) 
		tmp[t++] = A[i++];

	while (j <= r)
		tmp[t++] = A[j++];
	
	i = p, t = 1;

	while (i <= r) {

		A[i++] = tmp[t++];

		cnt++;
		if (cnt == k)
			ans = A[i - 1];

	}

	delete[] tmp;
		
}

void merge_sort(int * A, int p, int r) {

	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}


void solve() {
	
	cin >> n >> k;

	int *arr = new int[n + 1];

	for (int i = 1; i <= n; i++) 
		cin >> arr[i];

	merge_sort(arr, 1, n);

	cout << ans << '\n';

	delete[] arr;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}