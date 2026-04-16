#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int arr[10];

int solve() {	
	for (char c : s)
		arr[c - '0']++;
	
	int mid = (arr[6] + arr[9] + 1) / 2;
	arr[6] = arr[9] = mid;

	int ans = 0;
	for (int i = 0; i < 10; i++) 
		ans = max(ans, arr[i]);

	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	
	cout << solve() << '\n';
	return 0;
}
