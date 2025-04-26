#include <iostream>

using namespace std;

int dp_Max[3];
int dp_Min[3];
int arr[3];

void solve() {
    int N = 0;
    int temp0, temp1, temp2;
    cin >> N;

    cin >> dp_Max[0] >> dp_Max[1] >> dp_Max[2];
    dp_Min[0] = dp_Max[0]; dp_Min[1] = dp_Max[1]; dp_Min[2] = dp_Max[2];

    for (int i = 1; i < N; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];

        temp0 = dp_Max[0]; temp1 = dp_Max[1]; temp2 = dp_Max[2];
        dp_Max[0] = max(temp0, temp1) + arr[0];
        dp_Max[1] = max(max(temp0, temp1), temp2) + arr[1];
        dp_Max[2] = max(temp1, temp2) + arr[2];

        temp0 = dp_Min[0]; temp1 = dp_Min[1]; temp2 = dp_Min[2];
        dp_Min[0] = min(temp0, temp1) + arr[0];
        dp_Min[1] = min(min(temp0, temp1), temp2) + arr[1];
        dp_Min[2] = min(temp1, temp2) + arr[2];
    }

    int max_Num = max(max(dp_Max[0], dp_Max[1]), dp_Max[2]);
    int min_Num = min(min(dp_Min[0], dp_Min[1]), dp_Min[2]);
    cout << max_Num << " " << min_Num << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
