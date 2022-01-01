#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;

	long long N;
	for (int i = 0; i < T; i++) {
		cin >> N;

		if((N - 2) % 3 == 0 || N % 9 == 0)
			cout << "TAK" << '\n';
		else
			cout << "NIE" << '\n';

	}
	return 0;
}