#include <iostream>
using namespace std;

long long arr[1000001];

long long binary_search(long long start, long long end, int target, int N) {
	long long middle, len;
	while (start <= end) {
		middle = (start + end) / 2;
		len = 0;

		for (int i = 0; i < N; i++) {
			if(arr[i] >= middle) 
				len = len + (arr[i] - middle);
		}
			
		if (len >= target)
			start = middle + 1;
		else
			end = middle - 1;
	}

	return end;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	long long max = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	
	long long answer = binary_search(1, max, M, N);
	cout << answer << '\n';

	return 0;
}