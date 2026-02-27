import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            String ans = solve(N, K);
            sb.append(ans).append('\n');
        }

        System.out.println(sb);
    }

    static String solve(int N, int K) {
        if (N == 1)
            if (K == 1) return "1";
            else return "-1";

        if (K != 2) return "-1";

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < N; i++) {
            if (i == N - 1) ans.append(1);
            else ans.append((i + K)).append(" ");
        }

        return ans.toString();
    }
}
