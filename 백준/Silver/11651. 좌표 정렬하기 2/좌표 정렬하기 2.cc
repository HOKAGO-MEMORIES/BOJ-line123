#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class coordinate {
public:
	int x;
	int y;
	coordinate(int x, int y) : x(x), y(y) { }
};

bool compare(coordinate a, coordinate b) {
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<coordinate> coord;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		coord.push_back(coordinate(a, b));
	}

	sort(coord.begin(), coord.end(), compare);

	for (int j = 0; j < N; j++)
		cout << coord[j].x << " " << coord[j].y << '\n';
	return 0;
}