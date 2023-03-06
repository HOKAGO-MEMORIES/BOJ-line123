#include <iostream>
using namespace std;

int main() {

	int A, B, V, answer = 0;
	cin >> A >> B >> V;

	answer = (V - B) / (A - B);
	if ((V - B) % (A - B)) answer++;

	cout << answer << endl;
	return 0;
}