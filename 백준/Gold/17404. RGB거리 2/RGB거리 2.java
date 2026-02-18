import java.io.*;
import java.util.*;

public class Main {

    static int[][] cost;
    static int N, INF = 1000001;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        cost = new int[N + 1][3];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            cost[i][0] = Integer.parseInt(st.nextToken());
            cost[i][1] = Integer.parseInt(st.nextToken());
            cost[i][2] = Integer.parseInt(st.nextToken());
        }

        int ans = solve();
        System.out.println(ans);
    }

    static int solve() {
        int[][] dp = new int[N + 1][3];
        int ans = INF;

        for (int start = 0; start < 3; start++) {
            for (int i = 0; i < 3; i++) {
                if (i == start)
                    dp[1][i] = cost[1][i];
                else
                    dp[1][i] = INF;
            }

            for (int i = 2; i <= N; i++) {
                dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
                dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
                dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
            }

            for (int i = 0; i < 3; i++)
                if (i != start)
                    ans = Math.min(ans, dp[N][i]);
        }

        return ans;
    }

}
