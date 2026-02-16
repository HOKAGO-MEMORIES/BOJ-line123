import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int ans = solve(N);
        System.out.println(ans);
    }

    static int solve(int N) {
        int cnt = 0;
        while (N > 0) {
            if (N % 5 == 0) {
                cnt += N / 5;
                return cnt;
            }

            N -= 3;
            cnt++;
        }

        if (N != 0)
            return -1;

        return cnt;
    }
}
