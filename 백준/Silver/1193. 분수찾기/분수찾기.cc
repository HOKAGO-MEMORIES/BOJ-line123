#include <iostream>
#include <string>
using namespace std;

int X, n = 1, i = 1;
string ans;

void solve() {
	while (true) {
		if(X <= n) 
			break;
		i++;
		n = n + i;
	}

	int num = n - X;

	if(i % 2) //홀수
		ans = to_string(1 + num) + "/" + to_string(i - num);
	else //짝수
		ans = to_string(i - num) + "/" + to_string(1 + num);
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> X;

	solve();

	cout << ans << '\n';

    return 0;
}