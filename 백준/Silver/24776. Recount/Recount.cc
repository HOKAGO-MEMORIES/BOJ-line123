#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

static string LAST_WORD = "***";
map<string, int> m;
string s;
int max_cnt;

string solve() {
	string ans = "";
	for (auto& itr : m) {
		if (itr.second == max_cnt) {
			if (ans.empty()) ans = itr.first;
			else return "Runoff!";
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(getline(cin, s) && s != LAST_WORD) {
		m[s]++;
		max_cnt = max(max_cnt, m[s]);
	}

	cout << solve() << '\n';
	return 0;
}
