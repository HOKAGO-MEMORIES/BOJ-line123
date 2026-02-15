import java.io.*;
import java.util.*;

public class Main {

    static int N, W;
    static int[] cost, degree;
    static ArrayList<Integer>[] adj;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            settingGame();
            sb.append(solve()).append('\n');
        }

        System.out.println(sb);
    }

    static int solve() {
        int[] dp = new int[N + 1];
        Queue<Integer> q = new ArrayDeque<>();

        for (int i = 1; i <= N; i++) {
            dp[i] = cost[i];
            if (degree[i] == 0)
                q.offer(i);
        }

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int next : adj[cur]) {
                dp[next] = Math.max(dp[next], cost[next] + dp[cur]);
                degree[next]--;

                if (degree[next] == 0)
                    q.offer(next);
            }
        }

        return dp[W];
    }


    static void settingGame() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        cost = new int[N + 1];
        degree = new int[N + 1];
        adj = new ArrayList[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            cost[i] = Integer.parseInt(st.nextToken());
            adj[i] = new ArrayList<>();
        }

        while (K-- > 0) {
            st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken());
            int Y = Integer.parseInt(st.nextToken());

            adj[X].add(Y);
            degree[Y]++;
        }

        W = Integer.parseInt(br.readLine());
    }
}
