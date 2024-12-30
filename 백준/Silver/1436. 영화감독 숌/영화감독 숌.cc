#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;

	int count = 1;
	int num = 666;
	int temp = 0;

	while (count != N) {

		num++;
		temp = num;
		while (temp / 100) {
			if (temp % 1000 == 666) {
				count++;
				break;
			}
			temp = temp / 10;
		}
	}

	cout << num << endl;
	return 0;
}