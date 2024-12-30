#include <iostream>
using namespace std;

int arr[6];

void solve() {
    int N, T, P, sum = 0;
    
    cin >> N;
    for (int i = 0; i < 6; i++) 
        cin >> arr[i];
    cin >> T >> P;

    for (int i = 0; i < 6; i++) {
        sum += arr[i] / T;
        if (arr[i] % T) sum++;
    }
    
    cout << sum << '\n' << N / P << " " << N % P << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
