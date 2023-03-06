#include <iostream>
using namespace std;

int main() {

	string word;
	int length;
	bool is_palindrome;
	while (true) {
		cin >> word;
		length = word.length();
		is_palindrome = true;

		if (word == "0") break;

		for (int i = 0; i < length / 2; i++) {
			if (word[i] != word[length - 1 - i]) {
				cout << "no" << endl;
				is_palindrome = false;
				break;
			}
		}

		if(is_palindrome)
			cout << "yes" << endl;
	}

	return 0;
}