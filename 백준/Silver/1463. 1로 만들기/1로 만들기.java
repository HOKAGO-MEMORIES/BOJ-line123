import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int ans = solve(N);
        System.out.println(ans);
    }

    static int solve(int N) {
        int[] dp = new int[N + 1];

        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + 1;

            if (i % 2 == 0)
                dp[i] = Math.min(dp[i / 2] + 1, dp[i]);

            if (i % 3 == 0)
                dp[i] = Math.min(dp[i / 3] + 1, dp[i]);

        }

        return dp[N];
    }
}
