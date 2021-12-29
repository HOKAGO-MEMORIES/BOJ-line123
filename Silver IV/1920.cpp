//4번의 시간 초과가 vector 때문이라니!
#include <iostream>
#include <algorithm>
using namespace std;

int A[100001] = {};

void binary_search(int n, int start, int end) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (start > end) {
		cout << 0 << '\n';
		return;
	}
		
	int mid = (start + end) / 2;
	
	if (A[mid] == n) {
		cout << 1 << '\n';
		return;
	}
	else if (A[mid] > n) 
		return binary_search(n, start, mid - 1);
	else 
		return binary_search(n, mid + 1, end);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		A[i] = n;
	}

	sort(A, A + N);

	int M;
	cin >> M;
	
	int m;
	for (int j = 0; j < M; j++) {
		cin >> m;
		binary_search(m, 0, N - 1);
	}

	return 0;
}