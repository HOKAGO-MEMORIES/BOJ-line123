#include <iostream>
using namespace std;

int arr[31];
int x, y, n;

void input() {
	for (int i = 0; i < 28; i++) {
		cin >> n;
		arr[n] = 1;
	}
} 

void solve() {
	for (int j = 1; j <= 30; j++) {
		if(arr[j] == 0) {
			if(x > y) y = j;
			else x = j;
		}
	}
	cout << x << '\n' << y << '\n';
}


int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	input();

	solve();

    return 0;
}