import java.io.*;
import java.util.*;

public class Main {

    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        arr = new int[N + 1][2];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        System.out.println(solve(N));
    }

    static int solve(int N) {
        int[][] dp = new int[N + 1][N + 1];

        // g: 범위, i: 시작, k: 중간, j: 끝
        for (int g = 1; g <= N; g++) {
            for (int i = 1; i + g <= N; i++) {
                int j = i + g;
                dp[i][j] = Integer.MAX_VALUE;
                
                for (int k = i; k < j; k++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k + 1][0] * arr[j][1]);
                }
            }
        }

        return dp[1][N];
    }
}
