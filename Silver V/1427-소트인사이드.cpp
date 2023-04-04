#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];

void solve() {

	string s;
	cin >> s;

	int len = s.length();

	for (int i = 0; i < len; i++) 
		arr[i] = s[i] - '0';

	sort(arr, arr + len, greater<>());

	for (int j = 0; j < len; j++)
		cout << arr[j];
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}