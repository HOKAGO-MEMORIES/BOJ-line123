#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

void solve() {

	int n, k;
	cin >> n >> k; 

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, greater<int>());

	cout << arr[k - 1] << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}