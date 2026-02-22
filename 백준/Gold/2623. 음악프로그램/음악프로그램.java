import java.io.*;
import java.util.*;

public class Main {

    static int[] degree;
    static List<Integer>[] adj;
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
            int num = Integer.parseInt(st.nextToken());

            int[] arr = new int[num];
            for (int i = 0; i < num; i++)
                arr[i] = Integer.parseInt(st.nextToken());

            for (int i = 0; i < num - 1; i++) {
                adj[arr[i]].add(arr[i + 1]);
                degree[arr[i + 1]]++;
            }
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
            sb.append(cur).append('\n');

            for (int next : adj[cur])
                if (--degree[next] == 0)  q.offer(next);
        }

        for (int i = 1; i <= N; i++) {
            if (degree[i] > 0) {
                sb = new StringBuilder();
                sb.append(0);
                break;
            }
        }
    }
}
