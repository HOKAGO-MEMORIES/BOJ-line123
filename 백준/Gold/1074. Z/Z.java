import java.io.*;
import java.util.*;

public class Main {

    static int ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        N = (int)Math.pow(2, N);
        solve(r, c, N);

        System.out.println(ans);
    }

    static void solve(int r, int c, int N) {
        if (N == 1)
            return;

        int half = N / 2;

        if (r < half && c < half) {
            solve(r, c, half);
        } else if (r < half) {
            ans += half * half;
            solve(r, c - half, half);
        } else if (c < half) {
            ans += half * half * 2;
            solve(r - half, c, half);
        } else {
            ans += half * half * 3;
            solve(r - half, c - half, half);
        }
    }

}
