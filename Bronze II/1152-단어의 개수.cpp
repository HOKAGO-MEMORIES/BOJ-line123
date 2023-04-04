#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	getline(cin, text);
	
	int count = 0;
	if (text.empty()) {
		cout << count << endl;
		return 0;
	}

	count = 1;
	int length = text.length();
	for (int i = 0; i < length; i++) {
		if (text[i] == ' ') {
			count++;
		}
	}

	if (text[0] == ' ') count--;
	if (text[length - 1] == ' ') count--;

	cout << count << endl;
	return 0;
}