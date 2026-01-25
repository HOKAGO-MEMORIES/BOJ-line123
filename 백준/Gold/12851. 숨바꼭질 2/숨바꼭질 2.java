import java.util.*;
import java.io.*;

public class Main {

    static int cnt = 0;
    static int minTime = Integer.MAX_VALUE;
    static int[] time = new int[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        solve(N, K);
        System.out.println(minTime);
        System.out.println(cnt);
    }

    private static void solve(int N, int K) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(N);

        while(!q.isEmpty()) {
            int now = q.pop();

            if (minTime < time[now]) return;

            if (now == K) {
                cnt++;
                minTime = time[now];
                continue;
            }

            int[] nextMove = {now + 1, now - 1, now * 2};
            for (int next : nextMove) {
                if (next < 0 || next > 100000) continue;

                if (time[next] == 0 || time[next] == time[now] + 1) {
                    time[next] = time[now] + 1;
                    q.add(next);
                }
            }

        }
    }
}
