#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 300001;
int arr[MAXN];

void solve() {

	int n;
	cin >> n;

	if (n == 0) {
		cout << 0 << '\n';
		return;
	}
		
	int exclude = (int)round(n * 0.15);
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	
	sort(arr, arr + n);
	double sum = 0;

	for (int i = exclude; i < n - exclude; i++) 
		sum += arr[i];
	
	int ans = (int)round(sum / (n - 2 * exclude));
	cout << ans << '\n';

}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}