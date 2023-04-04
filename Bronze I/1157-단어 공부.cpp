#include <iostream>
using namespace std;

int main() {
	string word;
	int alphabet[26] = { };

	int num;
	cin >> word;
	int length = word.length();

	for (int i = 0; i < length; i++) {
		num = word[i] - 97;
		if (num < 0) num = word[i] - 65;
		alphabet[num]++;
	}

	int max = 0, count = 0;
	char ch = '\0';
	for (int j = 0; j < 26; j++) {
		if (alphabet[j] > max) {
			max = alphabet[j];
			ch = j + 65;
		}
	}

	for (int k = 0; k < 26; k++) 
		if (alphabet[k] == max) count++;
	if (count > 1) ch = '?';

	cout << ch << endl;
}