#include <iostream>
using namespace std;

void is_VPS(string s) {
	int count = 0;
	int size = s.size();
	int i = 0;
	string answer = "NO";

	while (count >= 0) {

		if (i == size) {
			if (count == 0) 
				answer = "YES";
			break;
		}
			
		if (s[i] == '(')
			count++;
		else if (s[i] == ')')
			count--;

		i++;
	}

	cout << answer << '\n';
}

int main() {

	int T;
	cin >> T;

	string str;
	for (int i = 0; i < T; i++) {
		cin >> str;
		is_VPS(str);
	}

	return 0;
}