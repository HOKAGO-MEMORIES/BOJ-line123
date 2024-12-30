#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;
const long long MAXN = 1000000007;

//행렬 곱
matrix matrixMultiply(matrix& a, matrix& b) {

    matrix result(2, vector<long long>(2, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] += (a[i][k] * b[k][j]) % MAXN;
                result[i][j] %= MAXN;
            }
        }
    }

    return result;
}

//행렬 A의 거듭제곱
void matrixPower(matrix& A, matrix& result, long long n) {
    while (n > 0) {
        if (n % 2)
            result = matrixMultiply(result, A);
        A = matrixMultiply(A, A);
        n /= 2;
    }
}

long long fibonacci(long long n) {
    if (n < 2)
        return 1;
    
    matrix A = {{1, 1}, {1, 0}};
    matrix result = {{1, 0}, {0, 1}};
    matrixPower(A, result, n - 1);

    return result[0][0] % MAXN;

}

void solve() {
    long long n;
    cin >> n;

    cout << fibonacci(n) << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
