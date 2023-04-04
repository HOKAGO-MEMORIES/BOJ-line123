#include <iostream>
using namespace std;

int n, ans;
string s;

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;

		bool b[26] = {false, };
		bool is_answer = true;

		for(int i = 0; i < s.length(); i++) {
			int index = s[i] - 'a';		

			if(!b[index]) {
				b[index] = true;

			} else {
				if(s[i] != s[i - 1]) {
					is_answer = false;
					break;
				}
			}
		}

		if(is_answer) 
			ans++;
			
	}

	cout << ans << '\n';

    return 0;
}