#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	unordered_map<int, string> pokemon_i;
	unordered_map<string, int> pokemon_s;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		pokemon_i[i] = name;
		pokemon_s[name] = i;
	}

	string input;
	while (M--) {
		cin >> input;
		if (isdigit(input[0]))
			cout << pokemon_i[stoi(input) - 1] << '\n';
		else
			cout << pokemon_s[input] + 1 << '\n';

	}



	return 0;
}