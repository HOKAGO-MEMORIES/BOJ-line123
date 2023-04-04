#include <iostream>
#include <string>
using namespace std;

int main() {

	string first_a, first_b;
	cin >> first_a >> first_b;

	string a = "", b = "";
	for (int i = 2; i > -1; i--) {
		a += first_a[i];
		b += first_b[i];
	}

	int a_num = stoi(a);
	int b_num = stoi(b);
	int answer = (a_num > b_num) ? a_num : b_num;

	cout << answer << endl;

	return 0;
}