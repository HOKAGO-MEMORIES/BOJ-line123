import java.io.*;
import java.util.*;

public class Main {

    private static long[] arr;
    private static int N;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        arr = new long[N];
        for (int i = 0; i < N; i++)
            arr[i] = Long.parseLong(st.nextToken());

        solve();

        System.out.println(sb);
    }

    private static void solve() {
        int ansLeft = 0;
        int ansRight = 0;
        long ansValue = Long.MAX_VALUE;

        int left = 0;
        int right = N - 1;

        while (right > left) {
            long sum = arr[left] + arr[right];
            long value = Math.abs(sum);

            if (value < ansValue) {
                ansLeft = left;
                ansRight = right;
                ansValue = value;
            }

            if (sum < 0)
                left++;
            else
                right--;
        }

        sb.append(arr[ansLeft]).append(" ").append(arr[ansRight]);
    }

}
