#include <iostream>
#include <string>
using namespace std;

int checkString(string& search, string& str) {
	int ans = 0, len = search.length(), pos = 0;
	while (str.find(search, pos) != string::npos) {
		ans++;
		pos = str.find(search, pos) + len;
	}

	return ans;
}
 
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int caseNum;
		string search, str;
		cin >> caseNum >> search >> str;

		int ans = checkString(search, str);
		cout << "#" << caseNum << " " << ans << '\n';
	}
	return 0;
}
