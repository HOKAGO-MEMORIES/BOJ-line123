#include <iostream>
#include <string>
using namespace std;

int base64ToBinary(char c) {
	if ('A' <= c && c <= 'Z') return c - 'A';
	if ('a' <= c && c <= 'z') return c - 'a' + 26;
	if ('0' <= c && c <= '9') return c - '0' + 52;
	if (c == '+') return 62;
	if (c == '/') return 63;
	return 0;
}

string decoder(string base64) {
	string decoded = "";
	int len = base64.length();

	for (int i = 0; i < len; i += 4) {
		int b1 = base64ToBinary(base64[i]);
		int b2 = base64ToBinary(base64[i + 1]);
		int b3 = base64ToBinary(base64[i + 2]);
		int b4 = base64ToBinary(base64[i + 3]);
		
		int binary = (b1 << 18) | (b2 << 12) | (b3 << 6) | b4;

		decoded += (char)(binary >> 16);
		decoded += (char)((binary >> 8) & 0xFF);
		decoded += (char)(binary & 0xFF);
	}

	return decoded;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string base64;
		cin >> base64;

		string ans = decoder(base64);
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
