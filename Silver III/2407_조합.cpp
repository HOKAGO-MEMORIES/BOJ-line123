#include <iostream>
#include <cmath>
using namespace std;

int n, m;
string result;
__uint128_t C[101][101];
//이거 없이 그냥 함수만 돌리면 무수히 많은 재귀가 증식해서 시간초과남

void input() {

	cin >> n >> m;
}

__uint128_t com(int x, int y) { 
	
	if (C[x][y] != 0) return C[x][y];	
	if (y == 0 || x == y) return C[x][y] = 1;
	if (y == 1 || x - y == 1) return C[x][y] = x;
	if (x - y < y) y = x - y;

	return C[x][y] = (com(x - 1, y - 1) + com(x - 1, y));
}


void solve() {
	
	input();

	__uint128_t r = com(n, m);

	string front = to_string((long long) (r / (__uint128_t) pow(10, 15)));
	string back = to_string((long long) (r % (__uint128_t) pow(10, 15)));
	
	if(front == "0") 
		result = back;
	else
		result = front + back;

	cout << result << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}