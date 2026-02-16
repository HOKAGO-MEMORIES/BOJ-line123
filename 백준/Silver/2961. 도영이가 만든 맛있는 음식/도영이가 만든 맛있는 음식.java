import java.io.*;
import java.util.*;

public class Main {

    static long ans = Long.MAX_VALUE;
    static int N;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        arr = new int[N][2];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        solve(0, 1, 0);

        System.out.println(ans);
    }

    static void solve(int cnt, long S, long B) {
        if (cnt == N) {
            if (S != 0 && B != 0)
                ans = Math.min(ans, Math.abs(B - S));
            return;
        }

        solve(cnt + 1, S, B);
        solve(cnt + 1, S * arr[cnt][0], B + arr[cnt][1]);
    }
}
