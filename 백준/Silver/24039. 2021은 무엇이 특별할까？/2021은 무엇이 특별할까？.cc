#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int prime[26] = { 6, 15, 35, 77, 143, 221, 323, 437, 667, 899, 1147, 1517, 1763, 2021, 2491, 3127, 3599, 4087, 4757, 5183, 5767, 6557, 7387, 8633, 9797, 10403 };

	int N;
	cin >> N;

	for (int i = 0; i < 26; i++) {
		if (prime[i] > N) {
			cout << prime[i] << '\n';
			break;
		}
			
	}

	return 0;

}