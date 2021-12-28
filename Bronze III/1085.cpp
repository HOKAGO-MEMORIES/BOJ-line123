#include <iostream>
using namespace std;

int main() {

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int x_up = w - x;
	int x_down = x;
	int y_up = h - y;
	int y_down = y;

	int x_min = (x_up < x_down) ? x_up : x_down;
	int y_min = (y_up < y_down) ? y_up : y_down;
	int min = (x_min < y_min) ? x_min : y_min;

	cout << min << endl;
	return 0;
}