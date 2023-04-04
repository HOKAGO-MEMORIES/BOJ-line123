#include <iostream>
#include <stack>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K;
	cin >> K;

	stack<int> s;
	int n;

	for (int i = 0; i < K; i++) {
		cin >> n;
		if (n == 0) {
			s.pop();
		}
		else {
			s.push(n);
		}
	}

	int size = s.size();
	int sum = 0;
	for (int j = 0; j < size; j++) {
		sum += s.top();
		s.pop();
	}

	cout << sum << '\n';
	return 0;
}