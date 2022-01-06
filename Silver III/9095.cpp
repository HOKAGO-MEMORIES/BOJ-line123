//진짜 숫자 계산 못하는게 맞는듯
#include <iostream>
using namespace std;

int check(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	if (n == 3) {
		return 4;
	}
	else {
		return check(n - 1) + check(n - 2) + check(n - 3);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int n;
	while(T--) {
		cin >> n;
		cout << check(n) << '\n';
	}

	return 0;
}