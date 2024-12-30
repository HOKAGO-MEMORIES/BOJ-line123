#include <iostream>
#include <set>
using namespace std;

int main() {

	set<int> set;

	int N;
	cin >> N;

	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		set.insert(a);
	}

	for (int j : set)
		cout << j << '\n';

	return 0;
}