import java.io.*;
import java.util.*;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        solve(N);

        System.out.println(sb);
    }

    static void solve(int N) {
        if (N % 10 != 0) {
            sb.append(-1);
            return;
        }

        int[] arr = {300, 60, 10};
        for (int num : arr) {
            sb.append(N / num).append(" ");
            N %= num;
        }
    }
}
