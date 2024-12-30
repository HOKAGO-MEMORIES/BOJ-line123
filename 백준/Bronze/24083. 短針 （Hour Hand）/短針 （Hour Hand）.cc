#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    int ans = (a + b) % 12;
    if(!ans)
        ans = 12;
    cout << ans << '\n';
    
    return 0;
}