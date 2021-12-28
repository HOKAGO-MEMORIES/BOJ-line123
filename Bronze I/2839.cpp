#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;

	int num_five = N / 5;
	int	num_three = N / 3; 
	int answer = 5000;
	bool no_answer = true;

	for (int i = num_five; i > -1; i--) {
		for (int j = num_three; j > -1; j--) {
			if ((5 * i + 3 * j) == N && (i + j) < answer) {
				answer = i + j;
				no_answer = false;
			}
		}
	}

	if (no_answer) answer = -1;

	cout << answer << endl;
	return 0;
}