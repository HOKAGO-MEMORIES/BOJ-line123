#include <iostream>
using namespace std;

int Euclidean(int a, int b) {
	int r = a % b;

	if (r == 0) 
		return b;
	else 
		return Euclidean(b, r);
}

int main() {

	int a, b;
	cin >> a >> b;

	int greatest = Euclidean(a, b);
	int least = a * (b / greatest);

	cout << greatest << '\n' << least << '\n';

	return 0;
}