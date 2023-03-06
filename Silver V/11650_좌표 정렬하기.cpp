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
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

int main() {

	int N;
	cin >> N;

	int a, b;
	vector<coordinate> coord;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		coord.push_back(coordinate(a, b));
	}

	sort(coord.begin(), coord.end(), compare);

	int size = coord.size();
	for (int j = 0; j < size; j++)
		cout << coord[j].x << " " << coord[j].y << '\n';
	return 0;
}