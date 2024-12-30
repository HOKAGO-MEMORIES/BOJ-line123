#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int LIS[1001];

void solve() {

	int n, ans = 1;
	cin >> n;

	fill_n(LIS, n, 1);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if(arr[i] > arr[j]) 
				LIS[i] = max(LIS[i], LIS[j] + 1);
		}
		
		ans = max(ans, LIS[i]);
	}
	
	cout << ans << '\n';
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}