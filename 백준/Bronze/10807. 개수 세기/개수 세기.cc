#include <iostream>
using namespace std;

int n, x, ans;
int arr[202];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;

		if(x < 0) x += 201;
		arr[x]++;
	}

	cin >> ans;
	if(ans < 0) ans += 201;
} 

void solve() {
	
	cout << arr[ans] << '\n';
}


int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	input();

	solve();

    return 0;
}