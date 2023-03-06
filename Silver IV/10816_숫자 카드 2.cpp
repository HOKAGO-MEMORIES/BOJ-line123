#include <iostream>
#include <map>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	map<int, int> m;
	int num = 0;

	for (int i = 0; i < N; i++) {
		cin >> num;

		if (m.count(num))
			m[num]++;
		else
			m.insert(make_pair(num, 1));
	}

	int M;
	cin >> M;

	for (int j = 0; j < M; j++) {
		cin >> num;
		if (m.count(num))
			cout << m[num] << " ";
		else
			cout << "0" << " ";
	}

	return 0;
}