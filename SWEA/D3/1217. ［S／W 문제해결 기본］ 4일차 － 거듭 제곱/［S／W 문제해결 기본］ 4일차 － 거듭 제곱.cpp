#include <iostream>
using namespace std;

int multiplication(int ans, int num, int idx) {
	if (idx == 0)
		return ans;
	ans = multiplication(ans * num, num, idx - 1);
	return ans;
}
 
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int caseNum, num, idx;
		cin >> caseNum >> num >> idx;

		int ans = multiplication(1, num, idx);
		cout << "#" << caseNum << " " << ans << '\n';
	}
	return 0;
}
