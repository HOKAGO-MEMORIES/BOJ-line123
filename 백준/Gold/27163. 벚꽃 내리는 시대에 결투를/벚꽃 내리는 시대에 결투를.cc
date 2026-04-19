#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, a, l;
vector<pair<int, int>> atk;
long long dp[5001][5001]; // 최소 오라 소모량

long long solve(int cnt, int life) {	
	if (cnt == n) 
		return 0;

	long long &ret = dp[cnt][life];
	if (ret != -1) return ret;

	ret = 1e15;

	// 오라로 맞기
	if (atk[cnt].first != -1) {
		long long nxt = solve(cnt + 1, life);

		if (atk[cnt].second == -1 && nxt == 0) {
			ret = min(ret, 0LL); // 오라가 0 미만이 될 경우 0으로 회복
		} else {
			ret = min(ret, nxt + atk[cnt].first);
		}
	}

	// 라이프로 맞기
	if (atk[cnt].second != -1 && life + atk[cnt].second < l) 
		ret = min(ret, solve(cnt + 1, life + atk[cnt].second));
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> a >> l;
	atk.resize(n);
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) 
		cin >> atk[i].first >> atk[i].second;
	
	if (solve(0, 0) <= a) {
		cout << "YES" << '\n';
		int life = 0;

		for (int i = 0; i < n; i++) {
			// 최선의 선택 역추적
			// 라이프 공격이 없으면 오라로 맞기
			if (atk[i].second == -1) {
				cout << 'A';
			}
			// 둘 다 있다면 오라로 맞는게 최선의 선택인지 확인
			else if (atk[i].first != -1 && 
				solve(i, life) == solve(i + 1, life) + atk[i].first) {
				cout << 'A';
			}
			// 아니면 라이프로 맞은 것 
			else {
				cout << 'L';
				life += atk[i].second;	
			}
		}
			
		cout << '\n';
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}
