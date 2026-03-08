import java.io.*;
import java.util.*;

public class Main {

    static int N, ans = Integer.MAX_VALUE;
    static int[] coins;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        coins = new int[N];

        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            for (int j = 0; j < N; j++) {
                if (input.charAt(j) == 'T')
                    coins[i] |= (1 << j);
            }
        }

        solve(0);
        System.out.println(ans);
    }

    static void solve(int cnt) {
        if (cnt == N) {
            int sum = 0;
            for (int i = 1; i < (1 << N); i *= 2) {
                int tail = 0;
                for (int j = 0; j < N; j++)
                    if ((coins[j] & i) != 0)
                        tail++;
                sum += Math.min(tail, N - tail);
            }
            ans = Math.min(ans, sum);
            return;
        }

        // 동전 뒤집기
        coins[cnt] = ~coins[cnt];
        solve(cnt + 1);

        // 동전 안뒤집기
        coins[cnt] = ~coins[cnt];
        solve(cnt + 1);
    }
}
