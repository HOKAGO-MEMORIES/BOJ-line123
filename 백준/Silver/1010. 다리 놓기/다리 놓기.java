import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int ans = solve(N, M);
            sb.append(ans).append('\n');
        }

        System.out.println(sb);
    }

    static int solve(int N, int M) {
        int[][] dp = new int[M + 1][N + 1];

        for (int i = 1; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (i == j || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }

        return dp[M][N];
    }
}
