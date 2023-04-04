#include <iostream>
#include <string>

using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;
	string num = to_string(a * b * c);

	int arr[10] = { };

	for (int n : num) 
		arr[n - '0']++;

	for (int n : arr)
		cout << n << '\n';

	return 0;

}