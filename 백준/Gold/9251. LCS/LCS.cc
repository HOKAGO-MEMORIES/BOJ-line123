//LCS을 일차원배열로 사용한 경우
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int LCS[MAX];

void solve() {

	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length(), len2 = s2.length(), ans = 0;

	for (int i = 1; i <= len1; i++) {
		//이차원배열처럼 최대 길이 갱신이 불가능하니 이전값 저장이 필요
		int prev = 0;
    	for (int j = 1; j <= len2; j++) {
			int cur = LCS[j];

			//일차원배열에 저장되는 값은 이차원배열로 했을 때의 한 행
			//LCS[j] = LCS[i][j]
       		if (s1[i - 1] == s2[j - 1])
            	LCS[j] = prev + 1;
			else
				LCS[j] = max(LCS[j], LCS[j - 1]);

			prev = cur;
    	}
	}

	cout << LCS[len2] << '\n';
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}