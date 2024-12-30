#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
	int tri[3];
	for (int i = 0; i < 3; i++) 
		cin >> tri[i];
	sort(tri, tri + 3);
	
	while (tri[2] >= tri[0] + tri[1])
		tri[2]--;
	
	cout << tri[0] + tri[1] + tri[2] << '\n';

}

int main() {
    
    ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}