#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int LCS[MAX][MAX];

void solve() {

	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length(), len2 = s2.length();

	//LCS 2차원 배열에서 i와 j가 0인 경우는 0으로 비워줌
	for (int i = 1; i <= len1; i++) {
    	for (int j = 1; j <= len2; j++) {
			//문자가 서로 같은 경우 직전 문자에 대한 최장 공통 부분 수열의 길이에 1을 더함
       		if (s1[i - 1] == s2[j - 1])
            	LCS[i][j] = LCS[i - 1][j - 1] + 1;
			//다른 경우에 더 긴 부분 수열의 길이를 갱신
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
    	}
	}

	//길이를 계속 갱신하기 때문에 마지막으로 갱신된 값이 최댓값
	cout << LCS[len1][len2] << '\n';
}	

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	solve();

    return 0;
}