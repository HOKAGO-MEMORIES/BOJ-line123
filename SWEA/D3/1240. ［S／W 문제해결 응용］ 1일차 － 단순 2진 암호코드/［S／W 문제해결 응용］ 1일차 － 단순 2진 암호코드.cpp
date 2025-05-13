#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> BIT_PATTERNS = {
	"0001101", "0011001", "0010011", "0111101", "0100011", 
	"0110001", "0101111", "0111011", "0110111", "0001011"
};

string encryptedSegment(int n, int m, vector<string>& code) {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 50; j--) {
			if (code[i][j] == '1')	
				return code[i].substr(j - 55, 56);
		}
	}
	return "";
}

int decodeDigit(string s) {
	for (int i = 0; i < 10; i++) {
		if (BIT_PATTERNS[i] == s)
			return i;
	}
	return -1;
}

int decodeAndValidate(string encrypted) {
	vector<int> digits(8);
	for (int i = 0; i < 8; i++) {
		string segment = encrypted.substr(i * 7, 7);
		digits[i] = decodeDigit(segment);
	}

	int sumOdd = digits[0] + digits[2] + digits[4] + digits[6];
	int sumEven = digits[1] + digits[3] + digits[5] + digits[7];
	int checksum = sumOdd * 3 + sumEven;
	return (checksum % 10 == 0) ? sumOdd + sumEven : 0;
}

int scanCode(int n, int m, vector<string>& code) {
	string encrypted = encryptedSegment(n, m, code);
	return decodeAndValidate(encrypted);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;

		vector<string> code(n);
		for (int i = 0; i < n; i++)
			cin >> code[i];

		int ans = scanCode(n, m, code);
		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}