#include <iostream>
using namespace std;

int checkCharge(int p, int q, int r, int s, int w) {
	int A_Charge = p * w;
	int over = (w > r) ? (w - r) : 0;
	int B_Charge = q + s * over;
	
	int ans = (A_Charge < B_Charge) ? A_Charge : B_Charge;
	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;



		int ans = checkCharge(p, q, r, s, w);
		cout << "#" << test_case << " " << ans << '\n';


	}
	return 0;
}
