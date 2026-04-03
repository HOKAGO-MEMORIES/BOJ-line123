#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 17
#define INF 10e16
using namespace std;

int n;
vector<pair<double, double>> cities;
double dp[MAX][1 << MAX];

double getDistance(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double solve(int cur, int bitmask) {
	if (bitmask == (1 << n) - 1)
		return getDistance(cities[cur].first, cities[cur].second, cities[0].first, cities[0].second);	// 시작 지점으로 돌아가기

	if (dp[cur][bitmask] != -1.0)
		return dp[cur][bitmask];	// 메모리제이션

	dp[cur][bitmask] = INF;	// 최댓값으로 초기화 (초기값)

	for (int i = 0; i < n; i++) {
		if ((bitmask & (1 << i)) == 0 && cur != i) {
			dp[cur][bitmask] = min(dp[cur][bitmask], solve(i, bitmask | (1 << i)) + 
			getDistance(cities[cur].first, cities[cur].second, cities[i].first, cities[i].second));
		}
	}

	return dp[cur][bitmask];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1.0;
        }
    }

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		cities.push_back(make_pair(x, y));
	}
	
	// 소수점 6자리까지 표현
	cout << fixed;
	cout.precision(6);

	cout << solve(0, 1) << '\n';
	return 0;
}
