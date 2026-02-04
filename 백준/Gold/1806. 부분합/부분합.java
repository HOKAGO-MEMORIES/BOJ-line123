import java.io.*;
import java.util.*;

public class Main {

    private static int N, S;
    private static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        arr = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            arr[i] = arr[i - 1] + Integer.parseInt(st.nextToken());

        System.out.println(solve());
    }

    private static int solve() {
        int left = 0;
        int right = 1;
        int ans = Integer.MAX_VALUE;

        while (right <= N) {
            int sum = arr[right] - arr[left];

            if (sum >= S) {
                ans = Math.min(ans, right - left);
                left++;
            }
            else {
                right++;
            }
        }

        return (ans == Integer.MAX_VALUE) ? 0 : ans;
    }
}
