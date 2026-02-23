import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[][] graph;
    static int[] leaf;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        graph = new int[N + 1][2];
        leaf = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int U = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());

            graph[i][0] = U;
            graph[i][1] = V;
        }

        long K = Long.parseLong(br.readLine());
        int ans = dfs(1, K);
        System.out.println(ans);
    }

    static int dfs(int n, long K) {
        if (graph[n][0] == -1) {
            if (graph[n][1] == -1) return n;    // 자식 없음
            else return dfs(graph[n][1], K);    // 오른쪽 자식만 있음
        }
        else if (graph[n][1] == -1) return dfs(graph[n][0], K); // 왼쪽 자식만 있음
        else if (K % 2 == 1) return dfs(graph[n][0], (K + 1) / 2);  // 양쪽 자식 있음 - 좌측으로 (K 홀수)
        return dfs(graph[n][1], K / 2); // 양쪽 자식 있음 - 우측으로 (K 짝수)
    }
}
