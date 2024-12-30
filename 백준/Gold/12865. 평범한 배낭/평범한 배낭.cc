#include <iostream>
#include <algorithm>
using namespace std;

int weight[101], value[101];
int dp[101][100001];

void solve() {

	int n, k, w, v;
	cin >> n >> k;


	for (int i = 1; i <= n; i++) 
		cin >> weight[i] >> value[i];

	//i: 배낭안에 담을 물건의 갯수 또는 i번째 물건, j: 물건의 총 무게, 값: 가치
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			//현재 물건의 무게(weight[i])가 j보다 크다면, 물건을 담을 수 없는 상태
			//이전 배낭의 상태(물건의 갯수가 i - 1일 때)의 가치를 가져옴
			if (j < weight[i]) 
				dp[i][j] = dp[i - 1][j];
			//현재 물건의 무게가 같거나 작다면, 물건을 담을 수 있는 상태
			//이전 배낭의 상태와 i번째 물건을 담은 상태의 값 중 가치가 큰 값을 선택
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}
	
	cout << dp[n][k] << '\n';
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}