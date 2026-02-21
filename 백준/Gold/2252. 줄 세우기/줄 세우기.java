import java.io.*;
import java.util.*;

public class Main {

    static List<Integer>[] adj;
    static int[] degree;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        degree = new int[N + 1];
        adj = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++)
            adj[i] = new ArrayList<>();

        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            adj[A].add(B);
            degree[B]++;
        }

        solve(N);
        System.out.println(sb);
    }

    static void solve(int N) {
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 1; i <= N; i++)
            if (degree[i] == 0) q.offer(i);

        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur).append(" ");

            for (int next : adj[cur])
                if (--degree[next] == 0)  q.offer(next);
        }
    }
}
