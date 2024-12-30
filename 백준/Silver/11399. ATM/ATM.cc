#include <iostream>
#include <algorithm>
using namespace std;

int P[1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
		cin >> P[i];

	sort(P, P + N);

	int answer = P[0];
	for (int j = 1; j < N; j++) {
		P[j] += P[j - 1];
		answer += P[j];
	}

	cout << answer << '\n';
	return 0;
}