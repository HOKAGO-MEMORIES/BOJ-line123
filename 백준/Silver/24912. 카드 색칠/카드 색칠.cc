#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int n;
int arr[1000002];

void solve() {
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			bool color[4] = {0, 0, 0, 0};
			color[arr[i - 1]] = true;
			color[arr[i + 1]] = true;

			for (int j = 1; j <= 3; j++) {
				if (!color[j]) {
					arr[i] = j;
					break;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] != 0 && arr[i - 1] == arr[i]) {
			cout << -1 << '\n';
			return 0;
		}
	}
		
	solve();
	return 0;
}
