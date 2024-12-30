#include <iostream>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;
	
	if (K == 0) {
		cout << 1 << endl;
		return 0;
	}

	int M = N - K;

	for (int i = N - 1; i > M; i--)
		N *= i;

	for (int j = K - 1; j > 0; j--) {
		K *= j;
	}

	int answer = N / K;

	cout << answer << endl;
	return 0;
}