#include <iostream>
#include <queue>
using namespace std;

void solve() {
	
	int k, n, m, area = 1, empty = 1;
	int cnt[5]{};
	queue<pair<int, int>> q;

	cin >> k;

	//가장 긴 길이가 방향은 한 번만, 아닌 곳은 두번이 나와야함
	//문제를 예시로 2, 4 방향은 한번 씩 나오지만 1, 3은 두 번이 나와야함
	for (int i = 0; i < 6; i++) {

		cin >> n >> m;

		cnt[n]++;
		q.push({ n, m });
	}


	int areacnt = 5;
	//긴 길이가 두번 나온 다음 4번의 짧은 길이가 나오는데 이 때 2, 3번째 나오는 길이를 곱하면 빼야할 넓이가 나옴
	//벡터에서 긴 길이 두번이 나오지 않았다면 push로 원소를 다시 넣음
	while (areacnt > 0) {

		n = q.front().first;
		m = q.front().second;

		if (cnt[n] == 1) {

			area *= m;
			areacnt--;
		}
		else if (areacnt <= 3) {

			if(areacnt < 3)
				empty *= m;
			areacnt--;
		}
		else
			q.push({ n, m });

		q.pop();
	}		 

	cout << (area - empty) * k << '\n';

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}