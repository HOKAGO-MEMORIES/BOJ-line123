#include <iostream>
using namespace std;

// 기둥을 각각 1, 2, 3으로 지정, ex) x = 1, y = 3, 남은 기둥: 2
// x : 원반이 있는 기둥, y : 원반을 옮길 기둥, 6-x-y : 남은 기둥
// n : 원반 번호 ex) 1, 2, ..., n-1, n
void hanoi(int n, int x, int y) {

	if(n == 1) // 가장 위에 있는 원반을 옮기는 경우
		cout << x << " " << y << '\n';
	else { // 가장 아래의 원반을 제외한 나머지 원반을 옮기는 경우
		hanoi(n - 1, x, 6-x-y); 
		cout << x << " " << y << '\n';
		hanoi(n - 1, 6-x-y, y);
	}
	
}

void solve() {
	
	int n;
	cin >> n;

	//하노이 탑의 총 이동 횟수는 2^n - 1, 시프트 연산으로 표현
	cout << (1 << n) - 1 << '\n';

	hanoi(n, 1, 3);
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}