#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}

void solve() {
    int N;
	cin >> N;

	vector<string> word;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		word.push_back(str);
	}

	sort(word.begin(), word.end(), compare);
    
    word.erase(unique(word.begin(), word.end()), word.end());

	for (const string &w : word)
        cout << w << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}
