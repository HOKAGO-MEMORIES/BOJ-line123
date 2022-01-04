//vector, binary_search 이용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<string> n;
	vector<string> m;

	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		n.push_back(name);
	}

	sort(n.begin(), n.end());

	for (int j = 0; j < M; j++) {
		cin >> name;
		m.push_back(name);
	}

	sort(m.begin(), m.end());

	int dbj = 0;
	vector<string> dbjname;

	for (int i = 0; i < N; i++) {
		if (binary_search(m.begin(), m.end(), n[i])) {
			dbj++;
			dbjname.push_back(n[i]);
		}
	}

	cout << dbj << '\n';
	for (int k = 0; k < dbj; k++)
		cout << dbjname[k] << '\n';

	return 0;
}