#include <iostream>
using namespace std;

int main() {

	int T, R;
	cin >> T;
	string S;

	for (int i = 0; i < T; i++) {
		string result = {};
		cin >> R >> S;

		for (int j = 0; j < S.length(); j++)
			for (int k = 0; k < R; k++)
				result += S[j];
		cout << result << endl;
	}

}