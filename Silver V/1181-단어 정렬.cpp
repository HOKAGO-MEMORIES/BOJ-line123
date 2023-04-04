#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main() {

	int N;
	cin >> N;

	vector<string> word;
	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		word.push_back(str);
	}

	sort(word.begin(), word.end(), compare);

	for (int j = 0; j < N; j++) {
		if (j > 0 && word[j] == word[j - 1])
			continue;
		cout << word[j] << endl;
	}

	return 0;
}