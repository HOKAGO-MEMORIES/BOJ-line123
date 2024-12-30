#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t, c, p;
    cin >> n >> t >> c >> p;
    int temp = n / t;
    if (n % t == 0)
        temp -= 1;
    
    cout << temp * c * p << '\n';

	return 0;
}