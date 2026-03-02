import java.io.*;
import java.util.*;

public class Main {

    static int MAX_VISIT = 1023;
    static int MOD = 1000000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        System.out.println(solve(N));
    }

    static long solve(int N) {
        long[][][] dp = new long[N + 1][10][MAX_VISIT + 1];

        for (int i = 1; i <= 9; i++)
            dp[1][i][1 << i] = 1;

        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 1; k <= MAX_VISIT; k++) {
                    long prev = dp[i - 1][j][k];

                    if (prev != 0) {
                        if (j > 0) {
                            int next = k | (1 << (j - 1));
                            dp[i][j - 1][next] = (dp[i][j - 1][next] + prev) % MOD;
                        }
                        if (j < 9) {
                            int next = k | (1 << (j + 1));
                            dp[i][j + 1][next] = (dp[i][j + 1][next] + prev) % MOD;
                        }
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 0; i <= 9; i++)
            ans = (ans + dp[N][i][MAX_VISIT]) % MOD;

        return ans;
    }

}
