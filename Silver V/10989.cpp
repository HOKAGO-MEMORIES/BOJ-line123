#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int num[10001] = { 0 };
	int a;

	for (int i = 0; i < N; i++) {
		cin >> a;
		num[a]++;
	}

	for (int j = 1; j < 10001; j++) {
		if (num[j]) {
			for (int k = 0; k < num[j]; k++)
				cout << j << '\n';
		}
	}
	
	return 0;
}