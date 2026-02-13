import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] field, dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        field = new int[N][M];
        dp = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++)
                field[i][j] = Integer.parseInt(st.nextToken());
        }

        solve();

        System.out.println(dp[N - 1][M - 1]);
    }

    static void solve() {
        
        // 첫 줄 해결
        dp[0][0] = field[0][0];
        for (int j = 1; j < M; j++)
            dp[0][j] = dp[0][j - 1] + field[0][j];

        int[][] tempSum = new int[2][M];

        for (int i = 1; i < N; i++) {
            tempSum[0][0] = dp[i - 1][0] + field[i][0];
            for (int j = 1; j < M; j++)
                tempSum[0][j] = Math.max(dp[i - 1][j], tempSum[0][j - 1]) + field[i][j];

            tempSum[1][M - 1] = dp[i - 1][M - 1] + field[i][M - 1];
            for (int j = M - 2; j >= 0; j--)
                tempSum[1][j] = Math.max(dp[i - 1][j], tempSum[1][j + 1]) + field[i][j];

            for (int j = 0; j < M; j++)
                dp[i][j] = Math.max(tempSum[0][j], tempSum[1][j]);
        }
    }
}
