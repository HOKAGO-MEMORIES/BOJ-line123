#include <iostream>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int card[100];
	for (int a = 0; a < n; a++)
		cin >> card[a];

	int result = 0, sum = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum > result && sum <= m) 
					result = sum;
			}
		}
	}

	cout << result << endl;
	return 0;
}