import java.io.*;
import java.util.*;

public class Main {

    static boolean[][][] visited;
    static boolean[] shiroko;
    static int[] teammate;
    static int N, K, X;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        teammate = new int[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            teammate[i] = Integer.parseInt(st.nextToken());
            st.nextToken(); // 값은 하나면 됨 (B = X - A)
        }

        shiroko = new boolean[K * X + 1];
        visited = new boolean[K + 1][N + 1][K * X + 1];
        solve(0, 0, 0);

        int ans = 0;
        for (int i = 0; i <= K * X; i++) {
            if (shiroko[i]) {
                ans = Math.max(ans, i * (K * X - i));
            }
        }

        System.out.println(ans);
    }

    static void solve(int cnt, int idx, int sum) {
        if (visited[cnt][idx][sum]) return;
        visited[cnt][idx][sum] = true;

        if (cnt >= K || idx >= N) {
            if (cnt == K) shiroko[sum] = true;
            return;
        }

        solve(cnt + 1, idx + 1, sum + teammate[idx]);
        solve(cnt, idx + 1, sum);
    }
}
