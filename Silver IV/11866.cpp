#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;

	int N;
	cin >> N;

	for (int i = 1; i < N + 1; i++)
		q.push(i);

	int K;
	cin >> K;

	int n = 1;
	int l = 0;
	int left[1000] = {};
	while (!q.empty()) {

		if (n % K == 0) {
			left[l] = q.front();
			l++;
		}
		else {
			q.push(q.front());
		}

		q.pop();
		n++;
	}

	int len = l - 1;

	cout << "<";
	for (int j = 0; j < len; j++) {
		cout << left[j] << ", ";
	}
	cout << left[len] << ">" << '\n';

	return 0;
}