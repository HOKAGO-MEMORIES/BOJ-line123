import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        System.out.println(solve(N, K, arr));
    }

    static long solve(int N, int K, int[] arr) {
        long ans = 0;
        int cnt = 1;

        Queue<int[]> q = new ArrayDeque<>();
        Set<Integer> visited = new HashSet<>();
        for (int n : arr) {
            visited.add(n);
            q.offer(new int[]{n, 0});
        }

        while (!q.isEmpty() && K > 0) {
            int[] cur = q.poll();
            int loc = cur[0];
            int dis = cur[1];

            int[] dx = {-1, 1};
            for (int dir : dx) {
                int next = loc + dir;

                if (!visited.contains(next)) {
                    q.offer(new int[]{next, dis + 1});
                    visited.add(next);
                    ans += (dis + 1);
                    K--;
                }

                if (K == 0) break;
            }
        }
        
        return ans;
    }

}
