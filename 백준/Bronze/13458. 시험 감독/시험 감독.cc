#include <iostream>
using namespace std;

const int MAXN = 1000001;
int arr[MAXN];

void solve() {
    int N, A, B, C;    
    long long result = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A;
        arr[i] = A;
    } 
    cin >> B >> C;

    for (int j = 0; j < N; j++) {
        arr[j] -= B;
        result ++;
        if (arr[j] <= 0) 
            continue;

        result += (arr[j] / C);
        arr[j] %= C;
        if (arr[j] > 0)
            result ++;
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}