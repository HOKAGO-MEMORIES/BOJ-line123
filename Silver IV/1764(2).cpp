//set 이용
#include <iostream>
#include <set>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	set<string> n;

	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		n.insert(name);
	}

	int dbj = 0;
	set<string> dbjname;

	for (int j = 0; j < M; j++) {
		cin >> name;
		if (n.count(name)) {
			dbj++;
			dbjname.insert(name);
		}
	}

	cout << dbj << '\n';
	for (auto k = dbjname.begin(); k != dbjname.end(); k++)
		cout << *k << '\n';

	return 0;
}