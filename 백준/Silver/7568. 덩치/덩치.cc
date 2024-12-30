#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int person[51][2] = {};
	int rating[51] = {};

	for (int i = 0; i < N; i++) {
		cin >> person[i][0] >> person[i][1];
		rating[i] = 1;
	}

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			if (person[j][0] < person[k][0] && person[j][1] < person[k][1])
				rating[j]++;
		}
		cout << rating[j] << " ";
	}

	return 0;
}