import java.io.*;
import java.util.*;

public class Main {

    static int MAX_INT = 16000000;
    static int N, maxVisit;
    static int[][] graph, dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        maxVisit = (1 << N) - 1;

        graph = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++)
                graph[i][j] = Integer.parseInt(st.nextToken());
        }

        dp = new int[N][maxVisit + 1];
        for (int i = 0; i < N; i++)
            Arrays.fill(dp[i], -1);

        System.out.println(solve(0, 1));
    }

    static int solve(int cur, int bitmask) {
        if (bitmask == maxVisit) {
            if (graph[cur][0] == 0) return MAX_INT;
            return graph[cur][0];
        }

        if (dp[cur][bitmask] != -1)
            return dp[cur][bitmask];

        dp[cur][bitmask] = MAX_INT;

        for (int i = 1; i < N; i++)
            if ((bitmask & (1 << i)) == 0 && graph[cur][i] != 0)
                dp[cur][bitmask] = Math.min(dp[cur][bitmask],
                        solve(i, bitmask | (1 << i)) + graph[cur][i]);

        return dp[cur][bitmask];
    }
}
