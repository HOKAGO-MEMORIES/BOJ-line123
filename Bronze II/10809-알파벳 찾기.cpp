#include <iostream>
using namespace std;

int main() {
	int alphabet[26];
	fill_n(alphabet, 26, -1);
	char c[101] = { };
	cin >> c;

	int i = 0, j;
	while (c[i] != '\0') {
		j = c[i] - 97;
		if (alphabet[j] == -1)
			alphabet[j] = i;
		i++;
	}

	for (int k = 0; k < 26; k++)
		cout << alphabet[k] << " ";
}