#include <iostream>
#include <unordered_map>
using namespace std;

const int MAXN = 200005;
int fruits[MAXN];

int checkFruit(int N) {
    int ans = 0, start = 0;
    unordered_map<int, int> fruitCnt;
    
    for (int end = 0; end < N; end++) {
        fruitCnt[fruits[end]]++;

        while (fruitCnt.size() > 2) {
            fruitCnt[fruits[start]]--;
            if (fruitCnt[fruits[start]] == 0)
                fruitCnt.erase(fruits[start]);

            start++;
        }

        ans = max(ans, end - start + 1);
    }

    return ans;
}

void solve() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> fruits[i];

    cout << checkFruit(N) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
