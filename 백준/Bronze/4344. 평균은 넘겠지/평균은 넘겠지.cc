#include <iostream>

using namespace std;

int main() {

	int c;
	cin >> c;

	int n, a, avg = 0;
	double result = 0;
	for (int i = 0; i < c; i++) {
		cin >> n;
		int sum = 0, student = 0;
		int score[1000] = { };

		for (int j = 0; j < n; j++) {
			cin >> a;
			score[j] = a;
			sum += score[j];
		}
		avg = sum / n;

		for (int k = 0; k < n; k++) {
			if (score[k] > avg) student++;
		}

		result = (double)student / n * 100;
		
		cout << fixed;
		cout.precision(3);
		cout << result << "%\n";
	}
}