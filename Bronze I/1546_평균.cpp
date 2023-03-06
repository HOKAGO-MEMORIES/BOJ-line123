#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	float sum = 0;
	float max = -100;

	int score;
	for (int i = 0; i < n; i++) {
		cin >> score;
		max = (max > score) ? max : score;
		sum += score;
	}

	float result = (sum / n) / max * 100;
	cout << result << '\n';
}