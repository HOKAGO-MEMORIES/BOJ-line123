import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        System.out.println(solve(N, K));
    }

    static int solve(int N, int K) {
        int[] dp = new int[N + 1];

        for (int i = 2; i <= N; i++)
            dp[i] = (dp[i - 1] + K) % i;

        return dp[N] + 1;
    }
}
