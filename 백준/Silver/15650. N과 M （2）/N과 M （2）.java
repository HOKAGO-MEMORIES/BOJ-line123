import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[] nums;
    static boolean[] visited;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visited = new boolean[N + 1];
        nums = new int[M + 1];

        solve(1);

        System.out.println(sb);
    }

    static void solve(int cnt) {
        if (cnt == M + 1) {
            for (int i = 1; i <= M; i++)
                sb.append(nums[i]).append(" ");
            sb.append('\n');
            return;
        }


        for (int i = 1 ; i <= N; i++) {
            if (!visited[i] && nums[cnt - 1] < i) {
                visited[i] = true;
                nums[cnt] = i;
                solve(cnt + 1);
                visited[i] = false;
            }
        }
    }
}
