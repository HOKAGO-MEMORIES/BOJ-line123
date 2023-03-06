#include <iostream>
using namespace std;

long long n[10001] = {};

long long binary_search(long long K, long long N, long long max) {
	long long start = 1, end = max, mid = 0;
	long long len;
	while (start <= end) {
		len = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < K; i++) 
			len = len + (n[i] / mid);

		if (len < N) 
			end = mid - 1;
		else
			start = mid + 1;
	}

	return end;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K, N;
	cin >> K >> N;
	long long max = 0;

	for (int i = 0; i < K; i++) {
		cin >> n[i];
		if (n[i] > max)
			max = n[i];
	}
		
	long long answer = binary_search(K, N, max);
	cout << answer << '\n';
	return 0;
}