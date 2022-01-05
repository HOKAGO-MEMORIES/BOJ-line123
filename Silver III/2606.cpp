#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[101];
bool check[101];
int answer = 0;

void check_virus(int n) {
	
	check[n] = true;

	for (int i = 0; i < vec[n].size(); i++) {
		int num = vec[n][i];

		if (!check[num]) {
			check_virus(num);
			answer++;
		}
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int n, m;
	while (M--) {
		cin >> n >> m;
		vec[n].push_back(m);
		vec[m].push_back(n);
	}

	check_virus(1);

	cout << answer << '\n';
	return 0;
}