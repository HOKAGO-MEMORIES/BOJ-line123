#include <iostream>
#include <string>
using namespace std;

string days[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

string solve(int x, int y) {
	int day = 0;
	for (int i = 1; i <= x; i++) {
		if (i == x) {
			day = (day + y) % 7;
		} else {
			switch (i)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				day = (day + 31) % 7;
				break;
			case 4: case 6: case 9: case 11:
				day = (day + 30) % 7;	
				break;
			case 2:
				day = (day + 28) % 7;
				break;
			}
		}
	}

	return days[day];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
    cin >> x >> y;

    cout << solve(x, y) << '\n';
}